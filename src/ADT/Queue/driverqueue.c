#include <stdio.h>
#include "queue.h"
#include "queue.c"

int main() {
    Queue q;
    CreateQueue(&q);

    printf("=== DRIVER QUEUE ===\n\n");

    // Membuat elemen Barang
    Barang barang1 = {"Laptop", 10000};
    Barang barang2 = {"Mouse", 5000};
    Barang barang3 = {"Keyboard", 7500};
    Barang barang4 = {"Monitor", 15000};

    // 1. Test isEmpty
    printf("[TEST: isEmpty]\n");
    printf("Apakah queue kosong? %s\n\n", isEmpty(q) ? "Ya" : "Tidak");

    // 2. Test enqueue
    printf("[TEST: enqueue]\n");
    enqueue(&q, barang1);
    enqueue(&q, barang2);
    enqueue(&q, barang3);
    printf("Queue setelah enqueue: ");
    displayQueue(q);
    printf("\n");

    // 3. Test length
    printf("[TEST: length]\n");
    printf("Panjang queue: %d\n\n", length(q));

    // 4. Test dequeue
    printf("[TEST: dequeue]\n");
    Barang val;
    dequeue(&q, &val);
    printf("Barang yang diambil: %s, %d}\n", val.name, val.price);
    printf("Queue setelah dequeue: ");
    displayQueue(q);
    printf("\n");

    // 5. Test enqueue tambahan
    printf("[TEST: enqueue tambahan]\n");
    enqueue(&q, barang4);
    printf("Queue setelah enqueue tambahan: ");
    displayQueue(q);
    printf("\n");

    // 6. Test dequeue hingga kosong
    printf("[TEST: dequeue hingga kosong]\n");
    while (!isEmpty(q))
    {
        dequeue(&q, &val);
        printf("Barang yang diambil: {name: %s, price: %d}\n", val.name, val.price);
        printf("Queue sekarang: ");
        displayQueue(q);
    }
    printf("Apakah queue kosong? %s\n\n", isEmpty(q) ? "Ya" : "Tidak");

    return 0;
}
