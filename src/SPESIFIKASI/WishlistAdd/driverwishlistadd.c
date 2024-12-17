#include <stdio.h>
#include "wishlistadd.h"

int main() {
    // Daftar barang toko (contoh data)
    Barang barangToko[3] = {
        {"AK47", 100},
        {"Lalabu", 50},
        {"Meong", 500}
    };

    // Inisialisasi user dan wishlist
    User user;
    CreateEmptyWishlist(&user.wishList);

    int jumlahBarangToko = 3;
    int pilihan;

    do {
        printf("\n=== DRIVER WISHLIST ADD ===\n");
        printf("1. Tampilkan Wishlist\n");
        printf("2. Tambahkan Barang ke Wishlist\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");
        
        // Membaca pilihan menggunakan mesin kata
        STARTWORD();
        pilihan = WordToInt(currentWord);

        switch (pilihan) {
            case 1:
                if (WishlistIsEmpty(user.wishList)) {
                    printf("Wishlist kosong.\n");
                } else {
                    printf("Isi Wishlist:\n");
                    addr_listdp current = First(user.wishList);
                    int i = 1;
                    while (current != NIL) {
                        printf("%d. %s (Rp %d)\n", i, Wish(current).name, Wish(current).price);
                        current = Next(current);
                        i++;
                    }
                }
                break;

            case 2:
                printf("\nDaftar barang di toko:\n");
                for (int i = 0; i < jumlahBarangToko; i++) {
                    printf("%d. %s (Rp %d)\n", i + 1, barangToko[i].name, barangToko[i].price);
                }
                WishlistAdd(&user, barangToko, jumlahBarangToko);
                break;

            case 3:
                printf("Keluar dari driver.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 3);

    return 0;
}
