#include <stdio.h>
#include "register.h"

// Global variable untuk daftar pengguna
// List userList;

// void RegisterUser() {
//     Word username, password;
//     User newUser;

//     // Loop untuk validasi input username
//     do {
//         printf("Masukkan username: ");
//         STARTWORD(); // Baca username
//         username = currentWord;

//         if (username.Length == 0) {
//             printf("Username tidak boleh kosong. Silakan coba lagi.\n");
//         }
//     } while (username.Length == 0);

//     // Loop untuk validasi input password

//     do {
//         printf("Masukkan password: ");
//         STARTWORD(); // Baca password
//         // Validasi input kosong
//         if (currentWord.Length == 0) {
//         printf("Password tidak boleh kosong!\n");
//         return;
//         }
//         password = currentWord;

//         if (password.Length == 0) {
//             printf("Password tidak boleh kosong. Silakan coba lagi.\n");
//         }
//     } while (password.Length == 0);

//     // Konversi Word ke char array menggunakan fungsi CopyWordToCharArray
//     CopyWordToCharArray(username, newUser.name);
//     CopyWordToCharArray(password, newUser.password);

//     // Validasi: Cek apakah username unik
//     if (SearchList(userList, newUser.name)) {
//         printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", newUser.name);
//         return;
//     }

//     // Inisialisasi atribut user lainnya
//     newUser.money = 0; // Default uang awal adalah 0
    
//     // Tambahkan ke list
//     InsertLastList(&userList, newUser);
//     printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", newUser.name);
// }

// Fungsi Register
// void RegisterUser(List *userList) {
//     Word username, password;

//     while (1) { // Looping hingga registrasi berhasil
//         // Meminta input username
//         printf("Masukkan Username: ");
//         STARTWORD();
//         CopyWordToCharArray(currentWord, username.TabWord);
//         username.Length = currentWord.Length;

//         // Validasi username
//         if (username.Length == 0) {
//             printf("Username tidak boleh kosong. Silakan coba lagi.\n");
//             continue;
//         }
//         if (SearchUserIndex(*userList, username.TabWord) != -1) {
//             printf("Username sudah terdaftar. Silakan gunakan username lain.\n");
//             continue;
//         }

//         // Loop untuk validasi password
//         while (1) {
//             printf("Masukkan Password: ");
//             STARTWORD(); // Reset mesin kata dan baca input baru
//             CopyWordToCharArray(currentWord, password.TabWord);
//             password.Length = currentWord.Length;

//             // Validasi password kosong
//             if (password.Length == 0) {
//                 printf("Password tidak boleh kosong. Silakan coba lagi.\n");
//             } else {
//                 break; // Password valid, keluar dari loop password
//             }
//         }

//         // Tambahkan pengguna baru ke List
//         User newUser;
//         CopyWordToCharArray(username, newUser.name);
//         CopyWordToCharArray(password, newUser.password);
//         newUser.money = 0; // Default saldo

//         InsertLastList(userList, newUser);
//         printf("Registrasi berhasil. Silakan login.\n");
//         break; // Registrasi berhasil, keluar dari loop utama
//     }
// }


// Global variable untuk daftar pengguna
List userList;

void RegisterUser() {
    Word username, password;
    User newUser;

    // Reset username dan password
    
    ResetWord(&password);

    // Loop untuk validasi input username
    do {
        printf("Masukkan username: ");
        STARTWORD(); // Baca username
        username = currentWord;

        if (username.Length == 0) {
            printf("Username tidak boleh kosong. Silakan coba lagi.\n");
        }
    } while (username.Length == 0);

    // Reset password untuk memastikan tidak membawa input lama
    ResetWord(&currentWord);

    // Input password
    printf("Masukkan password: ");
    STARTWORD(); // Baca password
    password = currentWord;

    // Jika password kosong, keluar dari program
    if (password.Length == 0) {
        printf("Password tidak boleh kosong. Program akan keluar.\n");
        exit(0); // Keluar dari program
    }

    // Konversi Word ke char array
    CopyWordToCharArray(username, newUser.name);
    CopyWordToCharArray(password, newUser.password);

    // Validasi akhir: Pastikan username dan password tidak kosong
    if (newUser.name[0] == '\0' || newUser.password[0] == '\0') {
        printf("Registrasi gagal karena username atau password kosong.\n");
        return;
    }

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
