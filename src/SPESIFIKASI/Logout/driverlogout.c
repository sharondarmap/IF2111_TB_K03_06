#include <stdio.h>
#include <string.h>
#include "logout.h"

int main() {
    // Inisialisasi List pengguna
    List userList = MakeList();
    int currentIndex = -1; // Menandakan tidak ada pengguna yang login

    // Tambahkan pengguna ke List
    User user1 = {"admin", "admin123", 10000};
    User user2 = {"user", "user123", 5000};
    InsertLastList(&userList, user1);
    InsertLastList(&userList, user2);

    // Simulasi pengguna login
    currentIndex = 0; // Misalnya, pengguna pertama (admin) sedang login
    printf("Pengguna yang sedang login:\n");
    User loggedInUser = GetList(userList, currentIndex);
    printf("Nama: %s\n", loggedInUser.name);
    printf("Uang: %d\n", loggedInUser.money);

    // Logout
    printf("\nMelakukan Logout...\n");
    Logout(&currentIndex);

    // Periksa status login
    if (currentIndex == -1) {
        printf("\nTidak ada pengguna yang sedang login.\n");
    }

    return 0;
}
