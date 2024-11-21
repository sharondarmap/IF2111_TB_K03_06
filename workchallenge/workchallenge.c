#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../src/ADT/Kustom/user.h"
#include "../src/ADT/MesinKata/mesinkata.h"
#include "../src/ADT/List/list.h"
#include "wordl3.h"
#include "tebakangka.h"

/* Library yang boleh digunakan hanya stdio.h, stdlib.h, time.h, dan math.h. */

void WorkChallenge(List *userList, IdxType currentIndex) {
    // Get the current user
    User *currentUser = &userList->A[currentIndex];

    printf("WELCOME TO WORK CHALLENGE!\n");
    printf("Daftar challenge yang tersedia:\n"
           "1. Tebak Angka (biaya main=200)\n"
           "2. W0RDL399 (biaya main=500)\n"
           "3. Keluar dari work challenge (quit)\n");
    printf("Saldo Anda saat ini: %d\n", currentUser->money);
    printf(">> ");

    STARTWORD(); // Start capturing user input
    int pilihan = WordToInt(currentWord); // Convert user input to integer

    if (pilihan == 1) { // If user selects "Tebak Angka"
        if (currentUser->money >= 200) {
            currentUser->money -= 200; // Deduct cost of the game

            int triesUsed = TebakAngka(); // Call TebakAngka
            if (triesUsed <= 10) { // User guessed correctly
                int reward = 500 - triesUsed * 20;
                currentUser->money += reward;
                printf("Selamat! %d rupiah telah ditambahkan ke akun Anda.\n", reward);
            } else { // User failed to guess
                printf("Sayang sekali, Anda tidak mendapatkan hadiah.\n");
            }
        } else {
            printf("Uang Anda tidak cukup untuk memainkan game ini.\n");
        }
    } else if (pilihan == 2) { // If user selects "W0RDL399"
        if (currentUser->money >= 500) {
            currentUser->money -= 500; // Deduct cost of the game

            int chancesUsed = WORDL3(); // Call WORDL3
            if (chancesUsed <= 5) { // User guessed correctly
                int reward = 3000 - chancesUsed * 100;
                currentUser->money += reward;
                printf("Selamat! %d rupiah telah ditambahkan ke akun Anda.\n", reward);
            } else { // User failed to guess
                printf("Sayang sekali, Anda tidak mendapatkan hadiah.\n");
            }
        } else {
            printf("Uang Anda tidak cukup untuk memainkan game ini.\n");
        }
    } else if (pilihan == 3) {
        printf("Terima kasih telah mencoba Work Challenge!\n");
    } else {
        printf("Pilihan tidak valid.\n");
    }
}