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