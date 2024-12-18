#include "wishlistclear.h"

#include "wishlistclear.h"
#include <stdio.h>

int main() {
    Linkedlist wishList;

    // Membuat wishlist kosong
    CreateEmptyWishlist(&wishList);

    // Menambahkan beberapa item ke wishlist
    Barang item1 = {"Earphone"};
    Barang item2 = {"Keyboard"};
    Barang item3 = {"Mouse"};

    InsertLastWishlist(&wishList, item1);
    InsertLastWishlist(&wishList, item2);
    InsertLastWishlist(&wishList, item3);

    // Menampilkan wishlist sebelum dikosongkan
    printf("Wishlist sebelum dikosongkan:\n");
    PrintWishlist(wishList);

    // Mengosongkan wishlist
    WishlistClear(&wishList);

    // Menampilkan wishlist setelah dikosongkan
    printf("Wishlist setelah dikosongkan:\n");
    PrintWishlist(wishList);

    return 0;
}