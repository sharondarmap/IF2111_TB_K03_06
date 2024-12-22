#include "help.h"
#include <stdio.h>

void DisplayHelp1() {
    printf("==============================================\n");
    printf("          PANDUAN PENGGUNAAN PROGRAM          \n");
    printf("==============================================\n");
    // START
    printf("1. START\n");
    printf("   Fungsi: Untuk masuk ke sesi baru.\n");
    printf("   Contoh: Ketik START untuk memulai.\n");

    // LOAD
    printf("2. LOAD\n");
    printf("   Fungsi: Memulai sesi berdasarkan file konfigurasi <filename>.\n");
    printf("   Contoh: LOAD\n");

    // QUIT
    printf("3. QUIT\n");
    printf("   Fungsi: Keluar dari program.\n");
    printf("   Contoh: QUIT\n");

}

void DisplayHelp2() {
    printf("==============================================\n");
    printf("          PANDUAN PENGGUNAAN PROGRAM          \n");
    printf("==============================================\n");
    // REGISTER
    printf("1. REGISTER\n");
    printf("   Fungsi: Untuk melakukan pendaftaran akun baru.\n");
    printf("   Contoh: Ketik REGISTER untuk memulai pendaftaran.\n");

    // LOGIN
    printf("2. LOGIN\n");
    printf("   Fungsi: Untuk masuk ke dalam akun dan memulai sesi.\n");
    printf("   Contoh: LOGIN untuk autentikasi akun.\n");

    // QUIT
    printf("3. QUIT\n");
    printf("   Fungsi: Keluar dari program.\n");
    printf("   Contoh: QUIT\n");

}

