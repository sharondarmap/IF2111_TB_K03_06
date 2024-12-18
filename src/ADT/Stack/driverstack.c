#include <stdio.h>
#include "stack.h"

int main() {
    Stack S;

    // Create an empty stack
    CreateEmptyStack(&S);

    printf("=== DRIVER STACK ===\n\n");

    // Creating Barang elements
    Barang barang1 = {"Laptop", 10000};
    Barang barang2 = {"Mouse", 5000};
    Barang barang3 = {"Keyboard", 7500};
    Barang barang4 = {"Monitor", 15000};

    // Push items onto the stack
    printf("Pushing items onto the stack...\n");
    PushToStack(&S, barang1);
    PushToStack(&S, barang2);
    PushToStack(&S, barang3);
    PushToStack(&S, barang4);

    // Display the stack
    printf("\nCurrent stack:\n");
    DisplayStack(S);

    // Pop the top element from the stack
    printf("\nPopping the top item from the stack...\n");
    Barang poppedItem;
    PopFromStack(&S, &poppedItem);

    // Display the popped item
    printf("Popped item: %s, Price: %d\n", poppedItem.name, poppedItem.price);

    // Display the stack after popping
    printf("\nStack after popping the top item:\n");
    DisplayStack(S);

    // Free the stack memory
    FreeStack(&S);
    printf("\nMemory for the stack has been freed.\n");

    return 0;
}
