#include <stdio.h>
#include <stdlib.h>

#include "login.h"

int main() {
    // Inisialisasi List pengguna
    List userList = MakeList();
    int currentIndex = -1; // Menandakan tidak ada pengguna yang login

    // Tambahkan pengguna ke List
    User user1 = {"admin", "admin123", 10000};
    User user2 = {"user", "user123", 5000};
    InsertLastList(&userList, user1);
    InsertLastList(&userList, user2);

    // Tampilkan daftar pengguna
    printf("Daftar Pengguna:\n");
    PrintList(userList);

    // Panggil fungsi Login
    Login(&userList, &currentIndex);

    // Tampilkan hasil login
    if (currentIndex != -1) {
        User loggedInUser = GetList(userList, currentIndex);
        printf("\nPengguna yang sedang login:\n");
        printf("Nama: %s\n", loggedInUser.name);
        printf("Uang: %d\n", loggedInUser.money);
    }

    return 0;
}