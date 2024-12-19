#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

/*---------------HEADER ADT---------------*/
#include "ADT/Kustom/barang.h"
#include "ADT/Kustom/user.h"
#include "ADT/MesinKarakter/mesinkarakter.h"
#include "ADT/MesinKata/mesinkata.h"
#include "ADT/Queue/queue.h"
#include "ADT/ListDinamis/arraydin.h"
#include "ADT/List/list.h"
#include "ADT/MesinKalimat/mesinkalimat.h"

/*---------------HEADER SPESIFIKASI---------------*/
#include "SPESIFIKASI/Load/load.h"
#include "SPESIFIKASI/Save/save.h"
#include "SPESIFIKASI/Login/login.h"
#include "SPESIFIKASI/Logout/logout.h"
#include "SPESIFIKASI/Help/help.h"
#include "SPESIFIKASI/Register/register.h"
#include "SPESIFIKASI/Help/help.h"
#include "SPESIFIKASI/StoreList/StoreList.h"
#include "SPESIFIKASI/StoreRemove/StoreRemove.h"
#include "SPESIFIKASI/StoreRequest/StoreRequest.h"
#include "SPESIFIKASI/StoreSupply/StoreSupply.h"
#include "SPESIFIKASI/Work/work.h"
#include "SPESIFIKASI/workchallenge/workchallenge.h"
#include "SPESIFIKASI/StoreRequestBioWeapon/StoreRequestBioWeapon.h"
#include "SPESIFIKASI/CartAdd/cartadd.h"
#include "SPESIFIKASI/CartPay/cartpay.h"
#include "SPESIFIKASI/CartRemove/cartremove.h"
#include "SPESIFIKASI/History/history.h"
#include "SPESIFIKASI/WishlistAdd/wishlistadd.h"
#include "SPESIFIKASI/WishlistClear/wishlistclear.h"
#include "SPESIFIKASI/WishlistRemove/WishlistRemove.h"
#include "SPESIFIKASI/WishlistRemoveIdx/WishlistRemoveIdx.h"
#include "SPESIFIKASI/WishlistShow/wishlistshow.h"
#include "SPESIFIKASI/WishlistSwap/WishlistSwap.h"
#include "SPESIFIKASI/profile/profile.h"

