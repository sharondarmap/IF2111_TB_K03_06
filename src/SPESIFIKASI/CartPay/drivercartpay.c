#include <stdio.h>
#include "cartpay.h"

// Fungsi untuk menginisialisasi user dan keranjang mereka
void InitializeDummyUser(List *userList) {
    // Inisialisasi list user
    *userList = MakeList();

    // Membuat user dummy pertama
    User user1;
    CopyString(user1.name, "Alice");
    user1.money = 50000;  // Saldo awal

    // Membuat keranjang untuk user1
    CreateEmptyKeranjang(&user1.keranjang);

    // Menambahkan barang ke keranjang user1
    Barang barang1 = {"Keyboard", 5000};
    Barang barang2 = {"Mouse", 3000};
    Barang barang3 = {"Monitor", 7000};

    // Menambahkan barang ke keranjang
    AddToKeranjang(&user1.keranjang, barang1, 1); // 1 buah Keyboard
    AddToKeranjang(&user1.keranjang, barang2, 2); // 2 buah Mouse
    AddToKeranjang(&user1.keranjang, barang3, 1); // 1 buah Monitor

    // Menambahkan user1 ke list user
    InsertLastList(userList, user1);
}

int main() {
    // Deklarasi list user
    List userList;

    // Inisialisasi user dummy
    InitializeDummyUser(&userList);

    // Menampilkan informasi awal pengguna
    User currentUser = userList.A[0];
    printf("Selamat datang, %s!\n", currentUser.name);
    printf("Saldo awal: Rp %d\n", currentUser.money);

    // Memanggil fungsi CartPay
    CartPay(&userList, 0);

    // Menampilkan saldo setelah transaksi
    printf("Saldo setelah transaksi: Rp %d\n", userList.A[0].money);

    return 0;
}
