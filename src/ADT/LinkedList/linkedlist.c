#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Ini nanti di main dihapus aja
int CompareStrings(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

void CopyString(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
// sampe sini bole diapus si nanti

addr_listdp AlokasiWishList(Barang X)
{
    addr_listdp P = (addr_listdp)malloc(sizeof(ElmtList));
    if (P != NIL)
    {
        // Deep copy the Barang
        CopyString(Wish(P).name, X.name);
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