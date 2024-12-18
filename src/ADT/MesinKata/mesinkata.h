/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include <stdlib.h>
#include "../MesinKarakter/mesinkarakter.h"
#include "../../boolean.h"
#include <stdlib.h>

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean endWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean isEndWord();

int WordToInt(Word w);
/* Mengonversi Word menjadi integer
   I.S. : Word valid yang berisi angka
   F.S. : Mengembalikan nilai integer dari Word */

Word IntToWord(int num);
/* Mengonversi integer menjadi Word
   I.S. : Integer valid
   F.S. : Mengembalikan Word yang merepresentasikan angka */

Word StringToWord(char *str);
/* Mengonversi string menjadi Word
   I.S. : String valid
   F.S. : Mengembalikan Word yang merepresentasikan string */

char *WordToString(Word w);
/* Mengonversi Word menjadi string
   I.S. : Word valid
   F.S. : Mengembalikan string yang merepresentasikan Word */

void PrintWord(Word w);
/* Mencetak Word ke layar
   I.S. : Word valid
   F.S. : Word dicetak ke layar tanpa tambahan karakter */

boolean IsWordEqual(Word w1, Word w2);
/* Membandingkan dua Word
   I.S. : Dua Word valid
   F.S. : Mengembalikan true jika kedua Word sama */

Word TrimWord(Word w);
/* Menghapus karakter kosong di akhir string
   I.S. : w adalah Word yang valid
   F.S. : w adalah Word yang sama tanpa karakter kosong di akhir string */

void ResetWord(Word *w);

boolean IsWordNumeric(Word W);
/* mengembalikan apakah kata berupa integer atau bukan */

#endif