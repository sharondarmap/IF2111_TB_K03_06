#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../src/ADT/Kustom/user.h"
#include "../src/ADT/MesinKata/mesinkata.h"

/* Library yang boleh digunakan hanya stdio.h, stdlib.h, time.h, dan math.h. */


void TebakAngka(){

    int r = rand() % 101; //mendapatkan integer dari 1––100
    int try = 0;

    while (try < 11){
        printf("Tebak angka: ");
        STARTWORD();
        WordToInt(currentWord);

        while (!isEndWord){
            printf("Kata yang dibaca: ");
            PrintWord(currentWord);
        
    }
}