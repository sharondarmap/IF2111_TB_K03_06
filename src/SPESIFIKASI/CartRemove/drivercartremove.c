#include <stdio.h>
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/Kustom/user.h"
#include "cartremove.h"


int main() {
    List L1 = MakeList();
    printf("berhasil make\n");

    Map Cart;

    CreateEmptyKeranjang(&Cart);
    Barang barang1 = {"Laptop", 10000};
    Barang barang2 = {"Mouse", 5000};
    Barang barang3 = {"Keyboard", 7500};
    Barang barang4 = {"Monitor", 15000};

    AddToKeranjang(&Cart, barang1, 2);
    AddToKeranjang(&Cart, barang2, 3);
    AddToKeranjang(&Cart, barang3, 1);

    printf("berhasil add\n");


    User u3 = {"Sharon", "mypassword", 750};

    printf("berhasil copystring\n");

    u3.keranjang = Cart;

    int currentIndex = 0;

    printf("berhasil copy\n");

    L1[0] = u3;

    printf("berhasil insert\n");

    // Tampilkan keranjang sebelum remove
    printf("Keranjang sebelum remove:\n");
    TampilkanKeranjang(L1.A[0].keranjang);

    STARTWORD();
    if (IsWordEqual(currentWord, StringToWord("CART"))) {
        ADVWORD();
        if (IsWordEqual(currentWord, StringToWord("REMOVE"))) {
            // Ambil nama barang
            ADVWORD();
            Barang currentBarang;
            CopyString(currentBarang.name, WordToString(currentWord));

            // Ambil jumlah
            ADVWORD();
            int jumlah = WordToInt(currentWord);

            // Panggil fungsi CartRemove
            CartRemove(&L1, currentIndex, currentBarang, jumlah);

            // Tampilkan keranjang setelah remove
            printf("\nKeranjang setelah remove:\n");
            TampilkanKeranjang(L1.A[0].keranjang);
        }
    }

    return 0;
}