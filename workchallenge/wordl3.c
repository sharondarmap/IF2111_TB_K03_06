#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../src/ADT/Kustom/user.h"
#include "../src/ADT/MesinKata/mesinkata.h"
/* Library yang boleh digunakan hanya stdio.h, stdlib.h, time.h, dan math.h. */

boolean CharExist(char c, Word *wordAns) {
    for (int i = 0; i < wordAns->Length; i++) {
        if (c == wordAns->TabWord[i]) {
            return true;
        }
    }
    return false;
}

void TandaTebakan(char *guess, Word *wordAns, char grid[5][6], int attempt, char answer[6]) {
    // Change answer to char[6], not a single character
    for (int i = 0; i < 5; i++) {
        if (guess[i] == answer[i]) {
            grid[attempt][i] = guess[i]; //huruf benar di posisi yang benar
        } else if (CharExist(guess[i], wordAns)) {
            grid[attempt][i] = '#'; //huruf benar tetapi posisi salah
        } else {
            grid[attempt][i] = '*'; //huruf tidak ada di jawaban
        }
    }
    grid[attempt][5] = '\0'; //null row untuk menge-print string
}

void DisplayGrid(char grid[5][6]) {
    printf("\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int WORDL3() {
    int chances = 0;
    int r = rand() % 100;
    char answer[6]; // container for the answer string

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
    answer[5] = '\0';

    Word wordAns = StringToWord(answer); // convert the answer string to a Word

    printf("WELCOME TO W0RDL3, YOU HAVE 5 CHANCES TO ANSWER BEFORE YOU LOSE!\n");
    printf(" \n");
    printf("aturan main:\n"
           "1. Terdapat 5 kesempatan.\n"
           "2. Setiap tebakan harus merupakan kata valid 5 huruf kecil (lowercase) bahasa inggris.\n"
           "3. * menunjukkan huruf tidak ada di dalam jawaban\n"
           "4. # menunjukkan huruf ada di dalam jawaban tetapi posisi salah\n"
           "5. Jika huruf benar dan posisi benar, huruf akan dikembalikan tanpa tanda\n");

    /*printf("_ _ _ _ _\n"
        "_ _ _ _ _\n"
        "_ _ _ _ _\n"
        "_ _ _ _ _\n"
        "_ _ _ _ _\n");*/
        
    char grid[5][6] = {
        "_____",
        "_____",
        "_____",
        "_____",
        "_____"
    };

    while (chances < 5) {
        DisplayGrid(grid);

        printf("Masukkan kata tebakan Anda: ");
        STARTWORD(); // capture user input using mesinkata
        char guess[6];
        for (int i = 0; i < currentWord.Length; i++) {
            guess[i] = currentWord.TabWord[i];
        }
        guess[currentWord.Length] = '\0'; // null-terminate the string

        if (currentWord.Length != 5) {
            printf("Invalid guess. Please enter exactly 5 letters.\n");
            continue;
        }

        // update the answer grid
        TandaTebakan(guess, &wordAns, grid, chances, answer);

        if (IsWordEqual(currentWord, wordAns)) {
            printf("SELAMAT, ANDA MENEBAK KATA: %s\n", answer);
            return chances + 1; // Return the number of chances used
        }

        chances++;
    }

    DisplayGrid(grid);
    printf("OH TIDAK Anda kehabisan kesempatan! Jawaban yang benar adalah: %s\n", answer);
    return 6; // Return 6 to indicate failure
}