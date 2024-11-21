#include <stdio.h>
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

void STARTFILE(char filename[]) {
    pita = fopen(filename, "r");
    if (pita != NULL) {
        ADVFILE();
    } else {
        printf("\nERROR: File tidak ditemukan!\n\n");
        exit(0);
    }
}