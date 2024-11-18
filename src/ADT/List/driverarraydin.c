#include <stdio.h>
#include "arraydin.h"
#include "arraydin.c"

int main() {
    printf("=== DRIVER ARRAYDIN ===\n\n");

    // 1. Membuat ArrayDin
    printf("[TEST: MakeArrayDin]\n");
    ArrayDin arr = MakeArrayDin();
    printf("ArrayDin berhasil dibuat dengan kapasitas awal: %d\n\n", GetCapacity(arr));

    // 2. Menambahkan elemen ke ArrayDin
    printf("[TEST: InsertLast]\n");
    ElType2 barang1 = {"Laptop", 10000};
    ElType2 barang2 = {"Mouse", 5000};
    ElType2 barang3 = {"Keyboard", 7500};

    InsertLast(&arr, barang1);
    InsertLast(&arr, barang2);
    InsertLast(&arr, barang3);
    printf("Setelah menambahkan elemen:\n");
    PrintArrayDin(arr);
    printf("\n");

    // 3. Menambahkan elemen di posisi tertentu
    printf("[TEST: InsertAt]\n");
    ElType2 barang4 = {"Monitor", 15000};
    InsertAt(&arr, barang4, 1); // Menambahkan di indeks 1
    printf("Setelah menambahkan elemen di indeks 1:\n");
    PrintArrayDin(arr);
    printf("\n");

    // 4. Menghapus elemen pertama
    printf("[TEST: DeleteFirst]\n");
    DeleteFirst(&arr);
    printf("Setelah menghapus elemen pertama:\n");
    PrintArrayDin(arr);
    printf("\n");

    // 5. Menghapus elemen terakhir
    printf("[TEST: DeleteLast]\n");
    DeleteLast(&arr);
    printf("Setelah menghapus elemen terakhir:\n");
    PrintArrayDin(arr);
    printf("\n");

    // 6. Menghapus elemen di indeks tertentu
    printf("[TEST: DeleteAt]\n");
    DeleteAt(&arr, 1); // Menghapus elemen di indeks 1
    printf("Setelah menghapus elemen di indeks 1:\n");
    PrintArrayDin(arr);
    printf("\n");

    // 7. Melakukan search elemen
    printf("[TEST: SearchArrayDin]\n");
    int idx = SearchArrayDin(arr, barang4);
    if (idx != -1) {
        printf("Barang ditemukan di indeks: %d\n", idx);
    } else {
        printf("Barang tidak ditemukan.\n");
    }
    printf("\n");

    // 8. Melakukan copy ArrayDin
    printf("[TEST: CopyArrayDin]\n");
    ArrayDin copyArr = CopyArrayDin(arr);
    printf("Array hasil copy:\n");
    PrintArrayDin(copyArr);
    printf("\n");

    // 9. Melakukan reverse ArrayDin
    printf("[TEST: ReverseArrayDin]\n");
    ReverseArrayDin(&arr);
    printf("Setelah melakukan reverse:\n");
    PrintArrayDin(arr);
    printf("\n");

    // 10. Menampilkan elemen dan kapasitas
    printf("[TEST: GetCapacity dan Get]\n");
    printf("Kapasitas ArrayDin: %d\n", GetCapacity(arr));
    printf("Elemen pertama: ");
    PrintElType(Get(arr, 0));
    printf("\n\n");

    // 11. Menghapus memori
    printf("[TEST: DeallocateArrayDin]\n");
    DeallocateArrayDin(&arr);
    printf("Memori ArrayDin berhasil dibebaskan.\n");

    return 0;
}
