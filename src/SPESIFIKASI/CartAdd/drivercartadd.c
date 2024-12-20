#include <stdio.h>
#include "cartadd.h"

// int main() {
//     // Inisialisasi store
//     Barang store[] = {
//         {"AK 47", 10000},
//         {"Bubble Blaster", 5000},
//         {"Lalabu", 3000}
//     };
//     int storeCount = sizeof(store) / sizeof(store[0]);

//     // Inisialisasi list user
//     List userList = MakeList();
//     User newUser;
//     CopyString(newUser.name, "Purry");
//     newUser.money = 100000;
//     CreateEmptyKeranjang(&newUser.keranjang);
//     InsertFirstList(&userList, newUser);

//     printf("Masukkan perintah (contoh: CART ADD AK 47 10):\n");
//     STARTWORD();

//     // Parsing perintah awal
//     if (!IsWordEqual(currentWord, StringToWord("CART"))) {
//         printf("Perintah tidak valid. Gunakan CART ADD.\n");
//         return 0;
//     }

//     ADVWORDNotIgnore();

//     if (!IsWordEqual(currentWord, StringToWord("ADD"))) {
//         printf("Perintah tidak valid. Gunakan CART ADD.\n");
//         return 0;
//     }

//     // Panggil fungsi CartAdd
//     CartAdd(&userList, 0, store, storeCount);

//     // Tampilkan keranjang setelah operasi
//     printf("\nIsi Keranjang:\n");
//     TampilkanKeranjang(userList.A[0].keranjang);

//     return 0;
// }

int main() {
    // Inisialisasi barangList
    ArrayDin barangList = MakeArrayDin();

    // Tambahkan barang ke barangList
    Barang barang1 = {"AK47", 100};
    Barang barang2 = {"Mouse", 50};
    Barang barang3 = {"Keyboard", 75};

    InsertLast(&barangList, barang1);
    InsertLast(&barangList, barang2);
    InsertLast(&barangList, barang3);

    // Debug: Tampilkan barang di barangList
    printf("Daftar Barang di Toko:\n");
    for (int i = 0; i < barangList.Neff; i++) {
        printf("- %s: %d\n", barangList.A[i].name, barangList.A[i].price);
    }

    // Inisialisasi userList
    List userList = MakeList();
    User user = {"JohnDoe", "password123", 500};

    // Tambahkan user ke userList
    InsertLastList(&userList, user);

    // Simulasi login
    IdxType currentIndex = 0; // Pengguna pertama dalam daftar

    // Debug: Tampilkan informasi pengguna sebelum menambahkan barang ke keranjang
    printf("\nProfil Pengguna:\n");
    printf("Nama: %s\n", userList.A[currentIndex].name);
    printf("Saldo: %d\n", userList.A[currentIndex].money);

    // Simulasi input untuk CartAdd
    printf("\nMasukkan input untuk CartAdd (contoh: CART ADD AK47 2):\n");
    STARTWORD(); // Memulai membaca input
    ADVWORDNotIgnore(); // Abaikan "CART"
    ADVWORDNotIgnore(); // Abaikan "ADD"
    // Panggil fungsi CartAdd
    CartAdd(&userList, currentIndex, barangList);

    // Debug: Tampilkan isi keranjang setelah penambahan
    printf("\nIsi Keranjang Pengguna:\n");
    TampilkanKeranjang(userList.A[currentIndex].keranjang);

    return 0;
}
