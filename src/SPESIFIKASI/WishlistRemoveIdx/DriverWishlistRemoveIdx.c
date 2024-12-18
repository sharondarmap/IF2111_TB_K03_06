
#include <stdio.h>
#include "WishlistRemoveIdx.h"
#include "WishlistRemoveIdx.c"

int main() {
    Linkedlist wishlist;
    CreateEmptyWishlist(&wishlist);

/*-------Contoh barang dalam wishlist-------*/
    Barang dataBarang[5] = {
        {"Ayam Geprek Bakar Crispy Besthal", 234000},
        {"Ayam Mangut Besthal", 12300},
        {"Ambalabu", 180200},
        {"Lalabu", 176900},
        {"AK47", 321000}
    };

    for (int i = 0; i < 5; i++) {
        addr_listdp newNode = AlokasiWishList(dataBarang[i]);
        if (newNode != NIL) {
            if (WishlistIsEmpty(wishlist)) {
                First(wishlist) = Last(wishlist) = newNode;
            } else {
                Next(Last(wishlist)) = newNode;
                Prev(newNode) = Last(wishlist);
                Last(wishlist) = newNode;
            }
            Count(wishlist)++;
        }
    }

/*-------Menampilkan barang dalam wishlist sebelum update-------*/
    printf("=== WISHLIST ===\n");
    addr_listdp P = First(wishlist);
    int idx = 1; 
    while (P != NIL) {
        printf("%d. %s - %d\n", idx++, Wish(P).name, Wish(P).price);
        P = Next(P);
    }
    
    STARTWORD();

    if (IsWordEqual(currentWord, StringToWord("WISHLIST"))) {
        ADVWORD();
        if (IsWordEqual(currentWord, StringToWord("REMOVE"))) {
            ADVWORD();
            int idxToRemove = WordToInt(currentWord);
            WishlistRemoveIdx(&wishlist, idxToRemove);
        } 
        else {
            printf("Penghapusan barang WISHLIST gagal dilakukan, command tidak valid!\n");
        }
    } else {
        printf("Penghapusan barang WISHLIST gagal dilakukan, command tidak valid!\n");
    }

/*-------Menampilkan barang dalam wishlist setelah update-------*/
    if (Count(wishlist) > 0) {
        printf("\n=== WISHLIST UPDATE ===\n");
        P = First(wishlist);
        idx = 1;
        while (P != NIL) {
            printf("%d. %s - %d\n", idx++, Wish(P).name, Wish(P).price);
            P = Next(P);
        }
    }

    P = First(wishlist);
    while (P != NIL) {
        addr_listdp temp = P;
        P = Next(P);
        DealokasiWishList(temp);
    }
    return 0;
}
