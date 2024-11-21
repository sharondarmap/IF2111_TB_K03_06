#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/Kustom/user.h"
#include "../../ADT/MesinKata/mesinkata.h"
#include "../../ADT/List/list.h"
#include "wordl3.h"
#include "tebakangka.h"

/* Library yang boleh digunakan hanya stdio.h, stdlib.h, time.h, dan math.h. */

void WorkChallenge(List *userList, IdxType currentIndex) {
    User *currentUser = &userList->A[currentIndex]; //mengambil user saat ini
    int mulaichallenge = 1; //control variable untuk loop

    while (mulaichallenge) {
        printf("\nWELCOME TO WORK CHALLENGE!\n");
        printf("Daftar challenge yang tersedia:\n"
               "1. Tebak Angka (biaya main=200)\n"
               "2. W0RDL3 (biaya main=500)\n"
               "3. Keluar dari work challenge (quit)\n");
        printf("Saldo Anda saat ini: %d\n", currentUser->money);
        printf(">> ");

        STARTWORD(); //input user
        int pilihan = WordToInt(currentWord); // Convert user input to integer

        if (pilihan == 1) { // Tebak Angka
            if (currentUser->money >= 200) {
                currentUser->money -= 200; //mengurangi saldo dengan harga game

                int triesUsed = TebakAngka(); // Call TebakAngka
                if (triesUsed <= 10) { //tebakan benar
                    int reward = 500 - triesUsed * 20;
                    currentUser->money += reward;
                    printf("Selamat! %d rupiah telah ditambahkan ke akun Anda.\n", reward);
                } else {
                    printf("Sayang sekali, Anda tidak mendapatkan hadiah.\n");
                }
            } else {
                printf("Uang Anda tidak cukup untuk memainkan game ini.\n");
            }
        } else if (pilihan == 2) { // W0RDL399
            if (currentUser->money >= 500) {
                currentUser->money -= 500; //mengurangi saldo seharga game

                int chancesUsed = WORDL3(); // memanggil WORDL3
                if (chancesUsed <= 5) { //tebakan benar
                    int reward = 3000 - chancesUsed * 100;
                    currentUser->money += reward;
                    printf("Selamat! %d rupiah telah ditambahkan ke akun Anda.\n", reward);
                } else { //tebakan dan chances habis
                    printf("Sayang sekali, Anda tidak mendapatkan hadiah.\n");
                }
            } else {
                printf("Uang Anda tidak cukup untuk memainkan game ini.\n");
            }
        } else if (pilihan == 3) { //quit
            printf("Terima kasih telah mencoba Work Challenge!\n");
            mulaichallenge = 0; //exit loop
        } else { //invalid input
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
}
