#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void CreateEmptyStack(Stack *S) {
    S->T = (infotype*) malloc(MaxEl * sizeof(infotype));  // Dynamically allocate memory for stack array
    if (S->T == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);  // Exit if memory allocation fails
    }
    S->TOP = -1;  // Set stack as empty
}

boolean IsEmptyStack(Stack S) {
    return S.TOP == -1;
}

boolean IsFullStack(Stack S) {
    return S.TOP == MaxEl - 1;
}

void PushToStack(Stack *S, infotype X) {
    if (IsFullStack(*S)) {
        printf("Stack penuh! Tidak bisa menambah elemen.\n");
        return;
    }
    S->TOP++;
    S->T[S->TOP] = X;
}

void PopFromStack(Stack *S, infotype *X) {
    if (IsEmptyStack(*S)) {
        printf("Stack kosong! Tidak ada elemen untuk dihapus.\n");
        return;
    }
    *X = S->T[S->TOP];
    S->TOP--;
}

/*
void DisplayStack(Stack S) {
    if (IsEmptyStack(S)) {
        printf("\nStack kosong.\n");
        return;
    }
    for (int i = S.TOP; i >= 0; i--) {
        printf("%d\n", S.T[i]);
    }
}
*/

// Free dynamically allocated memory for stack
void FreeStack(Stack *S) {
    free(S->T);  // Free the dynamically allocated memory
}