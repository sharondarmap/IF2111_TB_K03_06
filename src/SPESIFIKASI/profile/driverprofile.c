#include <stdio.h>
#include <string.h>  // Untuk strcpy
#include "profile.h"

/*
 * Driver untuk menguji showProfile dan operasi wishlist serta keranjang
 */
int main() {
    // Membuat user dan menginisialisasi data
    User loggedInUser;
    
    // Menginisialisasi data user
    strcpy(loggedInUser.name, "Purry");
    strcpy(loggedInUser.password, "meow123");
    loggedInUser.money = 2000;

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
    showProfile(loggedInUser);

    return 0;
}