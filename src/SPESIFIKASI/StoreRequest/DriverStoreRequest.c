#include <stdio.h>
#include "StoreRequest.h"
#include "StoreRequest.c"
#include "../../ADT/List/arraydin.h"
#include "../../ADT/Queue/queue.h"

int main() {
    Queue barangQueue;
    CreateQueue(&barangQueue);

    ArrayDin barangToko = MakeArrayDin();

    Barang barang1 = {"Adaditoko", 10000};
    Barang barang2 = {"Pensil", 5000};
    InsertLast(&barangToko, barang1);
    InsertLast(&barangToko, barang2);

    printf("Barang di toko sebelum operasi:\n");
    for (int i = 0; i < barangToko.Neff; i++) {
        printf("- %s (Rp%d)\n", barangToko.A[i].name, barangToko.A[i].price);
    }

    printf("\n===== TEST STORE REQUEST =====\n");
    printf("Test Case 1: Memasukkan barang 'AK47' (baru)\n");
    StoreRequest(&barangQueue, &barangToko);

    printf("\nTest Case 2: Memasukkan barang 'Adaditoko' (sudah ada di toko)\n");
    StoreRequest(&barangQueue, &barangToko);

    printf("\nTest Case 3: Memasukkan barang 'AK47' (sudah ada di antrian)\n");
    StoreRequest(&barangQueue, &barangToko);

    printf("\nTest Case 4: Memasukkan barang 'Keyboard' (baru)\n");
    StoreRequest(&barangQueue, &barangToko);

    printf("\nAntrian barang setelah operasi:\n");
    displayQueue(barangQueue);

    DeallocateArrayDin(&barangToko);

    return 0;
}