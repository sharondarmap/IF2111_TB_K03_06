#include <stdio.h>
#include "stack.h"

int main() {
    Stack S;

    CreateEmptyStack(&S);

    printf("=== DRIVER STACK ===\n\n");

    // Membuat elemen Barang
    Barang barang1 = {"Laptop", 10000};
    Barang barang2 = {"Mouse", 5000};
    Barang barang3 = {"Keyboard", 7500};
    Barang barang4 = {"Monitor", 15000};

    //masukkan barang ke stack
    PushToStack(&S, barang1);
    PushToStack(&S, barang2);
    PushToStack(&S, barang3);
    PushToStack(&S, barang4);

    //menampilkan isi stack sekarang
    DisplayStack(S);

    //mengeluarkan elemen paling atas (TOP)
    PopFromStack(&S, &barang4);
    DisplayStack(S);

    return 0;
}
