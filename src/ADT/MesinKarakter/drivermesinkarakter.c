#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkarakter.c"

int main() {
    printf("=== DRIVER MESIN KARAKTER ===\n\n");

    printf("[TEST: START]\n");
    printf("Masukkan input: ");
    START(); 

    printf("\n\n[TEST: ADV]\n");
    printf("Membaca karakter satu per satu hingga MARK:\n");

    while (!IsEOP()) { 
        printf("Karakter saat ini: '%c'\n", GetCC());
        ADV(); 
    }

    printf("\n[TEST: IsEOP]\n");
    if (IsEOP()) {
        printf("Akhir pita (MARK) telah tercapai.\n");
    }

    printf("\nDriver selesai dijalankan.\n");

    return 0;
}
