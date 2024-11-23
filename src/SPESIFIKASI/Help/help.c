#include "help.h"
#include <stdio.h>

void DisplayHelp() {
    printf("==================================================\n");
    printf("                PANDUAN PENGGUNAAN PROGRAM        \n");
    printf("==================================================\n");
    printf("Program ini merupakan sistem simulasi berbasis CLI\n");
    printf("dengan fitur manajemen data pengguna, permintaan,\n");
    printf("dan penyimpanan ke dalam folder DATA.\n");
    printf("\nBerikut adalah daftar perintah yang tersedia:\n");

    // LOAD
    printf("1. LOAD <filename>\n");
    printf("   Fungsi: Memuat data dari file <filename> ke dalam sistem.\n");
    printf("   Contoh: LOAD data.txt\n");

    // SAVE
    printf("2. SAVE <filename>\n");
    printf("   Fungsi: Menyimpan data sistem ke file <filename> di folder DATA.\n");
    printf("   Contoh: SAVE hasil_sistem.txt\n");

    // REGISTER
    printf("3. REGISTER\n");
    printf("   Fungsi: Mendaftarkan pengguna baru ke dalam sistem.\n");
    printf("   Pengguna akan diminta untuk memasukkan nama, password,\n");
    printf("   dan informasi lainnya sesuai dengan spesifikasi sistem.\n");
    printf("   Contoh: Ketik REGISTER lalu ikuti petunjuk.\n");

    // WORK
    printf("4. WORK\n");
    printf("   Fungsi: Menjalankan simulasi pekerjaan berdasarkan data permintaan.\n");
    printf("   Sistem akan memproses pekerjaan yang ada pada daftar kerja.\n");
    printf("   Contoh: Ketik WORK untuk memulai simulasi kerja.\n");

    // STORELIST
    printf("5. STORELIST\n");
    printf("   Fungsi: Menampilkan daftar barang dan stok yang tersedia di sistem.\n");
    printf("   Contoh: Ketik STORELIST untuk melihat daftar barang.\n");

    // STOREREQUEST
    printf("6. STOREREQUEST <barang> <jumlah>\n");
    printf("   Fungsi: Menambahkan permintaan barang tertentu ke dalam sistem.\n");
    printf("   Sistem akan memeriksa ketersediaan stok dan menyimpan permintaan.\n");
    printf("   Contoh: STOREREQUEST Sabun 5\n");

    // EXIT
    printf("7. EXIT\n");
    printf("   Fungsi: Keluar dari program.\n");
    printf("   Contoh: Ketik EXIT.\n");

    printf("==================================================\n");
    printf("          TERIMA KASIH TELAH MENGGUNAKAN PROGRAM! \n");
    printf("==================================================\n");
}
