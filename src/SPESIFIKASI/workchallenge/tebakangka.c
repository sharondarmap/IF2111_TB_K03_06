#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../../ADT/Kustom/user.h"
#include "../../ADT/MesinKata/mesinkata.h"
/* Library yang boleh digunakan hanya stdio.h, stdlib.h, time.h, dan math.h. */

int TebakAngka() {
    srand(time(NULL));
    int r = rand() % 101; // Random number between 0–100
    int try = 0;

    while (try < 10) {
        printf("Tebak angka: ");
        STARTWORD(); // Start capturing user input
        int guessedNumber = WordToInt(currentWord);

        if (guessedNumber == r) {
            printf("\nSelamat! Anda berhasil menebak angka: %d\n", r);
            return try + 1; // Return the number of tries used
        } else if (guessedNumber < r) {
            printf("\nTerlalu kecil!\n");
        } else {
            printf("\nTerlalu besar!\n");
        }
        
        try++;
        printf("Sisa percobaan: %d\n\n", 10 - try);
    }

    // If the loop ends, the user failed to guess the number
    printf("Sayang sekali! Angka yang benar adalah: %d\n", r);
    return 11; // Return 11 to indicate failure
}
