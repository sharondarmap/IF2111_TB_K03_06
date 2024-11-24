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
    printf("   Fungsi: Memulai pekerjaan untuk mendapatkan uang.\n");
    printf("   Sistem akan memberikan daftar pekerjaan dengan\n");
    printf("   durasi dan pendapatan yang berbeda.\n")
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
    printf("   Fungsi: Menyelesaikan tantangan berbasis game untuk mendapatkan uang.\n");
    printf("   Pilihan Tantangan:\n");
    printf("     a) Tebak Angka (biaya=200)\n");
    printf("        Anda memiliki 10 kesempatan untuk menebak angka.\n");
    printf("        Feedback: Lebih kecil, lebih besar, atau tepat.\n");
    printf("        Jumlah kesempatan yang tersisa akan memengaruhi hadiah.\n");
    printf("     b) W0RDL3 (biaya=500)\n");
    printf("        Permainan tebak kata lima huruf dengan 5 peluang.\n");
    printf("        Kata valid harus diakui oleh sistem.\n");
    printf("        Huruf dengan posisi benar: ditampilkan biasa.\n");
    printf("        Huruf benar tapi posisi salah: diberi tanda *.\n");
    printf("        Huruf salah: diberi tanda %.\n");
    printf("   Contoh: WORK CHALLENGE\n");

    // WORLD33
    printf("9. WORLD3\n");
    printf("   Fungsi: Permainan tebak kata lima huruf dengan hadiah uang.\n");
    printf("   Biaya: 500 rupiah.\n");
    printf("   Anda memiliki 5 peluang untuk menebak kata yang benar.\n");
    printf("   Feedback berdasarkan huruf:\n");
    printf("     - Huruf dengan posisi benar: ditampilkan biasa.\n");
    printf("     - Huruf benar tapi posisi salah: diberi tanda '*'.\n");
    printf("     - Huruf salah: diberi tanda '%%'.\n");
    printf("   Contoh: W0RDL3\n");
    printf("     Tebak kata: SMART\n");
    printf("     Feedback: S M A * R\n");
    printf("     Tebak kata: START\n");
    printf("     Feedback: S T A R T\n");
    printf("     Anda menang! +1000 rupiah telah ditambahkan ke akun anda.\n");


    // TEBAK ANGKA
    printf("10. TEBAK ANGKA\n");
    printf("   Fungsi: Permainan tebak angka dengan hadiah uang.\n");
    printf("   Biaya: 200 rupiah.\n");
    printf("   Anda memiliki 10 kesempatan untuk menebak angka.\n");
    printf("   Feedback: Lebih kecil, lebih besar, atau tepat.\n");
    printf("   Hadiah tergantung pada jumlah kesempatan tersisa.\n");
    printf("   Contoh: TEBAK ANGKA\n");
    printf("     Tebak angka: 50\n");
    printf("     Tebakanmu lebih kecil!\n");
    printf("     Tebak angka: 62\n");
    printf("     Tebakanmu benar! +350 rupiah telah ditambahkan ke akun anda.\n");

    // BIO WEAPON
    printf("11. BIO WEAPON\n");
    printf("   Fungsi: Menambahkan senjata biologis ke sistem PURRMART.\n");
    printf("   Pemain diminta memasukkan DNA dan kode rahasia.\n");
    printf("   Jika valid, barang masuk ke antrian sistem; jika tidak, barang ditolak.\n");
    printf("   Contoh: BIO WEAPON\n");
}