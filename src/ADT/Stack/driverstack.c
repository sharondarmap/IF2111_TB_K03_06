#include <stdio.h>
#include "stack.h"

int main() {
    Stack S;

    CreateEmpty(&S);

    printf("=== DRIVER STACK ===\n\n");

    // Membuat elemen Barang
    Barang barang1 = {"Laptop", 10000};
    Barang barang2 = {"Mouse", 5000};
    Barang barang3 = {"Keyboard", 7500};
    Barang barang4 = {"Monitor", 15000};

    //masukkan barang ke stack
    Push(&S, barang1);
    Push(&S, barang2);
    Push(&S, barang3);
    Push(&S, barang4);

    //menampilkan isi stack sekarang
    DisplayStack(S);

    //mengeluarkan elemen paling atas (TOP)
    Pop(&S, &barang4);
    DisplayStack(S);

    return 0;
}
