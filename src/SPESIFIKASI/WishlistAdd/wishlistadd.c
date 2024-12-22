#include <stdio.h>
#include "wishlistadd.h"

// // Tambahkan barang ke wishlist
// void WishlistAdd(List *userList, IdxType currentIndex, ArrayDin barangList) {
//     char namaBarang[MAX_LEN];

//     // Membaca nama barang menggunakan mesin kata
//     printf("Masukkan nama barang: ");
//     STARTWORD();
//     CopyWordToCharArray(currentWord, namaBarang); // Konversi Word ke char array

//     // Cari barang di toko
//     int found = 0;
//     Barang barangToAdd;
//     for (int i = 0; i < jumlahBarangToko; i++) {
//         int j = 0;
//         int isSame = 1; // Flag untuk membandingkan nama barang
//         while (barangToko[i].name[j] != '\0' && namaBarang[j] != '\0') {
//             if (barangToko[i].name[j] != namaBarang[j]) {
//                 isSame = 0;
//                 break;
//             }
//             j++;
//         }
//         if (barangToko[i].name[j] != namaBarang[j]) { // Panjang nama berbeda
//             isSame = 0;
//         }

//         if (isSame) {
//             barangToAdd = barangToko[i];
//             found = 1;
//             break;
//         }
//     }

//     if (!found) {
//         printf("Tidak ada barang dengan nama %s!\n", namaBarang);
//         return;
//     }

//     // Cek apakah barang sudah ada di wishlist (logika langsung di sini)
//     addr_listdp current = First(user->wishList);
//     while (current != NIL) {
//         int j = 0;
//         int isSame = 1; // Flag untuk membandingkan nama barang
//         while (Wish(current).name[j] != '\0' && namaBarang[j] != '\0') {
//             if (Wish(current).name[j] != namaBarang[j]) {
//                 isSame = 0;
//                 break;
//             }
//             j++;
//         }
//         if (Wish(current).name[j] != namaBarang[j]) { // Panjang nama berbeda
//             isSame = 0;
//         }

//         if (isSame) {
//             printf("%s sudah ada di wishlist!\n", namaBarang);
//             return;
//         }
//         current = Next(current);
//     }

//     // Tambahkan barang ke wishlist
//     addr_listdp newNode = AlokasiWishList(barangToAdd);
//     if (newNode != NIL) {
//         if (WishlistIsEmpty(user->wishList)) {
//             First(user->wishList) = newNode;
//             Last(user->wishList) = newNode;
//         } else {
//             Next(Last(user->wishList)) = newNode;
//             Prev(newNode) = Last(user->wishList);
//             Last(user->wishList) = newNode;
//         }
//         Count(user->wishList)++;
//         printf("Berhasil menambahkan %s ke wishlist!\n", namaBarang);
//     } else {
//         printf("Gagal menambahkan barang ke wishlist, memori penuh!\n");
//     }
// }

void WishlistAdd(List *userList, IdxType currentIndex, ArrayDin barangList) {
    Barang barangToAdd;
    User *currentUser = &userList->A[currentIndex];

    // Meminta input nama barang untuk ditambahkan ke wishlist
    printf("Masukkan nama barang: ");
    STARTWORD();
    Word words[100];
    int wordCount = 0;

    // Simpan seluruh kata
    while (!endWord) {
        words[wordCount] = currentWord;
        wordCount++;
        ADVWORD();
    }

    // PrintWord(*words);

    if (wordCount < 1) {
        printf("Format command tidak valid!\n");
        return;
    }

    // Inisialisasi nama barang sebagai Word kosong
    Word namaBarang;
    ResetWord(&namaBarang);

    // Gabungkan semua kata kecuali kata terakhir untuk nama barang
    for (int i = 0; i < wordCount; i++) {
        for (int j = 0; j < words[i].Length; j++) {
            namaBarang.TabWord[namaBarang.Length++] = words[i].TabWord[j];
        }
        if (i < wordCount - 1) {
            namaBarang.TabWord[namaBarang.Length++] = ' ';
        }
    }

    // Pencarian barang di barangList
    int found = 0;
    for (int i = 0; i < barangList.Neff; i++) {
        Word storeItemName = StringToWord(barangList.A[i].name);
        if (IsWordEqual(namaBarang, storeItemName)) {
            barangToAdd = barangList.A[i];
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Tidak ada barang dengan nama '%s' di toko!\n", WordToString(namaBarang));
        return;
    }

    // Cek apakah barang sudah ada di wishlist
    addr_listdp current = First(currentUser->wishList);
    while (current != NIL) {
        Word wishlistItemName = StringToWord(Wish(current).name);
        if (IsWordEqual(namaBarang, wishlistItemName)) {
            printf("%s sudah ada di wishlist!\n", WordToString(namaBarang));
            return;
        }
        current = Next(current);
    }

    // Tambahkan barang ke wishlist
    addr_listdp newNode = AlokasiWishList(barangToAdd);
    if (newNode != NIL) {
        if (WishlistIsEmpty(currentUser->wishList)) {
            First(currentUser->wishList) = newNode;
            Last(currentUser->wishList) = newNode;
        } else {
            Next(Last(currentUser->wishList)) = newNode;
            Prev(newNode) = Last(currentUser->wishList);
            Last(currentUser->wishList) = newNode;
        }
        Count(currentUser->wishList)++;
        printf("Berhasil menambahkan %s ke wishlist!\n", WordToString(namaBarang));
    } else {
        printf("Gagal menambahkan barang ke wishlist, memori penuh!\n");
    }
}