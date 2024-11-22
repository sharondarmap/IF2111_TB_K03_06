#include "StoreSupply.h"
#include <stdio.h>

int main() {
    Queue barangQueue;
    ArrayDin barangList;

    CreateQueue(&barangQueue);
    barangList = MakeArrayDin();

    Barang barang1 = {"AK47", 0};
    Barang barang2 = {"M4A1", 0};
    enqueue(&barangQueue, barang1);
    enqueue(&barangQueue, barang2);

    printf("=== Simulasi StoreSupply ===\n");

    StoreSupply(&barangQueue, &barangList); // Proses barang pertama
    StoreSupply(&barangQueue, &barangList); // Proses baranag kedua

    printf("\n=== Daftar Barang di Toko ===\n");
    if (IsEmpty(barangList)) { 
        printf("Tidak ada barang di toko.\n");
    } else {
        for (int i = 0; i < Length(barangList); i++) {
            Barang item = Get(barangList, i);
            printf("%d. Nama: %s, Harga: %d\n", i + 1, item.name, item.price);
        }
    }
    PrintArrayDin(barangList);
    DeallocateArrayDin(&barangList);

    return 0;
}