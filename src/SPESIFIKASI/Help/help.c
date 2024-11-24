#include "help.h"
#include <stdio.h>

void DisplayHelp1() {
    printf("==================================================\n");
    printf("                PANDUAN PENGGUNAAN PROGRAM        \n");
    printf("==================================================\n");
    printf("Program ini merupakan sistem simulasi berbasis CLI\n");
    printf("dengan fitur manajemen data pengguna, permintaan,\n");
    printf("dan penyimpanan ke dalam folder DATA.\n");
    printf("\nBerikut adalah daftar perintah yang tersedia:\n");

    // START
    printf("1. START\n");
    printf("   Fungsi: Memulai program dengan inisialisasi data awal.\n");
    printf("   Contoh: START\n");

    // LOAD
    printf("2. LOAD <filename>\n");
    printf("   Fungsi: Memuat data dari file <filename> ke dalam sistem.\n");
    printf("   Contoh: LOAD data.txt\n");
}

void DisplayHelp2(){
     // REGISTER
    printf("1. REGISTER\n");
    printf("   Fungsi: Mendaftarkan pengguna baru ke dalam sistem.\n");
    printf("   Pengguna akan diminta untuk memasukkan nama dan password,\n");
    printf("   Contoh: Ketik REGISTER lalu ikuti petunjuk.\n");

    // LOGIN
    printf("2. LOGIN <username> <password>\n");
    printf("   Fungsi: Login ke sistem menggunakan username dan password.\n");
    printf("   Setelah login, pengguna dapat mengakses fitur sistem.\n");
    printf("   Contoh: LOGIN Alice password123\n");
}

void DisplayHelp3(){
    // SAVE
    printf("1. SAVE <filename>\n");
    printf("   Fungsi: Menyimpan data sistem ke file <filename> di folder DATA.\n");
    printf("   Contoh: SAVE hasil_sistem.txt\n");

    // EXIT
    printf("2. EXIT\n");
    printf("   Fungsi: Keluar dari program.\n");
    printf("   Contoh: Ketik EXIT.\n");

    // WORK
    printf("3. WORK\n");
    printf("   Fungsi: Menjalankan simulasi pekerjaan berdasarkan data permintaan.\n");
    printf("   Sistem akan memproses pekerjaan yang ada pada daftar kerja.\n");
    printf("   Contoh: Ketik WORK untuk memulai simulasi kerja.\n");

    // STORELIST
    printf("4. STORELIST\n");
    printf("   Fungsi: Menampilkan daftar barang dan stok yang tersedia di sistem.\n");
    printf("   Contoh: Ketik STORELIST untuk melihat daftar barang.\n");

    // STOREREQUEST
    printf("5. STOREREQUEST <barang> <jumlah>\n");
    printf("   Fungsi: Menambahkan permintaan barang tertentu ke dalam sistem.\n");
    printf("   Sistem akan memeriksa ketersediaan stok dan menyimpan permintaan.\n");
    printf("   Contoh: STOREREQUEST Sabun 5\n");

    // STORE SUPPLY
    printf("6. STORE SUPPLY <barang> <jumlah>\n");
    printf("   Fungsi: Menambahkan stok barang ke dalam sistem.\n");
    printf("   Contoh: STORE SUPPLY Sabun 10\n");

    // STORE REMOVE
    printf("7. STORE REMOVE <barang>\n");
    printf("   Fungsi: Menghapus barang dari stok sistem.\n");
    printf("   Contoh: STORE REMOVE Sabun\n");

    // WORK CHALLENGE
    printf("8. WORK CHALLENGE\n");
    printf("   Fungsi: Menghadapi tantangan kerja dalam sistem simulasi.\n");
    printf("   Contoh: WORK CHALLENGE\n");

    // WORLD33
    printf("9. WORLD33\n");
    printf("    Fungsi: Memulai eksplorasi dunia tertentu dalam sistem simulasi.\n");
    printf("    Contoh: WORLD33\n");

    // TEBAK ANGKA
    printf("10. TEBAK ANGKA\n");
    printf("    Fungsi: Bermain game tebak angka sederhana.\n");
    printf("    Sistem akan meminta Anda menebak angka dari 1 sampai 100.\n");
    printf("    Contoh: TEBAK ANGKA\n");
}