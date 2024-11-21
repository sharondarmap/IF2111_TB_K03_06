#include "../MesinKata/mesinkata.h"
#include "../../boolean.h"
boolean EndKalimat;

#ifndef __MESINKALIMAT_H__
#define __MESINKALIMAT_H__

#define NMaks 100
#define NEWLINE '\n'
#define MARK2 '\0'

typedef struct {
  char TabLine[NMaks+1];
  int Length;
} Kalimat;

boolean EndKalimat;
Kalimat CLine;
Kalimat CInput;
Kalimat CCommand;

void ResetKalimat();
/* Mengosongkan isi CLine
   I.S. : CLine terdefinisi
   F.S. : CLine kosong, semua elemen TabLine diisi dengan '\0' dan Length = 0 */

void SalinSatuKata();
/* Mengakuisisi satu kata dari input
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : CLine berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK atau currentChar = NEWLINE;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi */

void IgnoreNewline();
/* Mengabaikan satu atau beberapa NEWLINE
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ NEWLINE atau currentChar = MARK */

void SalinKalimat();
/* Mengakuisisi kalimat dari input
   I.S. : currentChar adalah karakter pertama dari kalimat
   F.S. : CLine berisi kalimat yang sudah diakuisisi;
          currentChar = MARK atau currentChar = NEWLINE atau currentChar = EOF;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi */

void ADVKALIMAT();
/* Memajukan pembacaan kalimat
   I.S. : currentChar adalah karakter pertama dari kalimat yang akan diakuisisi
   F.S. : CLine adalah kalimat terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kalimat berikutnya, mungkin MARK
          Jika currentChar = MARK, EndKalimat = true */

void STARTKALIMATFILE(char filename[]);
/* Memulai pembacaan kalimat dari file
   I.S. : filename adalah nama file yang valid
   F.S. : EndKalimat = true jika currentChar = MARK2;
          EndKalimat = false jika currentChar ≠ MARK2;
          CLine berisi kalimat pertama yang sudah diakuisisi */

void ADVSATUKATA();
/* Memajukan pembacaan satu kata
   I.S. : currentChar adalah karakter pertama dari kata yang akan diakuisisi
   F.S. : CLine adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin ' '
          Jika currentChar = ' ', EndKalimat = true */

void ParseBarang(Kalimat line, int *angka, char *nama);
/* Mem-parsing kalimat menjadi angka dan nama
   I.S. : line berisi kalimat yang valid
   F.S. : angka berisi nilai integer yang diparsing dari bagian awal kalimat,
          nama berisi string yang diparsing dari sisa kalimat setelah angka */

void ParseBarang(Kalimat line, int *angka, char *nama);
/* Mem-parsing kalimat menjadi angka dan nama
   I.S. : line berisi kalimat yang valid
   F.S. : angka berisi nilai integer yang diparsing dari bagian awal kalimat,
          nama berisi string yang diparsing dari sisa kalimat setelah angka */

#endif