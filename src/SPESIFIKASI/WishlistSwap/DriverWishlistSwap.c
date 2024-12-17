#include <stdio.h>
#include <stdlib.h>
#include "WishlistSwap.h"
#include "WishlistSwap.c"

int main() {

/*-------Contoh barang dalam wishlist-------*/
    Barang dataBarang[5] = {
        {"Ayam Geprek Bakar Crispy Besthal", 234000},
        {"Ayam Mangut Besthal", 12300},
        {"Ambalabu", 180200},
        {"Lalabu", 176900},
        {"AK47", 321000}
    };

    Linkedlist wishlist;
    CreateEmptyWishlist(&wishlist); 

    for (int i = 0; i < 5; i++) {
        addr_listdp newNode = AlokasiWishList(dataBarang[i]);
        if (wishlist.First == NIL) {
            wishlist.First = newNode;
            wishlist.Last = newNode;
        } else {
            wishlist.Last->next = newNode;
            newNode->prev = wishlist.Last;
            wishlist.Last = newNode;
        }
        wishlist.count++;
    }

/*-------Menampilkan barang dalam wishlist sebelum update-------*/
    printf("\n=== WISHLIST ===\n");
    addr_listdp current = wishlist.First;
    int idx = 1;
    while (current != NIL) {
        printf("%d. %s - $%d\n", idx++, current->wish.name, current->wish.price);
        current = current->next;
    }

    printf("\nMasukkan perintah: ");
    STARTWORD();
    if (IsWordEqual(currentWord, StringToWord("WISHLIST"))) {
        ADVWORD();
        if (IsWordEqual(currentWord, StringToWord("SWAP"))) {
            ADVWORD();
            int i = WordToInt(currentWord);
            ADVWORD();
            int j = WordToInt(currentWord);
            WishlistSwap(&wishlist, i, j);
        } else {
            printf("Perintah tidak valid!\n");
        }
    } else {
        printf("Perintah tidak valid!\n");
    }

/*-------Menampilkan barang dalam wishlist setelah update-------*/
    printf("\n=== WISHLIST UPDATE ===\n");
    current = wishlist.First;
    idx = 1;
    while (current != NIL) {
        printf("%d. %s - $%d\n", idx++, current->wish.name, current->wish.price);
        current = current->next;
    }

    current = wishlist.First;
    while (current != NIL) {
        addr_listdp temp = current;
        current = current->next;
        DealokasiWishList(temp);
    }
    return 0;
}
