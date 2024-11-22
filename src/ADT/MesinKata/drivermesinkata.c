#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"
//gcc -o drivermesinkarakter drivermesinkarakter.c mesinkarakter.c mesinkata.c

int main() {
    printf("=== DRIVER MESIN KATA ===\n");

    // 1. STARTWORD dan ADVWORD
    printf("\n[TEST: STARTWORD dan ADVWORD]\n");
    printf("Masukkan input: ");
    STARTWORD();

    while (!isEndWord()) {
        printf("Kata yang dibaca: ");
        PrintWord(currentWord); // Cetak kata yang dibaca
        printf("\nPanjang kata: %d\n", currentWord.Length); // Tampilkan panjang kata
        ADVWORD(); // Lanjutkan ke kata berikutnya
    }
    printf("=== Selesai Membaca Input ===\n");

    // 2. CopyWord
    printf("\n[TEST: CopyWord]\n");
    printf("Masukkan input untuk CopyWord: ");
    STARTWORD();
    printf("Kata pertama yang disalin: ");
    PrintWord(currentWord);
    printf("\n");

    // 3. WordToInt
    printf("\n[TEST: WordToInt]\n");
    Word angkaWord = StringToWord("12345");
    printf("Kata: ");
    PrintWord(angkaWord);
    printf("\nKonversi ke integer: %d\n", WordToInt(angkaWord));

    // 4. IntToWord
    printf("\n[TEST: IntToWord]\n");
    int angka = 98765;
    Word angkaKeWord = IntToWord(angka);
    printf("Angka: %d\n", angka);
    printf("Konversi ke Word: ");
    PrintWord(angkaKeWord);
    printf("\n");

    // 5. IsWordEqual
    printf("\n[TEST: IsWordEqual]\n");
    Word word1 = StringToWord("admin");
    Word word2 = StringToWord("admin");
    Word word3 = StringToWord("password");
    printf("Word1: ");
    PrintWord(word1);
    printf("\nWord2: ");
    PrintWord(word2);
    printf("\nWord3: ");
    PrintWord(word3);
    printf("\nWord1 == Word2: %s\n", IsWordEqual(word1, word2) ? "true" : "false");
    printf("Word1 == Word3: %s\n", IsWordEqual(word1, word3) ? "true" : "false");

    // 6. StringToWord dan WordToString
    printf("\n[TEST: StringToWord dan WordToString]\n");
    char str[] = "REGISTER";
    Word strToWord = StringToWord(str);
    char *wordToStr = WordToString(strToWord);
    printf("String ke Word: ");
    PrintWord(strToWord);
    printf("\nWord ke String: %s\n", wordToStr);
    free(wordToStr); // Bebaskan memori yang dialokasikan

    return 0;
}