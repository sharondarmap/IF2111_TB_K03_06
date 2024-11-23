#include <stdio.h>
#include <stdbool.h>
#include "StoreRemove.h"

boolean RemoveLogic(ArrayDin *barangList, Word barangHapus) {
    boolean barangDitemukan;
    int i = 0;
    int j = 0;
    Barang currentBarang;

    for (int i = 0; i < barangList->Neff; i++) {
        // Membandingkan barang dalam daftar dengan barang yang akan dihapus
        if (IsWordEqual(TrimWord(StringToWord(barangList->A[i].name)), barangHapus)) {
            // Jika ditemukan, hapus barang
            DeleteAt(barangList, i);
            barangDitemukan = true;
            break;
        }
        else{
           barangDitemukan = false;
        }
    }
    return barangDitemukan;
}
void StoreRemove (ArrayDin *barangList) {
    printf("Nama barang yang akan dihapus: ");
    STARTKALIMAT();

    if (RemoveLogic(barangList,TrimWord(StringToWord(CLine.TabLine)))) {
        PrintWord (StringToWord(CLine.TabLine));
        printf("telah berhasil dihapus\n");
    }
    else {
        printf("Toko tidak menjual: ");
        PrintWord (StringToWord(CLine.TabLine));
    }
}
