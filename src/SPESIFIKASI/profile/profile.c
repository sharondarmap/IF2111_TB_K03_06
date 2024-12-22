#include <stdio.h>
#include "profile.h"


void showProfile(List userList, int currentIndex) {
    User loggedInUser = GetList(userList, currentIndex);

    printf("Nama       : %s\n", loggedInUser.name);
    printf("Password   : %s\n", loggedInUser.password);
    printf("Saldo      : %d\n\n", loggedInUser.money);
    
    // Menampilkan isi keranjang
    printf("Isi Keranjang:\n");
    if (IsKeranjangEmpty(loggedInUser.keranjang)) {  
        printf("Keranjang kosong.\n");
    } else {
        TampilkanKeranjang(loggedInUser.keranjang); 
    }
    // Menampilkan wishlist
    printf("\nWishlist:\n");
    if (WishlistIsEmpty(loggedInUser.wishList)) {  
        printf("Wishlist kosong.\n");
    } else {
        PrintWishlist(loggedInUser.wishList); 
    }
}