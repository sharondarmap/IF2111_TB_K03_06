#include <stdio.h>
#include "stack.h"

void CreateEmpty(Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
   return Top(S) == Nil;
}

boolean IsFull(Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (Top(S) == MaxEl-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X = InfoTop(*S);
    Top(*S)--;
}

void DisplayStack(Stack S) {
    if (S.TOP == Nil) {
        printf("\n");
        return;
    }
    for (int i = S.TOP; i >= 0; i--) {
        printf("%d\n", S.TOP - i + 1);
        printf("Name: %s\n", S.T[i].name);
        printf("Price: %d\n", S.T[i].price);
        printf("---\n");
    }
}