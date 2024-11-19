#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../src/ADT/Kustom/user.h"
#include "../src/ADT/MesinKata/mesinkata.h"
/* Library yang boleh digunakan hanya stdio.h, stdlib.h, time.h, dan math.h. */

void TebakAngka() {
    int r = rand() % 101; // Random number between 0–100
    int try = 0;

    while (try < 10) {
        printf("Tebak angka: ");
        STARTWORD(); //setiap pengguna salah memasukkan angka, loop akan kembali ke STARTWORD

        int guessedNumber = WordToInt(currentWord); //meng-convert word ke integer
        printf("Angka yang dimasukkan: ");
        PrintWord(currentWord);

        if (guessedNumber == r) {
            printf("\nSelamat! Anda berhasil menebak angka: %d\n", r);
            break;
        } else if (guessedNumber < r) {
            printf("\nTerlalu kecil!\n");
        } else {
            printf("\nTerlalu besar!\n");
        }

        try++;
        printf("Sisa percobaan: %d\n\n", 11 - try);
    }

    if (try == 10) {
        printf("Sayang sekali! Angka yang benar adalah: %d\n", r);
    }
}

int main(){
    TebakAngka();

    return 0;
}