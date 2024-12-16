#include <stdio.h>
#include "cartremove.h"

void CartRemove(List *userList, IdxType currentIndex, Barang currentBarang, int jumlah) {
    User *currentUser = &userList->A[currentIndex]; // mengambil user saat ini
    int itemQuantity = GetItemQuantity(currentUser->keranjang, currentBarang);

    if (IsItemInKeranjang(currentUser->keranjang, currentBarang)) {
        if (jumlah <= itemQuantity) {
            // Kurangi quantity
            if (jumlah == itemQuantity) {
                // Jika jumlah yang dihapus sama dengan quantity, hapus item
                RemoveFromKeranjang(&(currentUser->keranjang), currentBarang);
            } else {
                // Update quantity
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