#include <stdio.h>
#include "cartadd.h"

void CartAdd(List *userList, IdxType currentIndex, Barang *store, int storeCount) {
    Barang currentBarang;
    int jumlah;
    User *currentUser = &userList->A[currentIndex];

    ADVWORDNotIgnore();  // Pindah ke kata pertama setelah "ADD"

    Word words[100]; // Menyimpan kata dalam bentuk array
    int wordCount = 0;

    // Simpan seluruh kata
    while (!endWord) {
        words[wordCount] = currentWord;
        wordCount++;
        ADVWORDNotIgnore();
    }

    if (wordCount < 2) {
        printf("Format command tidak valid!\n");
        return;
    }

    // Inisialisasi nama barang sebagai Word kosong
    Word namaBarang;
    ResetWord(&namaBarang);

    // Gabungkan semua kata kecuali kata terakhir untuk nama barang
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < words[i].Length; j++) {
            namaBarang.TabWord[namaBarang.Length++] = words[i].TabWord[j];
        }
        // Tambahkan spasi kecuali untuk kata terakhir
        if (i < wordCount - 2) {
            namaBarang.TabWord[namaBarang.Length++] = ' ';
        }
    }

    // Kuantitas diambil dari kata terakhir input
    jumlah = WordToInt(words[wordCount - 1]);

    // Debugging: Mengecek nama barang yang telah dibentuk
    printf("DEBUG: Constructed name: ");
    PrintWord(namaBarang);
    printf("\n");

    // Pencarian barang di store menggunakan Word
    int found = 0;
    for (int i = 0; i < storeCount; i++) {
        Word storeItemName = StringToWord(store[i].name);
        if (IsWordEqual(namaBarang, storeItemName)) {
            currentBarang.price = store[i].price;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Barang tidak ditemukan di toko!\n");
        return;
    }

    // Salin nama barang ke currentBarang.name
    CopyWordToCharArray(namaBarang, currentBarang.name);

    // Tambahkan barang ke keranjang
    if (IsItemInKeranjang(currentUser->keranjang, currentBarang)) {
        int existingQuantity = GetItemQuantity(currentUser->keranjang, currentBarang);
        UpdateKeranjangItemQuantity(&(currentUser->keranjang), currentBarang, existingQuantity + jumlah);
    } else {
        if (IsKeranjangFull(currentUser->keranjang)) {
            printf("Keranjang penuh! Tidak bisa menambah barang.\n");
            return;
        }
        AddToKeranjang(&(currentUser->keranjang), currentBarang, jumlah);
    }

    printf("Berhasil menambahkan %d ", jumlah);
    PrintWord(namaBarang);
    printf(" ke keranjang belanja!\n");
}
