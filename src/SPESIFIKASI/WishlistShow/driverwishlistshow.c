#include "wishlistshow.h"

#include <stdio.h>
#include "wishlistshow.h"

int main() {
    Linkedlist wishlist;
    CreateEmptyWishlist(&wishlist);

    Barang item1 = {"Ayam Geprek Bakar Crispy Besthal"};
    Barang item2 = {"Ayam Mangut Besthal"};
    Barang item3 = {"Karaage Don"};
    Barang item4 = {"Torikatsu Don"};

    // Menambahkan barang ke wishlist
    AddLastWishlist(&wishlist, item1);
    AddLastWishlist(&wishlist, item2);
    AddLastWishlist(&wishlist, item3);
    AddLastWishlist(&wishlist, item4);

    // Menampilkan isi wishlist
    wishlistShow(&wishlist);

    return 0;
}