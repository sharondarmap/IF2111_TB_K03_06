#include <stdio.h>
#include "StoreSupply.h"


void StoreSupply(Queue *barangQueue, ArrayDin *barangList) {
    if (isEmpty(*barangQueue)) {
        printf("Tidak ada barang dalam antrian untuk diproses.\n");
        return;
    }

    Barang barang;
    dequeue(barangQueue, &barang); 

    printf("Apakah kamu ingin menambahkan barang %s?: ", barang.name);
    STARTWORD();
    printf("\n");
    
    Word kata = currentWord;
    boolean isAdded = false;

    if (IsWordEqual(StringToWord("Terima"), kata)) {
        int harga = 0;
        boolean isValid = false;

        // Validasi harga
        while (!isValid) {
            printf("Harga barang: ");
            STARTWORD(); 
            printf("\n");
            harga = 0;
            isValid = true;
            for (int i = 0; i < currentWord.Length; i++) {
                if (currentWord.TabWord[i] < '0' || currentWord.TabWord[i] > '9') {
                    isValid = false;
                    break;
                }
                harga = harga * 10 + (currentWord.TabWord[i] - '0');
            }
            if (!isValid || harga <= 0) {
                printf("Harga tidak valid. Masukkan angka yang lebih dari 0.\n");
                isValid = false;
            }
        }
    }

    // ---------------------------------------------------------"Tunda"------------------------------------------------------------------
    if (IsWordEqual(StringToWord("Tunda"), kata)) {
        enqueue(barangQueue, barang); 
        printf("%s dikembalikan ke antrian.\n", barang.name);
    }
    // ---------------------------------------------------------"Tolak"------------------------------------------------------------------
    if (IsWordEqual(StringToWord("Tolak"), kata)) {
        printf("%s telah dihapus dari antrian.\n", barang.name);
    }
    // ---------------------------------------------------------"Tidak Valid"-------------------------------------------------------------
    if ((!IsWordEqual(StringToWord("Terima"), kata)) && (!IsWordEqual(StringToWord("Tunda"), kata)) && (!IsWordEqual(StringToWord("Tolak"), kata))) {
        enqueue(barangQueue, barang); 
        printf("Perintah tidak valid.\n", barang.name);
    }
}


