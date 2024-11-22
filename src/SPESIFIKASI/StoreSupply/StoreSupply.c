#include <stdio.h>
#include "StoreSupply.h"


void StoreSupply(Queue *barangQueue, ArrayDin *barangList) {
    if (isEmpty(*barangQueue)) {
        printf("Tidak ada barang dalam antrian untuk diproses.\n");
        return;
    }
    Barang barang;
    dequeue(barangQueue, &barang); 
    boolean validCommand = false; 
    Word kata;

    while (!validCommand) {
        printf("Apakah kamu ingin menambahkan barang %s? (Terima, Tolak, Tunda): ", barang.name);
        STARTWORD(); 
        printf("\n");
        kata = currentWord;
    // ---------------------------------------------------------"Terima"------------------------------------------------------------------
        if (IsWordEqual(StringToWord("Terima"), kata)) {
            validCommand = true;
            int harga = 0;
            boolean isValid = false;
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
                    isValid=false;
                }
            }

            barang.price = harga;
            InsertLast(barangList, barang);
            printf("%s dengan harga %d telah ditambahkan ke toko.\n", barang.name, barang.price);
        } 
    // ---------------------------------------------------------"Tunda"------------------------------------------------------------------        
        else if (IsWordEqual(StringToWord("Tunda"), kata)) {
            validCommand = true;
            enqueue(barangQueue, barang); 
            printf("%s dikembalikan ke antrian.\n", barang.name);
        } 
    // ---------------------------------------------------------"Tolak"------------------------------------------------------------------
        else if (IsWordEqual(StringToWord("Tolak"), kata)) {
            validCommand = true;
            printf("%s telah dihapus dari antrian.\n", barang.name);
        } 
    // ---------------------------------------------------------"Tidak Valid"-------------------------------------------------------------
        else {
            printf("Perintah tidak valid. Masukkan perintah yang valid (Terima, Tunda, Tolak).\n");
        }
    }
}
