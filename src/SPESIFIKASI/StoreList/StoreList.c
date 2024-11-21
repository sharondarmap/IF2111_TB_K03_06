#include <stdio.h>
#include <stdlib.h>
#include "StoreList.h"

void StoreList(ArrayDin *barangList){
    if (IsEmpty(*barangList)){
        printf("TOKO KOSONG\n");
    }
    else{
        Word displayed[100];
        int displayedCount = 0;
            for (int i = 0; i < (*barangList).Neff; i++) {
                boolean isUnique = true; 
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
            }
            
        }
    }
}
