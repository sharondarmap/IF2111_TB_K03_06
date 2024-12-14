#ifndef LIST_H
#define LIST_H

#include "../../boolean.h"
#include "../Kustom/user.h"
#include "../MesinKata/mesinkata.h"

/* Definisi ukuran maksimum elemen dalam list */
#define MaxEl 100

/* Definisi indeks dan elemen list */
typedef int IdxType;
typedef User ElType;

/* Definisi Mark untuk elemen kosong */
#define Mark -1

/* Definisi struktur list */
typedef struct {
    ElType A[MaxEl];
} List;

int CompareStrings(char *str1, char *str2);

void CopyString(char *dest, char *src);

/* ********* KONSTRUKTOR ********* */
/* Membuat list kosong */
List MakeList();
/* I.S. sembarang */
/* F.S. Terbentuk List kosong dengan semua elemen diinisialisasi sebagai kosong */

/* ********* FUNGSI PENGECEKAN ********* */
boolean IsEmptyList(List L);
/* Mengembalikan true jika List kosong (tidak ada elemen) */

int LengthList(List L);
/* Mengembalikan banyaknya elemen efektif dalam List */

/* ********* AKSES ELEMEN ********* */
ElType GetList(List L, IdxType i);
/* Mengembalikan elemen pada indeks ke-i */

void SetList(List *L, IdxType i, ElType v);
/* Mengubah elemen pada indeks ke-i menjadi elemen baru v */

/* ********* INDEKS ********* */
IdxType FirstIdxList(List L);
/* Mengembalikan indeks pertama dalam List */

IdxType LastIdxList(List L);
/* Mengembalikan indeks terakhir elemen dalam List */

boolean IsIdxValidList(List L, IdxType i);
/* Mengembalikan true jika indeks i berada dalam range 0 hingga MaxEl-1 */

boolean IsIdxEffList(List L, IdxType i);
/* Mengembalikan true jika indeks i efektif (ada elemen di posisi tersebut) */

/* ********* OPERASI PADA LIST ********* */
boolean SearchList(List L, char *name);
/* Mencari elemen berdasarkan name */
/* Mengembalikan true jika elemen dengan nama tertentu ditemukan */

void InsertFirstList(List *L, ElType X);
/* Menambahkan elemen di awal List */
/* I.S. List terdefinisi, tidak penuh */
/* F.S. Elemen baru ditambahkan di awal List, elemen lainnya bergeser */

void InsertAtList(List *L, ElType X, IdxType i);
/* Menambahkan elemen di indeks i */
/* I.S. List terdefinisi, tidak penuh, dan indeks i valid */
/* F.S. Elemen baru ditambahkan di indeks i, elemen lainnya bergeser */

void InsertLastList(List *L, ElType X);
/* Menambahkan elemen di akhir List */
/* I.S. List terdefinisi, tidak penuh */
/* F.S. Elemen baru ditambahkan di akhir List */

void DeleteFirstList(List *L);
/* Menghapus elemen pertama dari List */
/* I.S. List tidak kosong */
/* F.S. Elemen pertama dihapus, elemen lainnya bergeser */

void DeleteAtList(List *L, IdxType i);
/* Menghapus elemen pada indeks i */
/* I.S. List tidak kosong, indeks i valid */
/* F.S. Elemen di indeks i dihapus, elemen lainnya bergeser */

void DeleteLastList(List *L);
/* Menghapus elemen terakhir dari List */
/* I.S. List tidak kosong */
/* F.S. Elemen terakhir dihapus */

List ConcatList(List L1, List L2);
/* Menggabungkan dua List menjadi satu List baru */
/* I.S. L1 dan L2 terdefinisi */
/* F.S. List baru yang berisi elemen dari L1 diikuti elemen dari L2 */

/* Header untuk prosedur PrintUser dan PrintList */
void PrintUser(User u);
/* I.S. u terdefinisi */
/* F.S. Informasi user dicetak ke layar dengan format {name: ..., password: ..., money: ...} */

void PrintList(List L);
/* I.S. L terdefinisi */
/* F.S. Elemen-elemen dalam list dicetak ke layar dengan format [{name: ..., password: ..., money: ...}, ...] */

void CopyWordToCharArray(Word src, char *dest);
/* Menyalin isi Word ke array karakter
   I.S. : src adalah Word yang valid, dest adalah array karakter yang cukup besar
   F.S. : dest berisi salinan karakter dari src, diakhiri dengan null-terminator */

int SearchUserIndex(List L, char *name);
/* Mencari indeks user berdasarkan nama
   I.S. : L terdefinisi, name adalah string yang valid
   F.S. : Mengembalikan indeks user jika ditemukan, -1 jika tidak ditemukan */

#endif
