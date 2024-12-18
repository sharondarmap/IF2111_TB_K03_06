#include <stdio.h>
#include <stdlib.h>
#include "WishlistRemove.h"

void WishlistRemove(Linkedlist *L, Word inputName) {
    if (WishlistIsEmpty(*L)) {
        printf("Wishlist kosong! Tidak ada barang yang dapat dihapus.\n");
        return;
    }
    else {
        addr_listdp P = First(*L);
        boolean found = false;

        while (P != NIL) {
            Word barangName = StringToWord(Wish(P).name);
            if (IsWordEqual(barangName, inputName)) {
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
                found = true;
                printf("%s berhasil dihapus dari WISHLIST!\n", WordToString(inputName));
                break;
            }
            P = Next(P);
        }

        if (!found) {
            printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", WordToString(inputName));
        }
    }
}
