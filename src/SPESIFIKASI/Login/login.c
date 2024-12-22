#include "login.h"


void Login(List *userList, int *currentIndex) {
    Word username, password;

    while (1) { // Looping hingga login berhasil
        // Meminta input username
        printf("Masukkan Username: ");
        STARTWORD();
        CopyWordToCharArray(currentWord, username.TabWord);
        username.Length = currentWord.Length;

        // Cari username di List menggunakan SearchUserIndex
        *currentIndex = SearchUserIndex(*userList, username.TabWord);
        if (*currentIndex == -1) { // Jika username tidak ditemukan
            printf("Username tidak ditemukan. Coba lagi.\n");
            continue;
        }
        // Meminta input password
        printf("Masukkan Password: ");
        STARTWORD();
        CopyWordToCharArray(currentWord, password.TabWord);
        password.Length = currentWord.Length;

        // Ambil data pengguna dari List
        User user = GetList(*userList, *currentIndex);
        Word userPassword = StringToWord(user.password);
        
        // Validasi password
        if (IsWordEqual(password, userPassword)) {
            // Login berhasil
            printf("Login berhasil. Selamat datang, ");
            PrintWord(StringToWord(user.name));
            printf("!\n");
            // Inisialisasi keranjang jika belum diinisialisasi
            // Inisialisasi keranjang jika belum diinisialisasi
            CreateEmptyKeranjang(&userList->A[*currentIndex].keranjang);
            // printf("DEBUG: Keranjang berhasil diinisialisasi untuk pengguna %s.\n", user.name);
            break;
        } else {
            printf("Password salah. Coba lagi.\n");
        }
    }
}
