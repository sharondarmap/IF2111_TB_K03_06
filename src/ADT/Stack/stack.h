#include "../../boolean.h"
#include "../Kustom/barang.h"

#ifndef STACK_H
#define STACK_H

#define MaxEl 100

typedef Barang infotype;  // Change to the appropriate type for stack elements

typedef struct {
    infotype *T;   // Dynamically allocated array for stack elements
    int TOP;       // Index of the top element in the stack
} Stack;

// Function declarations
void CreateEmptyStack(Stack *S);
boolean IsEmptyStack(Stack S);
boolean IsFullStack(Stack S);
void PushToStack(Stack *S, infotype X);
void PopFromStack(Stack *S, infotype *X);
void DisplayStack(Stack S);
void FreeStack(Stack *S); // Free dynamically allocated memory for stack

#endif
