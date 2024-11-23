#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

//ASUMSI MAIN.C ADA DI DALAM SRC//

/*---------------HEADER ADT---------------*/
#include "ADT/Kustom/barang.h"
#include "ADT/Kustom/user.h"
#include "ADT/MesinKarakter/mesinkarakter.h"
#include "ADT/MesinKata/mesinkata.h"
#include "ADT/Queue/queue.h"
#include "ADT/List/arraydin.h"
#include "ADT/List/list.h"
#include "ADT/MesinKalimat/mesinkalimat.h"

/*---------------C FILE ADT---------------*/
#include "ADT/MesinKarakter/mesinkarakter.c"
#include "ADT/MesinKata/mesinkata.c"
#include "ADT/Queue/queue.c"
#include "ADT/List/arraydin.c"
#include "ADT/List/list.c"
#include "ADT/MesinKalimat/mesinkalimat.c"

#include "SPESIFIKASI/Load/load.c"
#include "SPESIFIKASI/Login/login.c"
#include "SPESIFIKASI/Logout/logout.c"
#include "SPESIFIKASI/Save/save.c"

/*---------------HEADER SPESIFIKASI---------------*/
#include "SPESIFIKASI/Load/load.h"
#include "SPESIFIKASI/Save/save.h"
#include "SPESIFIKASI/Login/login.h"
#include "SPESIFIKASI/StoreList/StoreList.h"
#include "SPESIFIKASI/StoreRemove/StoreRemove.h"
#include "SPESIFIKASI/StoreRequest/StoreRequest.h"
#include "SPESIFIKASI/StoreSupply/StoreSupply.h"
#include "SPESIFIKASI/Work/work.h"
#include "SPESIFIKASI/workchallenge/workchallenge.h"

#include "SPESIFIKASI/StoreList/StoreList.c"
#include "SPESIFIKASI/StoreRemove/StoreRemove.c"
#include "SPESIFIKASI/StoreRequest/StoreRequest.c"
#include "SPESIFIKASI/StoreSupply/StoreSupply.c"
#include "SPESIFIKASI/Work/work.c"
#include "SPESIFIKASI/workchallenge/workchallenge.c"
#include "SPESIFIKASI/workchallenge/tebakangka.c"
#include "SPESIFIKASI/workchallenge/wordl3.c"

// boolean EndKalimat = 0;  // Deklarasi variabel global
// Kalimat CLine;
// Kalimat CInput;
// Kalimat CCommand;

// #include "src/ADT/MesinKarakter/mesinkarakter.h"
// #include "src/ADT/MesinKata/mesinkata.h"
// #include "src/ADT/List/list.h"
// #include "src/ADT/List/arraydin.h"
// #include "src/ADT/MesinKalimat/mesinkalimat.h"
// #include "src/ADT/Kustom/user.h"
// #include "src/ADT/Kustom/barang.h"
// #include "src/SPESIFIKASI/Load/load.h"
// #include "src/SPESIFIKASI/Save/save.h"
// #include "src/SPESIFIKASI/Login/login.h"
// #include "src/SPESIFIKASI/Logout/logout.h"
// #include "src/SPESIFIKASI/Work/work.h"
// #include "src/SPESIFIKASI/Register/register.h"
// #include "src/SPESIFIKASI/StoreList/StoreList.h"
// #include "src/SPESIFIKASI/StoreSupply/StoreSupply.h"
// #include "src/SPESIFIKASI/StoreRequest/StoreRequest.h"
// #include "src/SPESIFIKASI/workchallenge/workchallenge.h"
// #include "src/SPESIFIKASI/workchallenge/tebakangka.h"
// #include "src/SPESIFIKASI/workchallenge/wordl3.h"
// #include "boolean.h"

void StartCommand() {
    printf("START Command executed (Stub).\n");
}

void LoadCommand(Word filename) {
    printf("LOAD Command executed with file: ");
    PrintWord(filename);
    printf(" (Stub).\n");
}

void LoginCommand() {
    printf("LOGIN Command executed (Stub).\n");
}

void HelpCommand() {
    printf("HELP Command executed (Stub): Menampilkan daftar perintah yang tersedia.\n");
}

void QuitCommand() {
    printf("QUIT Command executed (Stub).\n");
}

void RegisterCommand() {
    printf("REGISTER Command executed (Stub): Mendaftarkan akun baru.\n");
}

void WorkCommand() {
    printf("WORK Command executed (Stub): Bekerja untuk mendapatkan uang.\n");
}

void WorkChallengeCommand() {
    printf("WORK CHALLENGE Command executed (Stub): Mengikuti tantangan untuk mendapatkan uang.\n");
}

void StoreListCommand() {
    printf("STORE LIST Command executed (Stub): Menampilkan daftar barang di toko.\n");
}

void StoreRequestCommand() {
    printf("STORE REQUEST Command executed (Stub): Meminta penambahan barang ke toko.\n");
}

void StoreSupplyCommand() {
    printf("STORE SUPPLY Command executed (Stub): Menambahkan barang dari permintaan ke toko.\n");
}

