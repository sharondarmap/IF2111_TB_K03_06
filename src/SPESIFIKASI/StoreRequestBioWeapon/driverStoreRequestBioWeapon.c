#include <stdio.h>
#include "StoreRequestBioWeapon.h"

int main() {
    // Inisialisasi Queue dan ArrayDin
    Queue barangQueue;
    CreateQueue(&barangQueue);

    ArrayDin barangList = MakeArrayDin(); // ArrayDin kosong dengan ukuran awal

    // Simulasi menambahkan barang di toko (ArrayDin)
    Barang existingBarang;

    // Mengisi nama barang menggunakan ADT Word
    Word namaBarang = StringToWord("Batuksius");
    for (int i = 0; i < namaBarang.Length; i++) {
        existingBarang.name[i] = namaBarang.TabWord[i];
    }
    existingBarang.name[namaBarang.Length] = '\0'; // Null-terminator
    existingBarang.price = 1000;

    InsertLast(&barangList, existingBarang); // Tambahkan ke ArrayDin

    // Tampilkan kondisi awal
    printf("Barang di toko (ArrayDin):\n");
    for (int i = 0; i < barangList.Neff; i++) {
        PrintBarang(barangList.A[i]);
    }

    printf("\nBarang di antrian (Queue):\n");
    displayQueue(barangQueue);

    // Panggil StoreRequestBioWeapon
    printf("\n=== Simulasi StoreRequestBioWeapon ===\n");
    StoreRequestBioWeapon(&barangQueue, &barangList);

    // Tampilkan kondisi akhir
    printf("\nBarang di antrian (Queue) setelah StoreRequestBioWeapon:\n");
    displayQueue(barangQueue);

    // Dealokasi memori ArrayDin
    DeallocateArrayDin(&barangList);

    return 0;
}
