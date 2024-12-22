#include "wishlistshow.h"

void wishlistShow(Linkedlist *wishList) {
    if (WishlistIsEmpty(*wishList)) {
        printf("Wishlist kamu kosong!\n");
    } else {
        addr_listdp P = First(*wishList);
        int index = 1;
        printf("Berikut adalah isi wishlist-mu:\n");
        while (P != NIL) {
            printf("%d. %s\n", index, Wish(P).name);
            P = Next(P);
            index++;
        }
    }
}