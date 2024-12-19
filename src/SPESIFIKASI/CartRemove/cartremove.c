#include <stdio.h>
#include "cartremove.h"

void CartRemove(List *userList, IdxType currentIndex) {
    Barang currentBarang;
    int jumlah;
    User *currentUser = &userList->A[currentIndex];
    int itemQuantity;

    ADVWORDNotIgnore();  // Move to first word after "REMOVE"
    
    Word words[100]; //menyimpan words dalam bentuk array
    int wordCount = 0;
    
    //Simpan seluruh word
    while (!endWord) {
        words[wordCount] = currentWord;
        wordCount++;
        ADVWORDNotIgnore();
    }
    
    if (wordCount < 2) {
        printf("Format command tidak valid!\n");
        return;
    }
    
    // Clear currentBarang.name
    for (int i = 0; i < MAX_LEN; i++) {
        currentBarang.name[i] = '\0';
    }
    
    int idx = 0;
    // Semua word ditambah kecuali word paling akhir
    for (int i = 0; i < wordCount - 1; i++) {
        // Append current word ke currentBarang.name
        for (int j = 0; j < words[i].Length && idx < MAX_LEN - 1; j++) {
            currentBarang.name[idx++] = words[i].TabWord[j];
        }
        
        // spasi kalau bukan kata terakhir
        if (i < wordCount - 2 && idx < MAX_LEN - 1) {
            currentBarang.name[idx++] = ' ';
        }
    }
    
    currentBarang.name[idx] = '\0';
    
    //quantity diambil dari last word inputan user (ubah kata jadi integer)
    jumlah = WordToInt(words[wordCount - 1]);

    // Debugging: mengecek currentBarang.name yang sudah dibentuk
    printf("DEBUG: Constructed name: '%s'\n", currentBarang.name);

    // Ambil quantity barang dengan currentBarang jika ada di keranjang
    itemQuantity = GetItemQuantity(currentUser->keranjang, currentBarang);

    if (IsItemInKeranjang(currentUser->keranjang, currentBarang)) {
        if (jumlah <= itemQuantity) {
            if (jumlah == itemQuantity) {
                RemoveFromKeranjang(&(currentUser->keranjang), currentBarang);
            } else {
                UpdateKeranjangItemQuantity(&(currentUser->keranjang), currentBarang, itemQuantity - jumlah);
            }
            printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", jumlah, currentBarang.name);
        } else {
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", itemQuantity, currentBarang.name);
        }
    } else {
        printf("Barang tidak ada di keranjang belanja!\n");
    }
}
