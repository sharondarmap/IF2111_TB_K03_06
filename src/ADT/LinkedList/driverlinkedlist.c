#include "linkedlist.h"
#include <stdio.h>

//gcc driverlinkedlist.c linkedlist.c -o driverlinkedlist

#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

int main() {
    // Inisialisasi daftar barang
    Linkedlist wishList;
    CreateEmptyWishlist(&wishList);

    WishlistIsEmpty(wishList);

    return 0;
}