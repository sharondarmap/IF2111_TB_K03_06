#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../src/ADT/Kustom/user.h"
#include "../src/ADT/MesinKata/mesinkata.h"
/* Library yang boleh digunakan hanya stdio.h, stdlib.h, time.h, dan math.h. */

/* typedef struct
{
   char TabWord[NMax]; container penyimpan kata, indeks yang dipakai [0..NMax-1]
   int Length;
   } Word  
*/

boolean CharExist(char c, Word *wordAns){
    for (int i = 0; i < wordAns->Length; i++){
        if (c == wordAns->TabWord[i]){
            return true;
        }
    }
    return false;
}

void WORDL3(){
    int chances = 0;
    int r = rand() % 100;
    char answer[6]; //container jawaban string

    char solution[100][6] = {
    "actor", "amber", "angel", "apple", "baker", "beach", 
    "blend", "brisk", "candy", "charm", "clear", "crane", 
    "dense", "delta", "dodge", "dream", "eager", "eagle", 
    "elder", "ethic", "fable", "flame", "flute", "frost", 
    "giant", "glare", "globe", "grain", "heist", "honey", 
    "house", "hover", "image", "index", "input", "ivory", 
    "jewel", "joker", "jolly", "jumpy", "kinky", "knife", 
    "knock", "kneel", "layer", "latch", "lemon", "lofty", 
    "mango", "march", "mirth", "nylon", "noble", "north", 
    "ocean", "oasis", "orbit", "pearl", "pivot", "plant", 
    "queen", "query", "quake", "raven", "rider", "rocky", 
    "snake", "silly", "stone", "tears", "toast", "trump", 
    "ultra", "union", "urban", "valve", "vivid", "vocal", 
    "wagon", "whale", "witty", "xenon", "xerox", "xylos", 
    "yacht", "yummy", "youth", "zebra", "zesty", "zonal"
    };

    for (int i = 0; i < 5; i++) {
        answer[i] = solution[r][i];
    }
    answer[5] = '\0';  // Null-terminate the string

    Word wordAns = StringToWord(answer); //ubah string menjadi word
    char coba = wordAns.TabWord[0]; //ngambil huruf pertama dari Word kek gini ya bang

    printf("WELCOME TO W0RDL3, YOU HAVE 5 CHANCES TO ANSWER BEFORE YOU LOSE!\n");

    printf{"aturan main:\n"
            "1. Terdapat 5 kesempatan.\n"
            "2. Setiap tebakan harus merupakan kata valid 5 huruf bahasa inggris.\n"
            "3. * menunjukkan huruf tidak ada di dalam jawaban\n"
            "4. # menunjukkan huruf ada di dalam jawaban tetapi posisi salah\n"
            "5. Jika huruf benar dan posisi benar, huruf akan dikembalikan tanpa tanda\n"}


    printf("_ _ _ _ _\n"
        "_ _ _ _ _\n"
        "_ _ _ _ _\n"
        "_ _ _ _ _\n"
        "_ _ _ _ _\n");

    printf("%c\n", coba);
    
    while (chances < 5){
        printf("Masukkan kata tebakan Anda: ");
        STARTWORD();



    }

    printf("%s\n", answer); //ini buat ngeter jawaban aja sie, nanti diapus
}

int main(){
    WORDL3();

    return 0;
}