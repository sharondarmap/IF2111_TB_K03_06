#include <stdio.h>
#include "StoreRequest.h"
#include "../../boolean.h"


void StoreRequest(Queue *barangQueue, ArrayDin *barangList) {
    printf("Nama barang yang diminta: ");
    STARTWORD(); 
    Word namaBarang = currentWord; 
    boolean isInStore = false; 
    boolean isInQueue = false; 

    for (int i = 0; i < (*barangList).Neff; i++) {
        Word barangListName = StringToWord((*barangList).A[i].name);
        if (IsWordEqual(barangListName, namaBarang)) {
            isInStore = true;
            break; 
        }
    }

    if (!isInStore) { 
        if (!isEmpty(*barangQueue)) {
            int queueLen = length(*barangQueue);
            for (int i = 0; i < queueLen; i++) {
                Barang tempBarang;
                dequeue(barangQueue, &tempBarang);
                Word queueName = StringToWord(tempBarang.name);
                enqueue(barangQueue, tempBarang); 
                if (IsWordEqual(queueName, namaBarang)) {
                    isInQueue = true;
                }
            }
        }
    }

    if (isInStore) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    }

    if (!isInStore && isInQueue) {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
    }

    if (!isInStore && !isInQueue) {
        Barang newBarang;
        char *barangName = WordToString(namaBarang); 
        for (int i = 0; i < namaBarang.Length; i++) {
            newBarang.name[i] = barangName[i];
        }
        newBarang.name[namaBarang.Length] = '\0'; 
        newBarang.price = 0; 
        enqueue(barangQueue, newBarang);
        /*
        printf("Barang berhasil dimasukkan ke antrian.\n");
        printf("Antrian saat ini:\n");
        displayQueue(*barangQueue);
        */
    }
}

