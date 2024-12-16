#include "linkedlist.h"
#include <stdio.h>

int main() {
    Linkedlist wishList;

    CreateEmptyWishlist(&wishList);

    WishlistIsEmpty(wishList);

    return 0;
}