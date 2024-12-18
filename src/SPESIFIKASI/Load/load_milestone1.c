#include "load.h"

void Load(char *filename, ArrayDin *daftarBarang, List *userList) {
    // Buka file dan baca jumlah barang
    STARTKALIMATFILE(filename);

    // Cek apakah file berhasil dibuka
    if (EndKalimat) { // Jika file tidak valid
        // printf("Gagal membuka file. Pastikan file tersedia dan formatnya benar.\n");
        return; // Keluar dari fungsi jika file tidak valid
    }

    // Baca jumlah barang dari file
    int jumlahBarang = atoi(CLine.TabLine); // Konversi string ke integer
    // printf("[DEBUG] Jumlah barang yang akan dibaca: %d\n", jumlahBarang);

    // Inisialisasi arrayDin dan ListUser
    *daftarBarang = MakeArrayDin();
    *userList = MakeList();

    // Pindah ke baris pertama barang
    ADVKALIMAT();

    // Loop untuk membaca barang
    for (int i = 0; i < jumlahBarang; i++) {
        if (EndKalimat) { // Jika EOF tercapai lebih awal
            // printf("ERROR: Data barang tidak lengkap.\n");
            return; // Keluar dari fungsi jika data barang tidak lengkap
        }

        // Parsing harga dan nama barang
        int harga;
        char nama[MAX_LEN];
        ParseBarang(CLine, &harga, nama);

        // Membuat elemen barang
        ElType2 barang;
        barang.price = harga;

        // Salin nama ke barang.name
        Word namaWord = StringToWord(nama);
        CopyWordToCharArray(namaWord, barang.name);

        // Tambahkan ke arrayDin
        InsertLast(daftarBarang, barang);
        // printf("[DEBUG] Barang ke-%d berhasil ditambahkan: {Nama: %s, Harga: %d}\n", i + 1, barang.name, barang.price);

        // Pindah ke baris berikutnya
        ADVKALIMAT();
    }

    // Membaca jumlah user dari file
    int jumlahUser = atoi(CLine.TabLine); // Konversi string ke integer
    // printf("[DEBUG] Jumlah user yang akan dibaca: %d\n", jumlahUser);

    // Loop untuk membaca detail user
    for (int i = 0; i < jumlahUser; i++) {
        ADVKALIMAT(); // Pindah ke baris berikutnya untuk setiap user

        if (EndKalimat) { // Jika EOF tercapai lebih awal
            // printf("ERROR: Data pengguna tidak lengkap.\n");
            return; // Keluar dari fungsi jika data pengguna tidak lengkap
        }

        // Parsing jumlah uang, nama user, dan password
        int jumlahUang;
        char namaUser[MAX_LEN];
        char password[MAX_LEN];
        ParseUser(CLine, &jumlahUang, namaUser, password);

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
        // printf("[DEBUG] User ke-%d berhasil ditambahkan: {Nama: %s, Uang: %d, Password: %s}\n", i + 1, user.name, user.money, password);
    }

    // printf("[DEBUG] File berhasil dimuat: %s\n", filename);
}
