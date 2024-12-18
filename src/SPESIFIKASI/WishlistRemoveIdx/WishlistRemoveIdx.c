#include <stdio.h>
#include "WishlistRemoveIdx.h"

void WishlistRemoveIdx(Linkedlist *L, int i) {
    if (Count(*L) == 0) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }
    else if (i > Count(*L) || i < 1) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", i);
        return;
    }
    else {
        addr_listdp P = First(*L);
        int idx = 1;

        while (idx < i) {
            P = Next(P);
            idx++;
        }
/*--------------Kata yang sama berada diawal List--------------*/
        if (P == First(*L)) {
            First(*L) = Next(P);
            if (First(*L) != NIL) {
                Prev(First(*L)) = NIL;
            }
        } 
/*--------------Kata yang sama berada ditengah List--------------*/      
        else if (P == Last(*L)) {
            Last(*L) = Prev(P);
            if (Last(*L) != NIL) {
                Next(Last(*L)) = NIL;
            }
        } 
/*--------------Kata yang sama berada diakhir List--------------*/
        else {
            Prev(Next(P)) = Prev(P);
            Next(Prev(P)) = Next(P);
        }

        DealokasiWishList(P);
        Count(*L)--;
        printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", i);
    
    }
}
