#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "workchallenge.h"

//gcc -o workceleng src/SPESIFIKASI/workchallenge/driverworkchallenge.c src/ADT/MesinKata/mesinkata.c src/ADT/MesinKarakter/mesinkarakter.c src/ADT/List/list.c src/SPESIFIKASI/workchallenge/tebakangka.c src/SPESIFIKASI/workchallenge/wordl3.c src/SPESIFIKASI/workchallenge/workchallenge.c

int main(){

    List L1 = MakeList();

    User u1 = {"Izhar", "pass123", 500};
    User u2 = {"Harfhan", "secure456", 1000};
    User u3 = {"Sharon", "mypassword", 750};
    User u4 = {"Gita", "hello789", 6000};
    int currentIndex = 0;

    InsertFirstList(&L1, u1);
    InsertFirstList(&L1, u2);
    InsertFirstList(&L1, u3);
    InsertFirstList(&L1, u4);

    PrintList(L1);

    WorkChallenge(&L1, 0);

    PrintList(L1);

}