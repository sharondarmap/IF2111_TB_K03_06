#include <stdio.h>
#include <stdbool.h>
#include "src/ADT/MesinKata/mesinkata.h"
#include "src/ADT/List/arraydin.h"

boolean RemoveLogic(ArrayDin *barangList, Word barangHapus) {
    boolean barangDitemukan = false;
    int i = 0;
    int j = 0;
    Word currentBarang;

    while (i<Length) {
        currentBarang.Length = 0;
        while (j<barangList->Neff) {
        currentBarang.TabWord[i] = barangList[i].A->name[j];
        currentBarang.Length++;
        i++;
        }
        j++;
    }
    // Mencari barang dalam daftar
    for (int i = 0; i < barangList->Neff; i++) {
        // Membandingkan barang dalam daftar dengan barang yang akan dihapus
        if (IsWordEqual(currentBarang, barangHapus)) {
            // Jika ditemukan, hapus barang
            DeleteAt(barangList, i);
            barangDitemukan = true;
            break;
        }
    }
    return barangDitemukan;
}
void StoreRemove (ArrayDin *barangList) {
    ADVWORD();
    printf("Nama barang yang akan dihapus:");
    boolean barangDitemukan = RemoveLogic(barangList,currentWord);
    if (barangDitemukan) {
        prinf(" telah berhasil dihapus.");
    }
    else {
        printf("Toko tidak menjual ");
        PrintWord (currentWord);
    }
}