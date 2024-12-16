#include <stdio.h>
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/Kustom/user.h"
#include "cartremove.h"

int main() {
    // Create and initialize the list
    List L1 = MakeList();
    printf("Successfully created the list.\n");

    // Create and initialize the cart (keranjang)
    Map Cart;
    CreateEmptyKeranjang(&Cart); // Ensure this function exists

    // Define some items to add to the cart
    Barang barang1 = {"Laptop", 10000};
    Barang barang2 = {"Mouse", 5000};
    Barang barang3 = {"Keyboard", 7500};
    Barang barang4 = {"Monitor", 15000};

    // Add items to the cart
    AddToKeranjang(&Cart, barang1, 2);
    AddToKeranjang(&Cart, barang2, 3);
    AddToKeranjang(&Cart, barang3, 1);

    printf("Items added to the cart.\n");

    // Create a user and associate the cart with them
    User u3;
    CopyString(u3.name, "Sharon");
    CopyString(u3.password, "mypassword");
    u3.money = 750;
    u3.keranjang = Cart;

    printf("User created and cart assigned.\n");

    // Insert the user into the list
    InsertFirstList(&L1, u3);

    printf("User added to the list.\n");

    // Display the cart before removal
    printf("Cart before removal:\n");
    TampilkanKeranjang(L1.A[0].keranjang); // Ensure this function is implemented

    // Use mesinkata to parse the input
    printf("Enter command (e.g., 'CART REMOVE Laptop 1'):\n");
    STARTWORD();

    if (IsWordEqual(currentWord, StringToWord("CART"))) {
        ADVWORD(); // Advance to next word
        if (IsWordEqual(currentWord, StringToWord("REMOVE"))) {
            // Declare currentBarang
            Barang currentBarang;

            // Parse item name
            ADVWORD();
            for (int i = 0; i < currentWord.Length && i < MAX_LEN - 1; i++) {
                currentBarang.name[i] = currentWord.TabWord[i];
            }
            currentBarang.name[currentWord.Length] = '\0'; // Null-terminate the string

            // Parse quantity
            ADVWORD();
            int jumlah = WordToInt(currentWord);

            // Call the CartRemove function
            CartRemove(&L1, 0, currentBarang, jumlah); // Ensure this function is implemented

            // Display the cart after removal
            printf("\nCart after removal:\n");
            TampilkanKeranjang(L1.A[0].keranjang);
        } else {
            printf("Invalid sub-command. Only 'REMOVE' is supported.\n");
        }
    } else {
        printf("Invalid command. Only 'CART' is supported.\n");
    }

    return 0;
}