#include <stdio.h>
#include "profile.h"

#include <stdio.h>
#include "profile.h"


void showProfile(User user) {
    printf(">> PROFILE\n");
    printf("Nama       : %s\n", user.name);
    printf("Saldo      : %d\n\n", user.money);
    
    // Menampilkan isi keranjang
    printf("Isi Keranjang:\n");
    if (IsKeranjangEmpty(user.keranjang)) {  
        printf("Keranjang kosong.\n");
    } else {
        TampilkanKeranjang(user.keranjang); 

    // Menampilkan wishlist
    printf("\nWishlist:\n");
    if (WishlistIsEmpty(user.wishList)) {  
        printf("Wishlist kosong.\n");
    } else {
        PrintWishlist(user.wishList); 
    }
}
}