#include "linkedlist.h"
#include <stdio.h>

//gcc driverlinkedlist.c linkedlist.c -o driverlinkedlist

#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

int main() {
    // Inisialisasi daftar barang
    Linkedlist wishList;
    CreateEmptyWishlist(&wishList);

    // Menambahkan beberapa barang ke wishlist
    Barang barang1 = {"Apel", 4};
    Barang barang2 = {"Jeruk", 5};
    Barang barang3 = {"Mangga", 6};

    InsertLastWishlist(&wishList, barang1);
    InsertLastWishlist(&wishList, barang2);
    InsertLastWishlist(&wishList, barang3);

    // Tampilkan daftar barang sebelum penghapusan
    printf("Daftar barang sebelum penghapusan:\n");
    PrintWishlist(wishList);
    printf("\n");

    // Input barang yang akan dihapus (misalnya, menghapus barang pertama)
    addr_listdp current = First(wishList);
    if (current != NIL) {
        First(wishList) = Next(current);
        if (First(wishList) != NIL) {
            Prev(First(wishList)) = NIL;
        } else {
            Last(wishList) = NIL;
        }
        DealokasiWishList(current);
        Count(wishList)--;
    }

    // Tampilkan daftar barang setelah penghapusan
    printf("Daftar barang setelah penghapusan:\n");
    PrintWishlist(wishList);
    printf("\n");

    // Dealokasi wishlist
    current = First(wishList);
    while (current != NIL) {
        addr_listdp temp = current;
        current = Next(current);
        DealokasiWishList(temp);
    }

    return 0;
}