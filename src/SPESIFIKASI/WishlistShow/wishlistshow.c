#include "wishlistshow.h"

void wishlistShow(Wishlist *wishlist) {
    if (wishlist->count == 0) {
        printf("Wishlist kamu kosong!\n");
    } else {
        printf("Berikut adalah isi wishlist-mu:\n");
        for (size_t i = 0; i < wishlist->count; i++) {
            printf("%zu %s\n", i + 1, wishlist->items[i].name);
        }
    }
}