#include <stdio.h>
#include "register.h"

// Global variable untuk daftar pengguna
List userList;

void RegisterUser() {
    Word username, password;
    User newUser;

    // Loop untuk validasi input username
    do {
        printf("Masukkan username: ");
        STARTWORD(); // Baca username
        username = currentWord;

        if (username.Length == 0) {
            printf("Username tidak boleh kosong. Silakan coba lagi.\n");
        }
    } while (username.Length == 0);

    // Loop untuk validasi input password

    do {
        printf("Masukkan password: ");
        STARTWORD(); // Baca password
        password = currentWord;

        if (password.Length == 0) {
            printf("Password tidak boleh kosong. Silakan coba lagi.\n");
        }
    } while (password.Length == 0);

    // Konversi Word ke char array menggunakan fungsi CopyWordToCharArray
    CopyWordToCharArray(username, newUser.name);
    CopyWordToCharArray(password, newUser.password);

    // Validasi: Cek apakah username unik
    if (SearchList(userList, newUser.name)) {
        printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", newUser.name);
        return;
    }

    // Inisialisasi atribut user lainnya
    newUser.money = 0; // Default uang awal adalah 0
    
    // Tambahkan ke list
    InsertLastList(&userList, newUser);
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", newUser.name);
}