void StoreRemoveCommand() {
    printf("STORE REMOVE Command executed (Stub): Menghapus barang dari toko.\n");
}

void LogoutCommand() {
    printf("LOGOUT Command executed (Stub): Keluar dari sesi dan kembali ke menu login.\n");
}

void SaveCommand() {
    printf("SAVE Command executed (Stub): Menyimpan state aplikasi saat ini ke file.\n");
}

void printClosing() {
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

void printPurrmart() {
    printf("  ____  _   _ ____  ____  __  __    _    ____ _____ \n");
    printf(" |  _ \\| | | |  _ \\|  _ \\|  \\/  |  / \\  |  _ \\_   _|\n");
    printf(" | |_) | | | | |_) | |_) | |\\/| | / _ \\ | |_) || |  \n");
    printf(" |  __/| |_| |  _ <|  _ <| |  | |/ ___ \\|  _ < | |  \n");
    printf(" |_|    \\___/|_| \\_\\_| \\_\\_|  |_/_/   \\_\\_| \\_\\|_|  \n");
    printf("                                                    \n");
}


void PrintLevel1Menu() {
    printf("==============================================\n");
    printf("|             WELCOME TO PURRMART            |\n");
    printf("|--------------------------------------------|\n");
    printf("| Commands:                                  |\n");
    printf("|  1. START - Mulai sesi baru                |\n");
    printf("|  2. LOAD  - Memuat file konfigurasi        |\n");
    printf("|  3. HELP  - Menampilkan panduan            |\n");
    printf("|  4. QUIT  - Keluar dari program            |\n");
    printf("==============================================\n");
    printf("Silakan pilih perintah: ");
}

void PrintLevel2Menu() {
    printf("==============================================\n");
    printf("|             AUTENTIKASI PENGGUNA           |\n");
    printf("|--------------------------------------------|\n");
    printf("| Commands:                                  |\n");
    printf("|  1. LOGIN    - Masuk ke akun               |\n");
    printf("|  2. REGISTER - Buat akun baru              |\n");
    printf("|  3. HELP     - Menampilkan panduan         |\n");
    printf("|  4. QUIT     - Keluar dari program         |\n");
    printf("==============================================\n");
    printf("Silakan pilih perintah: ");
}

void PrintLevel3Menu() {
    printf("============================================================\n");
    printf("|                   PURRMART - MAIN MENU                   |\n");
    printf("|----------------------------------------------------------|\n");
    printf("| Commands:                                                |\n");
    printf("|  1. WORK               - Bekerja untuk mendapatkan uang  |\n");
    printf("|  2. WORK CHALLENGE     - Ikuti tantangan untuk hadiah    |\n");
    printf("|  3. STORE LIST         - Lihat barang di toko            |\n");
    printf("|  4. STORE REQUEST      - Minta barang baru ke toko       |\n");
    printf("|  5. STORE SUPPLY       - Tambahkan barang dari permintaan|\n");
    printf("|  6. STORE REMOVE       - Hapus barang dari toko          |\n");
    printf("|  7. LOGOUT             - Keluar dari sesi pengguna       |\n");
    printf("|  8. SAVE               - Simpan progres saat ini         |\n");
    printf("|  9. QUIT               - Keluar dari program             |\n");
    printf("============================================================\n");
    printf("Silakan pilih perintah: ");
}

int main() {

    // INISIALISASI STRUKTUR DATA
    IdxType currentIndex = IDX_UNDEF; //bukan tipe pointer ke iny tapi ke tipenya integer krn gabisa assign idx_undef ke pointer
    char filename[MAX_LEN]; //untuk menge-load file data

    List userList = MakeList();
    ArrayDin barangList = MakeArrayDin();
    Queue barangQueue;
    CreateQueue(&barangQueue);

    /*TEST SEBELUM LOAD DOANG*/
    User u1 = {"Izhar", "pass123", 500};
    User u2 = {"Harfhan", "secure456", 1000};
    User u3 = {"Sharon", "mypassword", 750};
    User u4 = {"Gita", "hello789", 600};

    InsertFirstList(&userList, u1);
    InsertFirstList(&userList, u2);
    InsertFirstList(&userList, u3);
    InsertFirstList(&userList, u4);

    Barang barang1 = {"Buku", 20000};
    Barang barang2 = {"Pensil", 5000};
    Barang barang3 = {"Buku", 20000}; // Barang duplikat

    InsertLast(&barangList, barang1);
    InsertLast(&barangList, barang2);
    InsertLast(&barangList, barang3);

    // INISIALISASI DATA UNTUK KEBUTUHAN DEBUGGING

    // Barang barang1 = {"AK-47", 10000};
    // User u1 = {"Izhar", "pass123", 500};
    // enqueue(&barangQueue, barang1);
    // InsertFirst(&barangList, barang1);
    // InsertFirstList(&userList, u1);
    
    // ALGORITMA

    int level = 1;
    boolean isRunning = true;

    // printf("DEBUG DATA AWAL: \n\n");

    // printf("DEBUG Queue: \n");
    // displayQueue(barangQueue);
    // printf("\n");

    // printf("DEBUG Barang: \n");
    // PrintArrayDin(barangList);
    // printf("\n");

    // printf("DEBUG User: \n");
    // PrintList(userList);
    // printf("\n");
    
    // printPurrmart();
    
    while (isRunning) { //mulai looping while isRunning (kondisi isRunning true, berhenti jika false)
        if (level == 1) {
            PrintLevel1Menu();
            printf("\n> ");
            STARTWORD();

            // Tingkatan 1: START, LOAD, HELP, QUIT
            if (IsWordEqual(currentWord, StringToWord("START"))) {
                char defaultFilename[] = "default.txt"; // File default untuk START
                Load(defaultFilename, &barangList, &userList);
                level = 2; //masuk ke menu level 2 (Autentikasi)
            } else if (IsWordEqual(currentWord, StringToWord("LOAD"))) {
                printf("Nama File (.txt): ");
                printf("\n> ");
                STARTWORD();
                for (int i = 0; i < currentWord.Length; i++) {
                    filename[i] = currentWord.TabWord[i];
                }
                filename[currentWord.Length] = '\0'; // Tambahkan null-terminator

                Load(filename, &barangList, &userList);
                            // Validasi setelah Load
                if (!EndKalimat) { // Jika file valid
                    printf("File berhasil dimuat. Masuk ke autentikasi pengguna.\n");
                    level = 2; // Masuk ke menu level 2
                } else { // Jika file salah
                    printf("Gagal memuat file.\n");
                }
                
            } else if (IsWordEqual(currentWord, StringToWord("HELP"))) {
                HelpCommand();
            } else if (IsWordEqual(currentWord, StringToWord("QUIT"))) {
                QuitCommand();
                isRunning = false;
            } else {
                printf("Command tidak dikenal. Silakan masukkan command yang valid.\n");
            }
        } else if (level == 2) { //Autentikasi Pengguna
            PrintLevel2Menu();
            printf("\n> ");
            STARTWORD();

            // Tingkatan 2: LOGIN, REGISTER, HELP, QUIT
            if (IsWordEqual(currentWord, StringToWord("LOGIN"))) {
                Login(&userList, &currentIndex);;
                level = 3; //Main Menu PURRMART
            } else if (IsWordEqual(currentWord, StringToWord("REGISTER"))) {
                RegisterCommand();
            } else if (IsWordEqual(currentWord, StringToWord("HELP"))) {
                HelpCommand();
            } else if (IsWordEqual(currentWord, StringToWord("QUIT"))) {
                QuitCommand();
                isRunning = false; //Keluar looping
            } else {
                printf("Command tidak dikenal. Silakan masukkan command yang valid.\n");
            }
        } else if (level == 3) { //Main Menu PURRMART
            PrintLevel3Menu();
            printf("\n> ");
            STARTWORD();

            // Tingkatan 3: WORK, STORE, LOGOUT, SAVE, QUIT
            if (IsWordEqual(currentWord, StringToWord("WORK"))) {
                ADVWORD();
                if (IsWordEqual(currentWord, StringToWord("CHALLENGE"))) {
                    WorkChallenge(&userList, currentIndex); //Done testing
                } else {
                    Work(&userList, currentIndex);
                }
            } else if (IsWordEqual(currentWord, StringToWord("STORE"))) {
                ADVWORD();
                if (IsWordEqual(currentWord, StringToWord("LIST"))) {
                    StoreList(&barangList);
                } else if (IsWordEqual(currentWord, StringToWord("REQUEST"))) {
                    StoreRequest(&barangQueue, &barangList);
                } else if (IsWordEqual(currentWord, StringToWord("SUPPLY"))) {
                    StoreSupply(&barangQueue, &barangList);
                } else if (IsWordEqual(currentWord, StringToWord("REMOVE"))) {
                    StoreRemove(&barangList);
                } else {
                    printf("Command tidak dikenal.\n");
                }
            } else if (IsWordEqual(currentWord, StringToWord("LOGOUT"))) {
                LogoutCommand();
                level = 2;
            } else if (IsWordEqual(currentWord, StringToWord("SAVE"))) {
                Save(&barangList, &userList, filename);
                printf("Berhasil menyimpan data!");
            } else if (IsWordEqual(currentWord, StringToWord("QUIT"))) {
                printf("Apakah Anda ingin menyimpan sesi ini? (Y/N)\n");
                boolean quit = false;
                while(!quit){
                    printf("> ");
                    STARTWORD();
                    if(IsWordEqual(currentWord, StringToWord("Y"))){
                        Save(&barangList, &userList, filename);
                        printf("Berhasil menyimpan data!");
                        QuitCommand();
                        quit = true;
                    }
                    else if(IsWordEqual(currentWord, StringToWord("N"))){
                        QuitCommand();
                        quit = true;
                    }
                    else{
                        printf("Command tidak dikenal. Silakan masukkan command yang valid.\n");
                        printf("Apakah Anda ingin menyimpan sesi ini? (Y/N)\n");
                    }
                    isRunning = false;
                }
            } else {
                printf("Command tidak dikenal. Silakan masukkan command yang valid.\n");
            }
        }
    }

    printClosing();
    return 0;
}
