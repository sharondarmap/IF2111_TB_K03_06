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

void RegisterUser(List *userList) {
    Word username, password;
    User user;

    while (1) { // Looping hingga registrasi berhasil
        // Meminta input username
        printf("Masukkan Username: ");
        STARTWORD();
        CopyWordToCharArray(currentWord, username.TabWord);
        username.Length = currentWord.Length;

        // Validasi username
        if (username.Length == 0) {
            printf("Username tidak boleh kosong. Silakan coba lagi.\n");
            continue;
        }
        if (SearchUserIndex(*userList, username.TabWord) != -1) {
            printf("Username sudah terdaftar. Silakan gunakan username lain.\n");
            continue;
        }
        
// Reset password untuk memastikan tidak membawa input lama
    ResetWord(&currentWord);
        // Meminta input password
        while (1) {
            printf("Masukkan Password: ");
            STARTWORD();
            CopyWordToCharArray(currentWord, password.TabWord);
            password.Length = currentWord.Length;

            if (password.Length == 0) {
                printf("Password tidak boleh kosong. Silakan coba lagi.\n");
            } else {
                break; // Password valid
            }
        }

        // Tambahkan pengguna baru ke List
        CopyWordToCharArray(username, user.name);
        CopyWordToCharArray(password, user.password);
        user.money = 0;

        InsertLastList(userList, user);
        printf("Registrasi berhasil. Silakan login.\n");
        break; // Keluar dari loop registrasi
    }
}


// // Global variable untuk daftar pengguna
// List userList;

// void RegisterUser() {
//     Word username, password;
//     User user;

//     // Reset username dan password
    
//     ResetWord(&password);

//     // Loop untuk validasi input username
//     do {
//         printf("Masukkan username: ");
//         STARTWORD(); // Baca username
//         username = currentWord;

//         if (username.Length == 0) {
//             printf("Username tidak boleh kosong. Silakan coba lagi.\n");
//         }
//         // Validasi: Cek apakah username unik
//         else if (SearchList(userList, user.name)) 
//         {
//             printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", user.name);
//         }
//     } while ((username.Length == 0) || (SearchList(userList, user.name)));

//     // Reset password untuk memastikan tidak membawa input lama
//     ResetWord(&currentWord);   
//     do {
//         printf("Masukkan password: ");
//         STARTWORD(); // Baca password
//         password = currentWord;

//         if (password.Length == 0) {
//         printf("Password tidak boleh kosong. Program akan keluar.\n");
//         }
//     } while (password.Length == 0);


//     // // Input password
//     // printf("Masukkan password: ");
//     // STARTWORD(); // Baca password
//     // password = currentWord;

//     // // Jika password kosong, keluar dari program
//     // if (password.Length == 0) {
//     //     printf("Password tidak boleh kosong. Program akan keluar.\n");
//     //     exit(0); // Keluar dari program
//     // }

//     // Konversi Word ke char array
//     CopyWordToCharArray(username, user.name);
//     CopyWordToCharArray(password, user.password);

//     // Inisialisasi atribut user lainnya
//     user.money = 0; // Default uang awal adalah 0

//     // Tambahkan ke list
//     InsertLastList(&userList, user);
//     printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", user.name);
// }
