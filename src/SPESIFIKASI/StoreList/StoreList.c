#include <stdio.h>
#include <stdlib.h>
#include "StoreList.h"

void StoreList(ArrayDin *barangList){
    if (IsEmpty(*barangList)){
        printf("TOKO KOSONG\n");
    }

    else{
        Word displayed[100]; // Array untuk menyimpan barang yang sudah ditampilkan
        int displayedCount = 0;

            for (int i = 0; i < (*barangList).Neff; i++) {
                boolean isUnique = true; 
                
                // Periksa apakah barang sudah pernah ditampilkan
                for (int j = 0; j < displayedCount; j++) {
                    if (IsWordEqual(StringToWord((*barangList).A[i].name), displayed[j])){
                        isUnique = false;
                        break;
                    }
                }
            if (isUnique){
                printf("- %s\n", (*barangList).A[i].name);
                displayed[displayedCount] = StringToWord((*barangList).A[i].name);  // Tambahkan barang ke daftar yang sudah ditampilkan
                displayedCount++;
                //char* namaBarang = WordToString((*barangList).A[i].TabWord);
                //printf("- %s\n", namaBarang);
            }
            
        }
    }
}