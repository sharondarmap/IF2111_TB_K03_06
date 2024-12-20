#include <stdio.h>
#include "profile.h"

/*
 * Driver untuk menguji showProfile dan operasi wishlist serta keranjang
 */
int main() {
    // Inisialisasi List pengguna
    List userList = MakeList();
    int currentIndex = -1; // Menandakan tidak ada pengguna yang login

    // Tambahkan pengguna ke List
    User user1 = {"admin", "admin123", 10000};
    User user2 = {"user", "user123", 5000};
    InsertLastList(&userList, user1);
    InsertLastList(&userList, user2);

    // Tampilkan daftar pengguna
    printf("Daftar Pengguna:\n");
    PrintList(userList);

    // Simulasi login dengan memilih indeks pengguna
    printf("\nMasukkan indeks pengguna untuk login (0 atau 1): ");
    scanf("%d", &currentIndex);
    // Membuat user dan menginisialisasi data
    User loggedInUser = GetList(userList, currentIndex);

    // Inisialisasi wishlist dan keranjang
    CreateEmptyKeranjang(&loggedInUser.keranjang);       // Inisialisasi keranjang
    CreateEmptyWishlist(&loggedInUser.wishList);          // Inisialisasi wishlist (Linkedlist)

    // Menambahkan barang ke keranjang
    Barang item1 = {"AK47", 200};
    Barang item2 = {"Platypus Laser", 500};
    AddToKeranjang(&loggedInUser.keranjang, item1, 2);    // Menambahkan 2 AK47 ke keranjang
    AddToKeranjang(&loggedInUser.keranjang, item2, 1);    // Menambahkan 1 Platypus Laser ke keranjang

    // Menambahkan barang ke wishlist
    InsertLastWishlist(&loggedInUser.wishList, item1);  // Menambahkan AK47 ke wishlist
    InsertLastWishlist(&loggedInUser.wishList, item2);  // Menambahkan Platypus Laser ke wishlist

    // Menampilkan profil pengguna
    showProfile(userList, currentIndex);

    return 0;
}