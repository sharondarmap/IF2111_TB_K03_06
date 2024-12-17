#include <stdio.h>
#include "save.h"

int main() {
    // Deklarasi variabel
    ArrayDin barangToko = MakeArrayDin();
    List userList = MakeList();

    // --- Menambahkan data barang ke toko ---
    printf("Menambahkan data barang ke toko...\n");
    Barang b1 = {"AK47", 100};
    Barang b2 = {"Lalabu", 200};
    Barang b3 = {"Meong", 500};

    InsertLast(&barangToko, b1);
    InsertLast(&barangToko, b2);
    InsertLast(&barangToko, b3);

    // --- Menambahkan data pengguna ---
    printf("Menambahkan data pengguna...\n");
    User u1, u2;

    // User 1
    u1.money = 1000;
    CopyString(u1.name, "user1");
    CopyString(u1.password, "password1");
    CreateEmptyStack(&u1.riwayat_pembelian);
    CreateEmptyWishlist(&u1.wishList);

    // Tambahkan riwayat pembelian user 1
    Barang r1 = {"AK47", 100};
    Barang r2 = {"Lalabu", 200};
    PushToStack(&u1.riwayat_pembelian, r1);
    PushToStack(&u1.riwayat_pembelian, r2);

    // Tambahkan wishlist user 1
    Barang w1 = {"Meong", 500};
    InsertLastWishlist(&u1.wishList, w1);

    // User 2
    u2.money = 500;
    CopyString(u2.name, "user2");
    CopyString(u2.password, "password2");
    CreateEmptyStack(&u2.riwayat_pembelian);
    CreateEmptyWishlist(&u2.wishList);

    // Tambahkan wishlist user 2
    Barang w2 = {"AK47", 100};
    InsertLastWishlist(&u2.wishList, w2);

    // Tambahkan user ke dalam list
    InsertLastList(&userList, u1);
    InsertLastList(&userList, u2);

    // --- Panggil fungsi Save ---
    char filename[100] = "output_save.txt";
    printf("Menyimpan data ke file '%s'...\n", filename);
    Save(&barangToko, &userList, filename);

    printf("Proses Save selesai. Silakan periksa file '%s'.\n", filename);

    // Dealokasi memori
    DeallocateArrayDin(&barangToko);
    return 0;
}
