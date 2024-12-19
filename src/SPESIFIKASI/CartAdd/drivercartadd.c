#include <stdio.h>
#include "cartadd.h"

int main() {
    // Inisialisasi store
    Barang store[] = {
        {"AK 47", 10000},
        {"Bubble Blaster", 5000},
        {"Lalabu", 3000}
    };
    int storeCount = sizeof(store) / sizeof(store[0]);

    // Inisialisasi list user
    List userList = MakeList();
    User newUser;
    CopyString(newUser.name, "Purry");
    newUser.money = 100000;
    CreateEmptyKeranjang(&newUser.keranjang);
    InsertFirstList(&userList, newUser);

    printf("Masukkan perintah (contoh: CART ADD AK 47 10):\n");
    STARTWORD();

    // Parsing perintah awal
    if (!IsWordEqual(currentWord, StringToWord("CART"))) {
        printf("Perintah tidak valid. Gunakan CART ADD.\n");
        return 0;
    }

    ADVWORDNotIgnore();

    if (!IsWordEqual(currentWord, StringToWord("ADD"))) {
        printf("Perintah tidak valid. Gunakan CART ADD.\n");
        return 0;
    }

    // Panggil fungsi CartAdd
    CartAdd(&userList, 0, store, storeCount);

    // Tampilkan keranjang setelah operasi
    printf("\nIsi Keranjang:\n");
    TampilkanKeranjang(userList.A[0].keranjang);

    return 0;
}
