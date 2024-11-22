#include "load.h"

boolean EndKalimat;  // Deklarasi variabel global
Kalimat CLine;
Kalimat CInput;
Kalimat CCommand;

void Load(char *filename, ArrayDin *daftarBarang, List *userList) {
    int jumlahBarang;

    // Buka file dan baca jumlah barang
    STARTKALIMATFILE(filename);
    jumlahBarang = atoi(CLine.TabLine);
    // printf("DEBUG: Jumlah barang yang akan dibaca = %d\n", jumlahBarang);

    // Inisialisasi arrayDin dan ListUser
    *daftarBarang = MakeArrayDin();
    *userList = MakeList();

    // Pindah ke baris pertama barang
    ADVKALIMAT();

    // Step 3: Loop untuk membaca barang
    for (int i = 0; i < jumlahBarang; i++) {
        // printf("\nDEBUG: Iterasi %d - Sebelum ADVKALIMAT\n", i + 1);

        // Debug baris yang akan diproses
        // printf("DEBUG: Baris yang akan diproses = '%s'\n", CLine.TabLine);

        // Parsing harga dan nama barang
        int harga;
        char nama[MAX_LEN];
        ParseBarang(CLine, &harga, nama);
        // printf("DEBUG: Harga barang = %d\n", harga);
        // printf("DEBUG: Nama barang = '%s'\n", nama);

        // Membuat elemen barang
        ElType2 barang;
        barang.price = harga;

        // Salin nama ke barang.name
        Word namaWord = StringToWord(nama);
        CopyWordToCharArray(namaWord, barang.name);

        // Tambahkan ke arrayDin
        InsertLast(daftarBarang, barang);
        // printf("DEBUG: Barang berhasil ditambahkan: {%s, %d}\n", barang.name, barang.price);

        // Pindah ke baris berikutnya
        ADVKALIMAT();
        // if (!EndKalimat) {
        //     printf("DEBUG: Baris berikutnya yang dibaca = '%s'\n", CLine.TabLine);
        // }
    }

    // Step 4: Membaca jumlah user
    // printf("\nDEBUG: Membaca jumlah user...\n");
    int jumlahUser = atoi(CLine.TabLine); // Konversi string ke integer
    // printf("DEBUG: Jumlah user yang akan dibaca = %d\n", jumlahUser);

    // Step 5: Membaca detail user
    // printf("\nDEBUG: Membaca detail user...\n");

    for (int i = 0; i < jumlahUser; i++) {
        ADVKALIMAT(); // Pindah ke baris berikutnya untuk setiap user

        // Parsing jumlah uang, nama user, dan password
        int jumlahUang;
        char namaUser[MAX_LEN];
        char password[MAX_LEN];
        ParseUser(CLine, &jumlahUang, namaUser, password);

        // printf("DEBUG: Jumlah uang = %d, Nama user = '%s', Password = '%s'\n", jumlahUang, namaUser, password);

        // Membuat elemen user
        User user;
        user.money = jumlahUang;

        // Salin nama user dan password
        Word namaUserWord = StringToWord(namaUser);
        Word passwordWord = StringToWord(password);
        CopyWordToCharArray(namaUserWord, user.name);
        CopyWordToCharArray(passwordWord, user.password);

        // Tambahkan ke List User
        InsertLastList(userList, user);
        // printf("DEBUG: User berhasil ditambahkan: {Nama: %s, Uang: %d, Password: %s}\n", user.name, user.money, user.password);
        
    }
}