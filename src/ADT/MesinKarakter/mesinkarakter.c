#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

void START() {
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    /* Algoritma */
    pita = stdin;
    ADV();
}

void ADV() {
    /* Pita dimajukan satu karakter. ... */
    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
//     EOP = (currentChar == MARK);
//     if (EOP) {
//         fclose(pita);
//     }
}

char GetCC() {
    /* Mengirimkan currentChar */
    /* Algoritma */
    return currentChar;
}

boolean IsEOP() {
    /* Mengirimkan true jika currentChar = MARK */
    /* Algoritma */
    return EOP;
}

void ADVFILE() {
    retval = fscanf(pita,"%c",&currentChar);
    if (feof(pita)) {
       fclose(pita);
    }
}

boolean STARTFILE(char filename[]) {

    pita = fopen(filename, "r"); // Membuka file
    if (pita != NULL) {
        ADVFILE(); // Lanjutkan membaca karakter pertama
        return true; // Indikasi file berhasil dibuka
    } else {
        return false; // Indikasi file tidak ditemukan
    }
}