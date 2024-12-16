#include "wishlistclear.h"

void clearWishlist(Wishlist *wishlist)
{
if (wishlist == NULL || wishlist->items == NULL) {
    return;
}

wishlist->count = 0;

for (size_t i = 0; i < wishlist->capacity; i++) {
    wishlist->items[i].name[0] = '\0';  // Mengosongkan string
}

printf("Wishlist telah dikosongkan.\n");
}