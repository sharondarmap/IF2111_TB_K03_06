#include <stdio.h>
#include "save.h"
#include <string.h>

int main() {
    // Inisialisasi ADT Barang (ArrayDin)
    ArrayDin barang = MakeArrayDin();
    Barang barang1 = {"AK47", 100};
    Barang barang2 = {"Ayam Goreng", 50};
    InsertLast(&barang, barang1);
    InsertLast(&barang, barang2);

    // Debugging: Periksa data barang
    printf("Jumlah barang: %d\n", Length(barang));

    // Inisialisasi ADT Pengguna (List)
    List userList = MakeList();
    User u1 = {"Alice", "password123", 100000}; // User dengan nama, password, dan uang
    User u2 = {"Bob", "securePass", 75000};
    InsertLastList(&userList, u1);
    InsertLastList(&userList, u2);

    // Nama file untuk menyimpan data
    Word filename;
    filename.Length = 8;
    strcpy(filename.TabWord, "data.txt");

    // Memanggil fungsi Save
    Save(&barang, &userList, filename.TabWord);

    // Menampilkan hasil
    printf("Data berhasil disimpan ke file '%s'.\n", filename.TabWord);

    // Membersihkan memori
    DeallocateArrayDin(&barang);

    return 0;
}
