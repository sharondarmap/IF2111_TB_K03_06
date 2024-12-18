#include <stdio.h>
#include "cartpay.h"

void CartPay(List *userList, IdxType idxUser) {
    User *currentUser = &userList->A[idxUser];
    Map usercart = currentUser->keranjang;

    if (currentUser->riwayat_pembelian.T == NULL) {
        CreateEmptyStack(&currentUser->riwayat_pembelian);
    }
    
    int totalHarga = HitungTotalHargaKeranjang(usercart);

    if (totalHarga == 0) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    printf("Kamu akan membeli barang-barang berikut:\n");

    // Menampilkan isi keranjang
    TampilkanKeranjang(usercart);

    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalHarga);

    STARTWORD();
    Word jawaban = currentWord;

    if (IsWordEqual(StringToWord("Ya"), jawaban)) {
        int saldo = currentUser->money;
        if (saldo >= totalHarga) {
            
            currentUser->money -= totalHarga;

            // Menentukan barang dengan total harga terbesar dan urutan leksikal terbesar
            Barang barangTerbesar = usercart.Elements[0].Key;
            int totalTerbesar = usercart.Elements[0].Quantity * usercart.Elements[0].Key.price;

            // Membandingkan barang berdasarkan total harga dan urutan leksikal
            for (int i = 1; i < usercart.Count; i++) {
                int totalItem = usercart.Elements[i].Quantity * usercart.Elements[i].Key.price;
                Word namaBarangWord = StringToWord(usercart.Elements[i].Key.name);
                Word namaTerbesarWord = StringToWord(barangTerbesar.name);

                // Jika total harga lebih besar atau total sama tetapi nama barang lebih besar leksikalnya
                if (totalItem > totalTerbesar || 
                    (totalItem == totalTerbesar && IsWordEqual(namaBarangWord, namaTerbesarWord) > 0)) {
                    totalTerbesar = totalItem;
                    barangTerbesar = usercart.Elements[i].Key;
                }
            }

            printf("Selamat, kamu telah membeli barang-barang tersebut!\n");

            // Tambahkan barang terbesar ke riwayat pembelian
            PushToStack(&currentUser->riwayat_pembelian, barangTerbesar);
            DisplayStack(currentUser->riwayat_pembelian); //cek

            // Kosongkan keranjang di userList
            CreateEmptyKeranjang(&currentUser->keranjang);

        } else {
            printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", saldo);
        }

    } else if (IsWordEqual(StringToWord("Tidak"), jawaban)) {
        printf("Pembelian dibatalkan.\n");
    } else {
        printf("Perintah tidak valid, pembelian dibatalkan.\n");
    }
}
