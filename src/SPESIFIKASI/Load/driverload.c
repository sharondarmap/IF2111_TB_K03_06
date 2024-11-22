#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "load.h"

int main() {
    ArrayDin daftarBarang;
    List userList;
    char filename[MAX_LEN];

    printf("Masukkan nama file konfigurasi: ");
    
    // Menggunakan Mesin Kata untuk membaca input nama file
    STARTWORD();
    for (int i = 0; i < currentWord.Length; i++) {
        filename[i] = currentWord.TabWord[i];
    }
    filename[currentWord.Length] = '\0'; // Tambahkan null-terminator

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