int main()
{
    printPurrmart();

    // INISIALISASI STRUKTUR DATA
    IdxType currentIndex = IDX_UNDEF;
    char filename[MAX_LEN];  
    List userList = MakeList();
    ArrayDin barangList = MakeArrayDin();
    Queue barangQueue;
    CreateQueue(&barangQueue);

    // ALGORITMA

    int level = 1;
    boolean isRunning = true;

    while (isRunning)
    { 
        if (level == 1)
        {
            PrintLevel1Menu();
            printf("\n> ");
            STARTWORD();

            // Tingkatan 1: START, LOAD, HELP, QUIT
            if (IsWordEqual(currentWord, StringToWord("START")))
            {
                char defaultFilename[] = "default.txt";
                Load(defaultFilename, &barangList, &userList);
                level = 2; 
            }
            else if (IsWordEqual(currentWord, StringToWord("LOAD")))
            {
                printf("Nama File (.txt): ");
                printf("\n> ");
                STARTWORD();
                for (int i = 0; i < currentWord.Length; i++)
                {
                    filename[i] = currentWord.TabWord[i];
                }
                filename[currentWord.Length] = '\0';
                Load(filename, &barangList, &userList);
                if (!EndKalimat)
                {
                    printf("File berhasil dimuat. Masuk ke autentikasi pengguna.\n");
                    level = 2;
                }
                else
                {
                    printf("Gagal memuat file.\n");
                }
            }
            else if (IsWordEqual(currentWord, StringToWord("HELP")))
            {
                DisplayHelp1();
            }
            else if (IsWordEqual(currentWord, StringToWord("QUIT")))
            {
                isRunning = false;
            }
            else
            {
                printf("Command tidak dikenal. Silakan masukkan command yang valid.\n");
            }
        }
        else if (level == 2)
        {
            PrintLevel2Menu();
            printf("\n> ");
            STARTWORD();

            // Tingkatan 2: LOGIN, REGISTER, HELP, QUIT
            if (IsWordEqual(currentWord, StringToWord("LOGIN")))
            {
                Login(&userList, &currentIndex);
                ;
                level = 3;
            }
            else if (IsWordEqual(currentWord, StringToWord("REGISTER")))
            {
                RegisterUser(&userList);
            }
            else if (IsWordEqual(currentWord, StringToWord("HELP")))
            {
                DisplayHelp2();
            }
            else if (IsWordEqual(currentWord, StringToWord("QUIT")))
            {
                isRunning = false;
            }
            else
            {
                printf("Command tidak dikenal. Silakan masukkan command yang valid.\n");
            }
        }
        else if (level == 3)
        {
            PrintLevel3Menu();
            printf("\n> ");
            STARTWORD();

            // Tingkatan 3: WORK, STORE, CART, WISHLIST, LOGOUT, SAVE, QUIT
            if (IsWordEqual(currentWord, StringToWord("WORK")))
            {
                ADVWORD();
                if (IsWordEqual(currentWord, StringToWord("CHALLENGE")))
                {
                    WorkChallenge(&userList, currentIndex); // Done testing
                }
                else
                {
                    Work(&userList, currentIndex);
                }
            }
            else if (IsWordEqual(currentWord, StringToWord("STORE")))
            {
                ADVWORD();
                if (IsWordEqual(currentWord, StringToWord("LIST")))
                {
                    StoreList(&barangList);
                }
                else if (IsWordEqual(currentWord, StringToWord("REQUEST")))
                {
                    ADVWORD();
                    if (IsWordEqual(currentWord, StringToWord("BIOWEAPON"))){
                        StoreRequestBioWeapon(&barangQueue, &barangList);
                    }
                    else if (endWord)
                    {
                        StoreRequest(&barangQueue, &barangList);
                    }
                    else{
                        printf("Command tidak dikenal.\n");
                    }
                }
                else if (IsWordEqual(currentWord, StringToWord("SUPPLY")))
                {
                    StoreSupply(&barangQueue, &barangList);
                }
                else if (IsWordEqual(currentWord, StringToWord("REMOVE")))
                {
                    StoreRemove(&barangList);
                }
                else
                {
                    printf("Command tidak dikenal.\n");
                }
            }
            else if (IsWordEqual(currentWord, StringToWord("CART")))
            {
                ADVWORD();
                if (IsWordEqual(currentWord, StringToWord("ADD")))
                /*{
                    Barang *store; // should be ArrayDin?
                    int storeCount = Length(barangList);
                    CartAdd(&userList, currentIndex, &store, storeCount);
                } */
                else if (IsWordEqual(currentWord, StringToWord("PAY")))
                {
                    CartPay(&userList, currentIndex);
                }
                else if (IsWordEqual(currentWord, StringToWord("REMOVE")))
                {
                    CartRemove(&userList, currentIndex);
                }
            }
            else if (IsWordEqual(currentWord, StringToWord("HISTORY")))
            {
                history(&userList, currentIndex);
            }
            /* else if (IsWordEqual(currentWord, StringToWord("WISHLIST")))
            {
                ADVWORD();
                if (IsWordEqual(currentWord, StringToWord("ADD")))
                {
                    Barang *barangToko; 
                    int jumlahBarangToo = Length(barangList);
                    WishlistAdd(&user, Barang *barangToko, int jumlahBarangToko);
                }
                else if (IsWordEqual(currentWord, StringToWord("CLEAR")))
                {
                    CartPay(&userList, currentIndex);
                }
                else if (IsWordEqual(currentWord, StringToWord("REMOVE")))
                {
                    CartPay(&userList, currentIndex);
                }
                else if (IsWordEqual(currentWord, StringToWord("REMOVE IDX")))
                {
                    CartPay(&userList, currentIndex);
                }
                else if (IsWordEqual(currentWord, StringToWord("SHOW")))
                {
                    CartRemove(&userList, currentIndex);
                }
                else if (IsWordEqual(currentWord, StringToWord("SWAP")))
                {
                    CartPay(&userList, currentIndex);
                }
            } */
            else if (IsWordEqual(currentWord, StringToWord("LOGOUT")))
            {
                Logout(currentIndex);
                level = 2;
            }
            else if (IsWordEqual(currentWord, StringToWord("SAVE")))
            {
                Save(&barangList, &userList, filename);
                printf("Berhasil menyimpan data!");
            }
            else if (IsWordEqual(currentWord, StringToWord("QUIT")))
            {
                printf("Apakah Anda ingin menyimpan sesi ini? (Y/N)\n");
                boolean quit = false;
                while (!quit)
                {
                    printf("> ");
                    STARTWORD();
                    if (IsWordEqual(currentWord, StringToWord("Y")))
                    {
                        Save(&barangList, &userList, filename);
                        printf("Berhasil menyimpan data!");
                        quit = true;
                    }
                    else if (IsWordEqual(currentWord, StringToWord("N")))
                    {
                        quit = true;
                    }
                    else
                    {
                        printf("Command tidak dikenal. Silakan masukkan command yang valid.\n");
                        printf("Apakah Anda ingin menyimpan sesi ini? (Y/N)\n");
                    }
                    isRunning = false;
                }
            }
            else if (IsWordEqual(currentWord, StringToWord("HELP")))
            {
                DisplayHelp3();
            }
            else
            {
                printf("Command tidak dikenal. Silakan masukkan command yang valid.\n");
            }
        }
    }

    printClosing();
    return 0;
}
