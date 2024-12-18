#include "wishlistclear.h"
#include <stdio.h>

void WishlistClear(Linkedlist *wishList) {
    addr_listdp current = First(*wishList);
    addr_listdp temp;

    while (current != NIL) {
        temp = current;
        current = Next(current);
        DealokasiWishList(temp);
    }

    CreateEmptyWishlist(wishList);

    printf("Wishlist telah dikosongkan.\n");
}