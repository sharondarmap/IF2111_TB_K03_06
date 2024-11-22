#include <stdio.h>
#include "src/ADT/List/list.h"
#include <string.h>

void Logout(User *currentUser) {
    if (currentUser != NULL && strlen(currentUser->name) > 0) {
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", currentUser->name);
        // Mengosongkan data pengguna
        currentUser->name[0] = '\0';  // Mengosongkan nama pengguna
        currentUser->password[0] = '\0';  // Mengosongkan password pengguna
        currentUser->money = 0;  // Reset saldo menjadi 0 atau default
    } else {
        printf("Tidak ada pengguna yang sedang login.\n");
    }
}