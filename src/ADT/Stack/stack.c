#include <stdio.h>
#include <stdlib.h>  // For malloc and free
#include "stack.h"

void CreateEmptyStack(Stack *S) {
    /* I.S. sembarang; */
    /* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
    /* jadi indeksnya antara 0.. MaxEl */
    /* Ciri stack kosong : TOP bernilai Nil */
    S->T = (infotype*) malloc(MaxEl * sizeof(infotype));  // Allocate memory dynamically for stack array
    if (S->T == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);  // Exit if memory allocation fails
    }
    S->TOP = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S) {
    /* Mengirim true jika Stack kosong: lihat definisi di atas */
    return S.TOP == Nil;
}

boolean IsFullStack(Stack S) {
    /* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (S.TOP == MaxEl - 1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushToStack(Stack *S, infotype X) {
    /* Menambahkan X sebagai elemen Stack S. */
    /* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
    /* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    if (IsFullStack(*S)) {
        printf("Stack penuh! Tidak bisa menambah elemen.\n");
        return;
    }
    S->TOP++;
    S->T[S->TOP] = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopFromStack(Stack *S, infotype* X) {
    /* Menghapus X dari Stack S. */
    /* I.S. S tidak mungkin kosong */
    /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    if (IsEmptyStack(*S)) {
        printf("Stack kosong! Tidak ada elemen untuk dihapus.\n");
        return;
    }
    *X = S->T[S->TOP];
    S->TOP--;
}

void DisplayStack(Stack S) {
    if (S.TOP == Nil) {
        printf("\nStack kosong.\n");
        return;
    }
    for (int i = S.TOP; i >= 0; i--) {
        printf("%d\n", S.TOP - i + 1);
        printf("Name: %s\n", S.T[i].name);
        printf("Price: %d\n", S.T[i].price);
        printf("---\n");
    }
}

/* Free dynamically allocated memory for stack */
void FreeStack(Stack *S) {
    free(S->T);  // Free the dynamically allocated memory
}
