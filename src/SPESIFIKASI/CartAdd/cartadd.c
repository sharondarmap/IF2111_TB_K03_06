#include <stdio.h>
#include "cartadd.h"

void CartAdd(List *userList, IdxType currentIndex, Barang currentBarang, int jumlah) {
    User *currentUser = &userList->A[currentIndex]; // Ambil user aktif
   
    // Validasi jumlah barang
    if (jumlah <= 0) {
        printf("Jumlah barang yang ditambahkan harus lebih dari 0.\n");
        return;
    }
    // Validasi harga barang
    if (currentBarang.price <= 0) {
        printf("Harga barang tidak valid! Tidak dapat menambahkan ke keranjang.\n");
        return;
    }
    
    // Periksa apakah barang sudah ada di keranjang
    int itemQuantity = GetItemQuantity(currentUser->keranjang, currentBarang);
    if (IsItemInKeranjang(currentUser->keranjang, currentBarang)) {
        // Jika barang sudah ada, perbarui kuantitasnya
        UpdateKeranjangItemQuantity(&(currentUser->keranjang), currentBarang, itemQuantity + jumlah);
    } else {
        // Jika barang belum ada, tambahkan ke keranjang
        if (IsKeranjangFull(currentUser->keranjang)) {
            printf("Keranjang penuh! Tidak bisa menambah barang.\n");
            return;
        }
        AddToKeranjang(&(currentUser->keranjang), currentBarang, jumlah);
    }

    printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", jumlah, currentBarang.name);
}
