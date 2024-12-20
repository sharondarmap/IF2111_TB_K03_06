#include <stdio.h>
#include "cartadd.h"

void CartAdd(List *userList, IdxType currentIndex, ArrayDin barangList) {
    Barang currentBarang;
    int jumlah;
    User *currentUser = &userList->A[currentIndex];
    // CreateEmptyKeranjang(&userList->A[currentIndex].keranjang);

    // Validasi keranjang pengguna
    // printf("DEBUG: Validasi keranjang pengguna.\n");
    // if (currentUser->keranjang.Elements == NULL) {
    //     printf("DEBUG: Keranjang belum diinisialisasi. Menginisialisasi keranjang pengguna...\n");
    //     CreateEmptyKeranjang(&(currentUser->keranjang));
    //     printf("DEBUG: Keranjang berhasil diinisialisasi. Count: %d\n", currentUser->keranjang.Count);
    // }

    PrintWord(currentWord);
    printf("\n");
    Word words[100];
    int wordCount = 0;

    // Simpan seluruh kata
    while (!endWord) {
        words[wordCount] = currentWord;
        wordCount++;
        ADVWORD();
    }

    PrintWord(*words);

    if (wordCount < 2) {
        printf("Format command tidak valid!\n");
        return;
    }

    // Inisialisasi nama barang sebagai Word kosong
    Word namaBarang;
    ResetWord(&namaBarang);

    // Gabungkan semua kata kecuali kata terakhir untuk nama barang
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < words[i].Length; j++) {
            namaBarang.TabWord[namaBarang.Length++] = words[i].TabWord[j];
        }
        if (i < wordCount - 2) {
            namaBarang.TabWord[namaBarang.Length++] = ' ';
        }
    }

    // Kuantitas diambil dari kata terakhir input
    jumlah = WordToInt(words[wordCount - 1]);

    // Debugging: Mengecek nama barang yang telah dibentuk
    printf("DEBUG: Constructed name: ");
    PrintWord(namaBarang);
    printf("\n");

        // Debugging barangList
    printf("DEBUG: BarangList Neff: %d\n", barangList.Neff);
    for (int i = 0; i < barangList.Neff; i++) {
        printf("Barang %d: %s, Harga: %d\n", i + 1, barangList.A[i].name, barangList.A[i].price);
    }

    // Pencarian barang di barangList
    int found = 0;
    for (int i = 0; i < barangList.Neff; i++) {
        Word storeItemName = StringToWord(barangList.A[i].name);
        if (IsWordEqual(namaBarang, storeItemName)) {
            currentBarang.price = barangList.A[i].price;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("DEBUG: Barang ditemukan: %s dengan harga %d\n", currentBarang.name, currentBarang.price);
    } else {
        printf("[ERROR] Barang '%s' tidak ditemukan di toko.\n", WordToString(namaBarang));
        return;
    }

    // Salin nama barang ke currentBarang.name
    printf("DEBUG: Menyalin nama barang ke currentBarang.name.\n");
    CopyWordToCharArray(namaBarang, currentBarang.name);
    printf("DEBUG: Nama barang berhasil disalin: %s\n", currentBarang.name);

    // Validasi keranjang pengguna
    printf("DEBUG: Validasi keranjang pengguna.\n");
    printf("Keranjang count: %d\n", currentUser->keranjang.Count);
    if (currentUser->keranjang.Count < 0 || currentUser->keranjang.Count > MaxEl) {
        printf("[ERROR] Keranjang pengguna tidak valid atau belum diinisialisasi.\n");
        return;
    }
    printf("DEBUG: Keranjang valid.\n");

    // Tambahkan barang ke keranjang
    if (IsItemInKeranjang(currentUser->keranjang, currentBarang)) {
        printf("DEBUG: Barang sudah ada di keranjang.\n");
        int existingQuantity = GetItemQuantity(currentUser->keranjang, currentBarang);
        UpdateKeranjangItemQuantity(&(currentUser->keranjang), currentBarang, existingQuantity + jumlah);
    } else {
        printf("DEBUG: Barang belum ada di keranjang.\n");
        if (IsKeranjangFull(currentUser->keranjang)) {
            printf("[ERROR] Keranjang penuh! Tidak bisa menambah barang.\n");
            return;
        }
        printf("DEBUG: Keranjang belum penuh. Melanjutkan ke AddToKeranjang.\n");

        printf("DEBUG: Memanggil AddToKeranjang.\n");
        printf("Barang: %s, Harga: %d, Jumlah: %d\n", currentBarang.name, currentBarang.price, jumlah);

        AddToKeranjang(&(currentUser->keranjang), currentBarang, jumlah);

        printf("DEBUG: AddToKeranjang selesai dipanggil.\n");

    }

    printf("Berhasil menambahkan %d ", jumlah);
    PrintWord(namaBarang);
    printf(" ke keranjang belanja!\n");
}

