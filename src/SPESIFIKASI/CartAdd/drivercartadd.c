#include <stdio.h>
#include "cartadd.h"

int main() {
    // Create and initialize the list
    List L1 = MakeList();
    printf("Successfully created the list.\n");

    // Create and initialize the cart (keranjang)
    Map Cart;
    CreateEmptyKeranjang(&Cart);

    // Define some items in the store
    Barang storeItems[] = {
        {"Laptop", 10000},
        {"Mouse", 5000},
        {"Keyboard", 7500},
        {"Monitor", 15000}
    };
    int numStoreItems = 4;

    // Add an item to the cart for testing the "already in cart" condition
    AddToKeranjang(&Cart, storeItems[1], 3); // Adding "Mouse" with quantity 3

    // Create a user and associate the cart with them
    User u1;
    CopyString(u1.name, "Sharon");
    CopyString(u1.password, "mypassword");
    u1.money = 750;
    u1.keranjang = Cart;

    printf("User created and cart assigned.\n");

    // Insert the user into the list
    InsertFirstList(&L1, u1);

    printf("User added to the list.\n");

    // Input for testing
    printf("Masukkan perintah (contoh: 'CART ADD Laptop 2'):\n");
    STARTWORD();

    if (IsWordEqual(currentWord, StringToWord("CART"))) {
        ADVWORD(); // Advance to next word
        if (IsWordEqual(currentWord, StringToWord("ADD"))) {
            // Parse item name
            ADVWORD();
            Barang currentBarang;
            CopyWordToCharArray(currentWord, currentBarang.name);

            // Find the item in the store
            int found = 0;
            for (int i = 0; i < numStoreItems; i++) {
                if (CompareStrings(storeItems[i].name, currentBarang.name)) {
                    currentBarang.price = storeItems[i].price;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Barang tidak ditemukan di toko.\n");
                return 0;
            }

            // Parse quantity
            ADVWORD();
            int jumlah = WordToInt(currentWord);

            printf("Nama barang: %s, Harga: %d, Kuantitas: %d\n", currentBarang.name, currentBarang.price, jumlah);

            // Check if the item is already in the cart
            if (IsItemInKeranjang(L1.A[0].keranjang, currentBarang)) {
                printf("Barang sudah ada di keranjang. Menambahkan jumlah...\n");
            } else {
                printf("Barang belum ada di keranjang. Menambahkan barang baru...\n");
            }

            // Call CartAdd function
            CartAdd(&L1, 0, currentBarang, jumlah);

            // Display the cart
            printf("\nIsi Keranjang:\n");
            TampilkanKeranjang(L1.A[0].keranjang);
        } else {
            printf("Sub-perintah tidak valid. Hanya 'ADD' yang didukung.\n");
        }
    } else {
        printf("Perintah tidak valid. Hanya 'CART' yang didukung.\n");
    }

    return 0;
}
