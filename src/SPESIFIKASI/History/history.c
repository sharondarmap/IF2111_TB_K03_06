#include <stdio.h>
#include "history.h"

void history(List *userList, IdxType idxUser) {
    User *currentUser = &userList->A[idxUser];
    Stack riwayat = currentUser->riwayat_pembelian;

    printf("Masukkan jumlah history yang akan ditampilkan: ");
    STARTWORD();
    int jumlah = WordToInt(currentWord);

    // Cek apakah stack kosong
    if (IsEmptyStack(riwayat)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    printf("Riwayat pembelian barang:\n");
    printf("+----------------------+-------------+\n");
    printf("|     Nama Barang      | Total Harga |\n");
    printf("+----------------------+-------------+\n");

    // Tentukan jumlah riwayat yang akan ditampilkan
    int totalRiwayat = riwayat.TOP + 1;
    int displayCount;

    if (jumlah <= totalRiwayat){
        displayCount = jumlah;
    } else if (jumlah > totalRiwayat){
        displayCount = totalRiwayat;
    }

    for (int i = 0; i < displayCount; i++) { //dari paling baru (TOP) ke paling lama
        Barang barang = riwayat.T[riwayat.TOP - i];
        printf("| %-20s | %-11d |\n", barang.name, barang.price);
    }

    printf("+----------------------+-------------+\n");
}
