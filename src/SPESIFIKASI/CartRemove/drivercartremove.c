#include <stdio.h>
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/Kustom/user.h"
#include "cartremove.h"

int main() {
    // Create and initialize the list
    List L1 = MakeList();
    printf("Successfully created the list.\n");

    Map Cart;
    CreateEmptyKeranjang(&Cart);

    Barang barang1 = {"Laptop", 10000};
    Barang barang2 = {"Mouse 3000", 5000};
    Barang barang3 = {"Ayam Goreng Crisbar", 7500};
    Barang barang4 = {"Monitor", 15000};

    AddToKeranjang(&Cart, barang1, 2);
    AddToKeranjang(&Cart, barang2, 3);
    AddToKeranjang(&Cart, barang3, 1);

    printf("Items added to the cart.\n");

    User u3;
    CopyString(u3.name, "Sharon");
    CopyString(u3.password, "mypassword");
    u3.money = 750;
    u3.keranjang = Cart;

    printf("User created and cart assigned.\n");

    InsertFirstList(&L1, u3);

    printf("User added to the list.\n");

    printf("Cart before removal:\n");
    TampilkanKeranjang(L1.A[0].keranjang);

    printf("Enter command (e.g., 'CART REMOVE Laptop 1'):\n");
    STARTWORD();

    if (IsWordEqual(currentWord, StringToWord("CART"))) {
        ADVWORDNotIgnore();
        if (IsWordEqual(currentWord, StringToWord("REMOVE"))) {

            CartRemove(&L1, 0);
            TampilkanKeranjang(L1.A[0].keranjang);
 
        } else {
            printf("Invalid sub-command. Only 'REMOVE' is supported.\n");
        }
    } else {
        printf("Invalid command. Only 'CART' is supported.\n");
    }

    return 0;
}
