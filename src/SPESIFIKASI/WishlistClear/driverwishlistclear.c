#include "wishlistclear.h"

int main() {
    // Membuat Wishlist dengan kapasitas 5
    Wishlist wishlist;
    wishlist.capacity = 5;
    wishlist.count = 3;
    wishlist.items = (WishlistItem *)malloc(wishlist.capacity * sizeof(WishlistItem));

    if (wishlist.items == NULL) {
        fprintf(stderr, "Gagal mengalokasikan memori untuk wishlist\n");
        return 1;
    }

    // Menambahkan beberapa item ke wishlist
    strcpy(wishlist.items[0].name, "Earphone");

    strcpy(wishlist.items[1].name, "Keyboard");

    strcpy(wishlist.items[2].name, "Mouse");

    // Menampilkan isi wishlist sebelum clear
    printf("Isi Wishlist sebelum clear:\n");
    for (size_t i = 0; i < wishlist.count; i++) {
        printf("Nama: %s\n", wishlist.items[i].name);
    }

    // Panggil fungsi clearWishlist
    clearWishlist(&wishlist);

    // Menampilkan isi wishlist setelah clear
    printf("\nIsi Wishlist setelah clear:\n");
    if (wishlist.items == NULL) {
        printf("Wishlist kosong.\n");
    } else {
        for (size_t i = 0; i < wishlist.count; i++) {
            printf("Nama: %s\n", wishlist.items[i].name);
        }
    }

    return 0;
}