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

    // WORK
    printf("1. WORK\n");
    printf("   Fungsi: Untuk bekerja.\n");
    printf("   Contoh: Ketik WORK untuk bekerja dan mendapatkan uang.\n");

    // WORK CHALLENGE
    printf("2. WORK CHALLENGE\n");
    printf("   Fungsi: Untuk mengerjakan challenge.\n");
    printf("   Contoh: Ketik WORK CHALLENGE untuk menyelesaikan tantangan dan mendapatkan uang.\n");

    // STORE LIST
    printf("3. STORE LIST\n");
    printf("   Fungsi: Untuk melihat barang-barang di toko.\n");
    printf("   Contoh: Ketik STORE LIST untuk menampilkan daftar barang.\n");

    // STORE REQUEST
    printf("4. STORE REQUEST\n");
    printf("   Fungsi: Untuk meminta penambahan barang ke toko.\n");
    printf("   Contoh: STORE REQUEST\n");

    // STORE REQUEST BIOWEAPON
    printf("5. STORE REQUEST BIOWEAPON\n");
    printf("   Fungsi: Untuk meminta penambahan senjata biologis ke toko.\n");
    printf("   Contoh: STORE REQUEST BIOWEAPON\n");

    // STORE SUPPLY
    printf("6. STORE SUPPLY\n");
    printf("   Fungsi: Untuk menambahkan barang berdasarkan permintaan.\n");
    printf("   Contoh: STORE SUPPLY\n");

    // STORE REMOVE
    printf("7. STORE REMOVE\n");
    printf("   Fungsi: Untuk menghapus barang dari toko.\n");
    printf("   Contoh: STORE REMOVE\n");

    // LOGOUT
    printf("8. LOGOUT\n");
    printf("   Fungsi: Untuk keluar dari sesi.\n");
    printf("   Contoh: Ketik LOGOUT untuk keluar.\n");

    // SAVE
    printf("9. SAVE\n");
    printf("   Fungsi: Untuk menyimpan state program ke dalam file.\n");
    printf("   Contoh: SAVE\n");

    // QUIT
    printf("10. QUIT\n");
    printf("    Fungsi: Keluar dari program.\n");
    printf("    Contoh: QUIT\n");

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
    printf("|  >  WORK                                                 |\n");
    printf("|  >  WORK CHALLENGE                                       |\n");
    printf("|  >  STORE LIST                                           |\n");
    printf("|  >  STORE REQUEST                                        |\n");
    printf("|  >  STORE REQUEST BIOWEAPON                              |\n");
    printf("|  >  STORE SUPPLY                                         |\n");
    printf("|  >  STORE REMOVE                                         |\n");
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
