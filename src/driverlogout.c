#include <stdio.h>
#include "src/ADT/List/list.h"
#include <string.h>

int main() {
    User activeUser = {"johndoe", "password123", 500};

    // Logout
    Logout(&activeUser);

    // Verifikasi setelah logout
    if (strlen(activeUser.name) == 0) {
        printf("Pengguna berhasil logout dan datanya telah dikosongkan.\n");
    }
    return 0;
}