void DisplayHelp3() {
    printf("============================================================\n");
    printf("                  PANDUAN PENGGUNAAN PROGRAM                \n");
    printf("============================================================\n");

    // PROFILE
    printf("1. PROFILE\n");
    printf("   Fungsi: Untuk melihat data diri pengguna.\n");
    printf("   Contoh: Ketik PROFILE menampilkan nama dan saldo pengguna.\n");

    // CART ADD
    printf("2. CART ADD\n");
    printf("   Fungsi: Untuk menambah barang sejumlah kuantitas tertentu dari keranjang belanja.\n");
    printf("   Contoh: Ketik CART ADD <nama barang di toko> <kuantitas>.\n");

    // CART REMOVE
    printf("2. CART REMOVE\n");
    printf("   Fungsi: Untuk mengurangi barang sejumlah kuantitas tertentu dari keranjang belanja.\n");
    printf("   Contoh: Ketik CART REMOVE <nama barang di toko> <kuantitas>.\n");
    
    // CART SHOW
    printf("3. CART SHOW\n");
    printf("   Fungsi: Untuk melihat barang-barang yang ada di keranjang.\n");
    printf("   Contoh: Ketik CART SHOW untuk menampilkan daftar barang di keranjang.\n");

    // CART PAY
    printf("4. CART PAY\n");
    printf("   Fungsi: Untuk membeli barang-barang yang sudah dimasukan ke dalam keranjang.\n");
    printf("   Contoh: Ketik CART PAY untuk membayar daftar barang di keranjang\n");

    // HISTORY
    printf("5. HISTORY\n");
    printf("   Fungsi: Untuk menunjukan riwayat pembelian seorang pengguna.\n");
    printf("   Contoh: Ketik HISTORY untuk menampilkan daftar barang yang sudah dibeli\n");

    // WISHLIST ADD
    printf("6. WISHLIST ADD\n");
    printf("   Fungsi: Untuk menambah barang untuk menambahkan suatau barang ke wishlist.\n");
    printf("   Contoh: Ketik WISHLIST ADD untuk menambahkan wishlist barang\n");

    // WISHLIST SWAP
    printf("7. WISHLIST SWAP\n");
    printf("   Fungsi: Untuk menukar barang posisi ke-i dengan barang posisi ke-j pada wishlist.\n");
    printf("   Contoh: Ketik WISHLIST SWAP <barang posisi ke-i> <barang posisis ke-j>\n");

    // WISHLIST REMOVE INDEKS KE I
    printf("7. WISHLIST REMOVE Indeks\n");
    printf("   Fungsi: Untuk menghapus barang dengan posisi ke-i dari wishlist.\n");
    printf("   Contoh: Ketik WISHLIST REMOVE <barang posisi ke-i> untuk menghapus wishlist barang\n");

    // WISHLIST REMOVE
    printf("7. WISHLIST REMOVE\n");
    printf("   Fungsi: Untuk menghapus barang dari wishlist berdasarkan nama barang yang dimasukkan pengguna.\n");
    printf("   Contoh: Ketik WISHLIST REMOVE untuk menghapus wishlist barang\n");

    // WISHLIST CLEAR
    printf("8. WISHLIST CLEAR\n");
    printf("   Fungsi: Untuk menghapus semua barang yang terdapat di dalam wishlist.\n");
    printf("   Contoh: Ketik WISHLIST CLEAR untuk menghapus seluruh wishlist barang\n");

    // WISHLIST SHOW
    printf("8. WISHLIST SHOW\n");
    printf("   Fungsi: Untuk menunjukkan barang-barang yang sudah dimasukkan ke dalam wishlist.\n");
    printf("   Contoh: Ketik WISHLIST SHOW untuk menampilkan wishlist barang\n");

    // WORK
    printf("9. WORK\n");
    printf("   Fungsi: Untuk bekerja.\n");
    printf("   Contoh: Ketik WORK untuk bekerja dan mendapatkan uang.\n");

    // WORK CHALLENGE
    printf("10. WORK CHALLENGE\n");
    printf("    Fungsi: Untuk mengerjakan challenge.\n");
    printf("    Contoh: Ketik WORK CHALLENGE untuk menyelesaikan tantangan dan mendapatkan uang.\n");

    // STORE LIST
    printf("11. STORE LIST\n");
    printf("    Fungsi: Untuk melihat barang-barang di toko.\n");
    printf("    Contoh: Ketik STORE LIST untuk menampilkan daftar barang di toko.\n");

    // STORE REQUEST
    printf("12. STORE REQUEST\n");
    printf("    Fungsi: Untuk meminta penambahan barang ke toko.\n");
    printf("    Contoh: Ketik STORE REQUEST untuk meminta barang\n");

    // STORE REQUEST BIOWEAPON
    printf("13. STORE REQUEST BIOWEAPON\n");
    printf("    Fungsi: Untuk meminta penambahan senjata biologis ke toko.\n");
    printf("    Contoh: Ketik STORE REQUEST BIOWEAPON untuk meminta senjata\n");

    // STORE SUPPLY
    printf("14. STORE SUPPLY\n");
    printf("    Fungsi: Untuk menambahkan barang berdasarkan permintaan.\n");
    printf("    Contoh: Ketik STORE SUPPLY untuk menambahkan barang\n");

    // STORE REMOVE
    printf("15. STORE REMOVE\n");
    printf("    Fungsi: Untuk menghapus barang dari toko.\n");
    printf("    Contoh: Ketik STORE REMOVE untuk menghapus barang\n");

    // LOGOUT
    printf("16. LOGOUT\n");
    printf("    Fungsi: Untuk keluar dari sesi.\n");
    printf("    Contoh: Ketik LOGOUT untuk mengakhiri sesi.\n");

    // SAVE
    printf("17. SAVE\n");
    printf("    Fungsi: Untuk menyimpan state program ke dalam file.\n");
    printf("    Contoh: Ketik SAVE untuk menyimpan\n");

    // QUIT
    printf("18. QUIT\n");
    printf("    Fungsi: Keluar dari program.\n");
    printf("    Contoh: Ketik QUIT untuk mengakhiri program\n");
}

