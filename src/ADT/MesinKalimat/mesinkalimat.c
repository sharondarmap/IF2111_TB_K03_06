#include <stdio.h>
#include "mesinkalimat.h"

void ResetKalimat() {
    for (int i = 0; i < sizeof(CLine.TabLine); i++) {
        CLine.TabLine[i] = '\0';
        CLine.Length = 0;
    }
}
void SalinSatuKata() {
    ResetKalimat(); // Reset buffer
    int i = 0;
    while ((currentChar != ' ') && (currentChar != MARK) && (currentChar != '\n')) {
        CLine.TabLine[i] = currentChar;
        // printf("DEBUG: Karakter disalin ke kata = '%c'\n", currentChar); // Debug
        i++;
        ADV();
    }
    CLine.Length = i;
    CLine.TabLine[i] = '\0';
    // printf("DEBUG: Kata yang disalin = '%s'\n", CLine.TabLine); // Debug
}

void IgnoreNewline()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (currentChar == NEWLINE)
    {
        ADV();
    }
}

void SalinKalimat() {
    ResetKalimat();  // Reset array
    int i = 0;
    while ((currentChar != MARK) && (currentChar != NEWLINE) && (currentChar != EOF))
    {
        CLine.TabLine[i] = currentChar;
        // printf("%c", CC);
        i+= 1;
        ADV();
    }
    CLine.Length = i;
}

void ADVKALIMAT(){
    IgnoreNewline();
    IgnoreBlanks();
    if (currentChar == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
    // printf("DEBUG: Baris berikutnya yang dibaca = '%s'\n", CLine.TabLine);
}

void ParseBarang(Kalimat line, int *angka, char *nama) {
    // Inisialisasi variabel lokal
    int i = 0;
    Word angkaWord;
    angkaWord.Length = 0;

    // Parsing angka (bagian awal string)
    while (i < line.Length && line.TabLine[i] != ' ') { // Loop hingga bertemu spasi
        angkaWord.TabWord[angkaWord.Length] = line.TabLine[i];
        angkaWord.Length++;
        i++;
    }
    angkaWord.TabWord[angkaWord.Length] = '\0'; // Null-terminate untuk keamanan

    // Konversi Word angka menjadi integer
    *angka = WordToInt(angkaWord);

    // Lewati spasi
    while (i < line.Length && line.TabLine[i] == ' ') {
        i++;
    }

    // Parsing teks (sisa string setelah angka)
    int namaIndex = 0;
    while (i < line.Length) { // Loop hingga akhir string
        nama[namaIndex] = line.TabLine[i];
        namaIndex++;
        i++;
    }
    nama[namaIndex] = '\0'; // Null-terminate untuk keamanan
}

void ParseUser(Kalimat line, int *uang, char *nama, char *password) {
    int i = 0, j = 0;

    // Parsing uang (angka pertama)
    *uang = 0;
    while (line.TabLine[i] != ' ' && line.TabLine[i] != '\0') {
        *uang = *uang * 10 + (line.TabLine[i] - '0');
        i++;
    }

    // Lewati spasi
    while (line.TabLine[i] == ' ') i++;

    // Parsing nama
    j = 0;
    while (line.TabLine[i] != ' ' && line.TabLine[i] != '\0') {
        nama[j++] = line.TabLine[i++];
    }
    nama[j] = '\0'; // Null-terminate

    // Lewati spasi
    while (line.TabLine[i] == ' ') i++;

    // Parsing password
    j = 0;
    while (line.TabLine[i] != '\0') {
        password[j++] = line.TabLine[i++];
    }
    password[j] = '\0'; // Null-terminate
}


void STARTKALIMATFILE(char filename[]) {
    STARTFILE(filename);
    IgnoreNewline();
    if (currentChar == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
    // printf("DEBUG: Baris pertama yang dibaca = '%s'\n", CLine.TabLine);
}


void ADVSATUKATA() {
    IgnoreBlanks();
    IgnoreNewline();
    if (currentChar == ' ') {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinSatuKata();
    }
}
