#include <stdio.h>
#include <stdlib.h>

#include "load.h"
#include "load.c"


int main() {
    char filename[] = "dummy.txt";
    ArrayDin daftarBarang;
    List userList;

    // Panggil fungsi Load
    Load(filename, &daftarBarang, &userList);

    // Tampilkan hasil
    printf("\nDaftar Barang di Toko:\n");
    PrintArrayDin(daftarBarang);

    printf("\nDaftar User:\n");
    PrintList(userList);

    // Dealokasi array
    DeallocateArrayDin(&daftarBarang);

    return 0;
}