void PrintLevel1Menu()
{
    printf("==============================================\n");
    printf("|             WELCOME TO PURRMART            |\n");
    printf("|--------------------------------------------|\n");
    printf("| Commands:                                  |\n");
    printf("|  > START                                   |\n");
    printf("|  > LOAD                                    |\n");
    printf("|  > HELP                                    |\n");
    printf("|  > QUIT                                    |\n");
    printf("==============================================\n");
    printf("Silakan pilih perintah: ");
}

void PrintLevel2Menu()
{
    printf("==============================================\n");
    printf("|             AUTENTIKASI PENGGUNA           |\n");
    printf("|--------------------------------------------|\n");
    printf("| Commands:                                  |\n");
    printf("|  > LOGIN                                   |\n");
    printf("|  > REGISTER                                |\n");
    printf("|  > HELP                                    |\n");
    printf("|  > QUIT                                    |\n");
    printf("==============================================\n");
    printf("Silakan pilih perintah: ");
}

void PrintLevel3Menu()
{
    printf("============================================================\n");
    printf("|                   PURRMART - MAIN MENU                   |\n");
    printf("|----------------------------------------------------------|\n");
    printf("| Commands:                                                |\n");
    printf("|  >  PROFILE                                              |\n");
    printf("|  >  WORK                                                 |\n");
    printf("|  >  WORK CHALLENGE                                       |\n");
    printf("|  >  STORE LIST                                           |\n");
    printf("|  >  STORE REQUEST                                        |\n");
    printf("|  >  STORE REQUEST BIOWEAPON                              |\n");
    printf("|  >  STORE SUPPLY                                         |\n");
    printf("|  >  STORE REMOVE                                         |\n");
    printf("|  >  CART ADD                                             |\n");
    printf("|  >  CART REMOVE                                          |\n");
    printf("|  >  CART SHOW                                            |\n");
    printf("|  >  CART PAY                                             |\n");
    printf("|  >  HISTORY                                              |\n");
    printf("|  >  WISHLIST ADD                                         |\n");
    printf("|  >  WISHLIST SWAP <i> <j>                                |\n");
    printf("|  >  WISHLIST REMOVE <i>                                  |\n");
    printf("|  >  WISHLIST REMOVE                                      |\n");
    printf("|  >  WISHLIST CLEAR                                       |\n");
    printf("|  >  WISHLIST SHOW                                        |\n");
    printf("|  >  LOGOUT                                               |\n");
    printf("|  >  SAVE                                                 |\n");
    printf("|  >  HELP                                                 |\n");
    printf("|  >  QUIT                                                 |\n");
    printf("============================================================\n");
    printf("Silakan pilih perintah: ");
}

void printPurrmart()
{
    printf("  ____  _   _ ____  ____  __  __    _    ____ _____ \n");
    printf(" |  _ \\| | | |  _ \\|  _ \\|  \\/  |  / \\  |  _ \\_   _|\n");
    printf(" | |_) | | | | |_) | |_) | |\\/| | / _ \\ | |_) || |  \n");
    printf(" |  __/| |_| |  _ <|  _ <| |  | |/ ___ \\|  _ < | |  \n");
    printf(" |_|    \\___/|_| \\_\\_| \\_\\_|  |_/_/   \\_\\_| \\_\\|_|  \n");
    printf("                                                    \n");
}

void printClosing()
{
    printf("=========================================================\n");
    printf("  _____ _                 _     __   __          _   \n");
    printf(" |_   _| |__   __ _ _ __ | | __ \\ \\ / ___  _   _| |  \n");
    printf("   | | | '_ \\ / _` | '_ \\| |/ /  \\ V / _ \\| | | | |  \n");
    printf("   | | | | | | (_| | | | |   <    | | (_) | |_| |_|  \n");
    printf("   |_| |_| |_|\\__,_|_| |_|_|\\_\\   |_|\\___/ \\__,_(_)  \n");
    printf("=========================================================\n");
    printf("  Terima kasih telah mengunjungi PURRMART!          \n");
    printf("  Sampai jumpa lagi!                                \n");
    printf("=========================================================\n");
}
