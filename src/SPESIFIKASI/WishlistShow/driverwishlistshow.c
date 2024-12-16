#include "wishlistshow.h"

int main() {
    int i;
    Wishlist wishlist;

    // Inisialisasi wishlist dengan beberapa item
    wishlist.capacity = 5;
    wishlist.count = 4;
    wishlist.items = (WishlistItem *)malloc(wishlist.capacity * sizeof(WishlistItem));

    strcpy(wishlist.items[0].name, "Ayam Geprek Bakar Crispy Besthal");
    strcpy(wishlist.items[1].name, "Ayam Mangut Besthal");
    strcpy(wishlist.items[2].name, "Karaage Don");
    strcpy(wishlist.items[3].name, "Torikatsu Don");

    printf("Masukkan pilihan (1 untuk tampilkan wishlist, 2 untuk kosongkan wishlist): ");
    scanf("%d", &i); // Perbaiki dengan menggunakan '&' untuk alamat variabel

    if (i == 1) { // 
        // Tampilkan isi wishlist
        wishlistShow(&wishlist);
    } else if (i == 2) { 
        // Kosongkan wishlist
        wishlist.count = 0;
        wishlistShow(&wishlist);

        // Bebaskan memori yang dialokasikan
        free(wishlist.items);
    } else {
        printf("Pilihan tidak valid.\n");
    }

    return 0;
}