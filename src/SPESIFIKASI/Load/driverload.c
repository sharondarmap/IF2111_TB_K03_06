#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "load.h"

int main() {
    // Variabel untuk menyimpan data barang dan pengguna
    ArrayDin daftarBarang;
    List userList;

    // Nama file konfigurasi
    char filename[] = "dummy_config.txt";

    // Memanggil fungsi Load
    Load(filename, &daftarBarang, &userList);

    // Ambil panjang userList
    int jumlahPengguna = LengthList(userList);

    // Menampilkan hasil untuk debugging
    printf("\n[HASIL LOAD BARANG]\n");
    PrintArrayDin(daftarBarang);

    printf("\n[HASIL LOAD PENGGUNA]\n");
    PrintList(userList);
    printf("\n");

    // Menampilkan riwayat pembelian untuk setiap pengguna
    for (int i = 0; i < jumlahPengguna; i++) {
        printf("Isi Riwayat Pembelian user ke-%d:\n", i+1);
        DisplayStack(userList.A[i].riwayat_pembelian);
        printf("\n");
    }
    printf("\n");

    // Menampilkan wishlist untuk setiap pengguna
    for (int i = 0; i < jumlahPengguna; i++) {
        printf("Isi wishlist user ke-%d:\n", i+1);
        PrintWishlist(userList.A[i].wishList);
        printf("\n");
    }


    // Dealokasi memori
    DeallocateArrayDin(&daftarBarang);

    return 0;
}