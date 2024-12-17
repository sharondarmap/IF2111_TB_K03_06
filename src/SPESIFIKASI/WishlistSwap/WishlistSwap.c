#include <stdio.h>
#include <stdlib.h>
#include "WishlistSwap.h"

void WishlistSwap(Linkedlist *wishlist, int i, int j) {
    if (wishlist->count == 0) {
        printf("Gagal menukar posisi barang, wishlist kosong!\n");
        return;
    } 
    else if (wishlist->count == 1) {
        printf("Gagal menukar posisi %s!\n// Hanya terdapat satu barang (%s) pada wishlist sehingga posisinya tidak dapat ditukar\n",
               wishlist->First->wish.name, wishlist->First->wish.name);
        return;
    } 
    else if (i < 1 || j < 1 || i > wishlist->count || j > wishlist->count) {
        printf("Gagal menukar barang, karena posisi tidak valid!\n");
        return;
    } 
    else if (i == j) {
        printf("Tidak ada perubahan barang, karena posisi kedua barang sama.\n");
        return;
    }
    else {
        addr_listdp nodeI = wishlist->First;
        addr_listdp nodeJ = wishlist->First;
        int idx = 1;
        while (nodeI != NIL && idx < i) {
            nodeI = nodeI->next;
            idx++;
        }
        idx = 1;
        while (nodeJ != NIL && idx < j) {
            nodeJ = nodeJ->next;
            idx++;
        }

        if (nodeI != NIL && nodeJ != NIL) {
            Barang temp = nodeI->wish;
            nodeI->wish = nodeJ->wish;
            nodeJ->wish = temp;
            printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n",
                nodeJ->wish.name, nodeI->wish.name);
        }
    }

}
