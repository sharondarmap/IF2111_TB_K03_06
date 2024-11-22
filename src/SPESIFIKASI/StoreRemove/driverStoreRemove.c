#include <stdio.h>
#include "StoreRemove.h"

int main() {
    // Inisialisasi daftar barang
    ArrayDin barangList;
    barangList = MakeArrayDin(); // Maksimum kapasitas 10

    // Menambahkan beberapa barang ke daftar
    Barang barang1 = {"Apel", 4};
    Barang barang2 = {"Jeruk", 5};
    Barang barang3 = {"Mangga", 6};
    InsertLast(&barangList, barang1);
    InsertLast(&barangList, barang2);
    InsertLast(&barangList, barang3);

    printf("Daftar barang sebelum penghapusan:\n");
        PrintArrayDin(barangList);
        printf("\n");

    // Input barang yang akan dihapus

    // Panggil fungsi StoreRemove untuk menghapus barang
    StoreRemove(&barangList);
    PrintArrayDin(barangList);

    // // Tampilkan daftar barang setelah penghapusan
    // printf("\nDaftar barang setelah penghapusan:\n");
    //     PrintArrayDin(barangList);
    //     printf("\n");

    // Dealokasi array dinamis
    DeallocateArrayDin(&barangList);

    return 0;
}