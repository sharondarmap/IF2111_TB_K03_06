#include <stdio.h>
#include "history.h"

// Fungsi untuk menginisialisasi user dan riwayat pembelian
void InitializeDummyUser(List *userList) {
    // Inisialisasi list user
    *userList = MakeList();

    // Membuat user dummy pertama
    User user1;
    strcpy(user1.name, "Alice");
    user1.money = 10000;

    // Inisialisasi stack riwayat pembelian
    CreateEmptyStack(&user1.riwayat_pembelian);

    // Menambahkan beberapa riwayat pembelian
    Barang barang1 = {"AK4740", 40};
    Barang barang2 = {"AK47100", 100};
    Barang barang3 = {"Lalabu35", 35};
    Barang barang4 = {"AK4710", 10};

    PushToStack(&user1.riwayat_pembelian, barang1);
    PushToStack(&user1.riwayat_pembelian, barang2);
    PushToStack(&user1.riwayat_pembelian, barang3);
    PushToStack(&user1.riwayat_pembelian, barang4);

    // Menambahkan user ke list
    InsertLastList(userList, user1);
}

int main() {
    List userList;
    InitializeDummyUser(&userList);

    // Menampilkan riwayat pembelian untuk user pertama
    history(&userList, 0, 10);  // Menampilkan 3 riwayat pembelian terbaru

    return 0;
}
