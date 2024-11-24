#include <stdio.h>
#include "help.h"

// Fungsi untuk membandingkan kata (dengan ADT MesinKata)
boolean CompareWord(Word inputWord, char *command) {
    int i;
    for (i = 0; i < inputWord.Length && command[i] != '\0'; i++) {
        if (inputWord.TabWord[i] != command[i]) {
            return false;
        }
    }
    return (i == inputWord.Length && command[i] == '\0');
}

int main() {
    printf("===============================================\n");
    printf("          SELAMAT DATANG DI SISTEM SIMULASI CLI\n");
    printf("===============================================\n");
    printf("Ketik 'HELP' untuk melihat daftar perintah.\n");
    printf("Ketik 'EXIT' untuk keluar dari program.\n");

    while (1) {
        printf("\nMasukkan perintah: ");

        // Gunakan Mesin Kata untuk membaca input pengguna
        STARTWORD();

        // Periksa apakah input adalah "HELP"
        if (CompareWord(currentWord, "HELP")) {
            DisplayHelp1();
        }

        else if (CompareWord(currentWord, "HELP2")) {
            DisplayHelp2();
        }

        else if (CompareWord(currentWord, "HELP3")) {
            DisplayHelp3();
        }
        // Periksa apakah input adalah "EXIT"
        else if (CompareWord(currentWord, "EXIT")) {
            printf("Terima kasih telah menggunakan program ini. Sampai jumpa!\n");
            break;
        }
        // Jika perintah tidak dikenal
        else {
            printf("Perintah tidak dikenal. Ketik 'HELP' untuk melihat daftar perintah.\n");
        }
    }

    return 0;
}
