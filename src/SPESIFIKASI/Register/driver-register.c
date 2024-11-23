#include <stdio.h>
#include "register.h"

List userList;
// int main() {
//     // Inisialisasi list pengguna
//     userList = MakeList();

//     printf("=== Program REGISTER ===\n");
//     RegisterUser();

//     return 0;
// }
#include <stdio.h>
#include "register.h"

// Fungsi untuk mencetak daftar pengguna yang terdaftar
void PrintUserList(List userList) {
    printf("Daftar pengguna terdaftar:\n");
    if (IsEmptyList(userList)) {
        printf("- Tidak ada pengguna terdaftar.\n");
    } else {
        for (int i = FirstIdxList(userList); i <= LastIdxList(userList); i++) {
            User user = GetList(userList, i);
            printf("- Username: %s, Password: %s, Money: %d\n", user.name, user.password, user.money);
        }
    }
}

int main() {
    // Inisialisasi daftar pengguna
    userList = MakeList();

    printf("=== DRIVER REGISTER ===\n");

    // Test Case 1: Registrasi valid
    printf("\n[Test Case 1] Registrasi pengguna pertama:\n");
    printf("Input:\nUsername: johndoe\nPassword: securepass\n");
    RegisterUser();
    PrintUserList(userList);

    // Test Case 2: Username sudah ada
    printf("\n[Test Case 2] Registrasi dengan username yang sama:\n");
    printf("Input:\nUsername: johndoe\nPassword: newpass\n");
    RegisterUser();
    PrintUserList(userList);

    // Test Case 3: Registrasi valid lagi
    printf("\n[Test Case 3] Registrasi pengguna kedua:\n");
    printf("Input:\nUsername: janedoe\nPassword: anotherpass\n");
    RegisterUser();
    PrintUserList(userList);

    // Test Case 4: Username kosong
    printf("\n[Test Case 4] Registrasi dengan username kosong:\n");
    printf("Input:\nUsername: [kosong]\nPassword: nopass\n");
    RegisterUser();
    PrintUserList(userList);

    // Test Case 5: Password kosong
    printf("\n[Test Case 5] Registrasi dengan password kosong:\n");
    printf("Input:\nUsername: newuser\nPassword: [kosong]\n");
    RegisterUser();
    PrintUserList(userList);

    return 0;
}
