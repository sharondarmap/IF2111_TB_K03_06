#ifndef LIST_H
#define LIST_H

#include "..\..\boolean.h"
#include "..\Kustom\user.h"

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

/* ********* KONSTRUKTOR ********* */
/* Membuat list kosong */
List MakeList();
/* I.S. sembarang */
/* F.S. Terbentuk List kosong dengan semua elemen diinisialisasi sebagai kosong */

/* ********* FUNGSI PENGECEKAN ********* */
boolean IsEmpty(List L);
/* Mengembalikan true jika List kosong (tidak ada elemen) */

int Length(List L);
/* Mengembalikan banyaknya elemen efektif dalam List */

/* ********* AKSES ELEMEN ********* */
ElType Get(List L, IdxType i);
/* Mengembalikan elemen pada indeks ke-i */

void Set(List *L, IdxType i, ElType v);
/* Mengubah elemen pada indeks ke-i menjadi elemen baru v */

/* ********* INDEKS ********* */
IdxType FirstIdx(List L);
/* Mengembalikan indeks pertama dalam List */

IdxType LastIdx(List L);
/* Mengembalikan indeks terakhir elemen dalam List */

boolean IsIdxValid(List L, IdxType i);
/* Mengembalikan true jika indeks i berada dalam range 0 hingga MaxEl-1 */

boolean IsIdxEff(List L, IdxType i);
/* Mengembalikan true jika indeks i efektif (ada elemen di posisi tersebut) */

/* ********* OPERASI PADA LIST ********* */
boolean Search(List L, char *name);
/* Mencari elemen berdasarkan name */
/* Mengembalikan true jika elemen dengan nama tertentu ditemukan */

void InsertFirst(List *L, ElType X);
/* Menambahkan elemen di awal List */
/* I.S. List terdefinisi, tidak penuh */
/* F.S. Elemen baru ditambahkan di awal List, elemen lainnya bergeser */

void InsertAt(List *L, ElType X, IdxType i);
/* Menambahkan elemen di indeks i */
/* I.S. List terdefinisi, tidak penuh, dan indeks i valid */
/* F.S. Elemen baru ditambahkan di indeks i, elemen lainnya bergeser */

void InsertLast(List *L, ElType X);
/* Menambahkan elemen di akhir List */
/* I.S. List terdefinisi, tidak penuh */
/* F.S. Elemen baru ditambahkan di akhir List */

void DeleteFirst(List *L);
/* Menghapus elemen pertama dari List */
/* I.S. List tidak kosong */
/* F.S. Elemen pertama dihapus, elemen lainnya bergeser */

void DeleteAt(List *L, IdxType i);
/* Menghapus elemen pada indeks i */
/* I.S. List tidak kosong, indeks i valid */
/* F.S. Elemen di indeks i dihapus, elemen lainnya bergeser */

void DeleteLast(List *L);
/* Menghapus elemen terakhir dari List */
/* I.S. List tidak kosong */
/* F.S. Elemen terakhir dihapus */

List Concat(List L1, List L2);
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

#endif
