#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void CopyStringLink(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

addr_listdp AlokasiWishList(Barang X)
{
    addr_listdp P = (addr_listdp)malloc(sizeof(ElmtList));
    if (P != NIL)
    {
        // Deep copy the Barang
        CopyStringLink(Wish(P).name, X.name);
        Wish(P).price = X.price;
        Next(P) = NIL;
        Prev(P) = NIL;
    }
    return P;
}

/* Memory Deallocation */
void DealokasiWishList(addr_listdp P)
{
    free(P);
}

/* Create Empty Wishlist */
void CreateEmptyWishlist(Linkedlist *L)
{
    First(*L) = NIL;
    Last(*L) = NIL;
    Count(*L) = 0;
}

boolean WishlistIsEmpty(Linkedlist L)
{
    return First(L) == NIL;
}

void PrintWishlist(Linkedlist wishList) {
    addr_listdp current = First(wishList);
    int index = 1;

    if (WishlistIsEmpty(wishList)) {
        printf("  Wishlist kosong.\n");
        return;
    }

    while (current != NIL) {
        printf("    %d. %s\n", index++, Wish(current).name);
        current = Next(current);
    }
}


void InsertLastWishlist(Linkedlist *wishList, Barang item) {
    addr_listdp newNode = AlokasiWishList(item);
    if (newNode == NIL) {
        printf("ERROR: Gagal mengalokasikan memori untuk wishlist.\n");
        return;
    }

    if (WishlistIsEmpty(*wishList)) {
        First(*wishList) = newNode;
        Last(*wishList) = newNode;
        // printf("[DEBUG] Wishlist kosong. Elemen pertama '%s' ditambahkan di alamat %p\n", item.name, (void *)newNode);
    } else {
        Next(Last(*wishList)) = newNode;
        Prev(newNode) = Last(*wishList);
        Last(*wishList) = newNode;
        // printf("[DEBUG] Elemen '%s' ditambahkan di akhir wishlist di alamat %p\n", item.name, (void *)newNode);
    }
    Count(*wishList)++;
}