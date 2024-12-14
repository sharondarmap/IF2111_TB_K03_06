#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "../../ADT/Kustom/user.h"
#include "../../ADT/MesinKata/mesinkata.h"
/* Library yang boleh digunakan hanya stdio.h, stdlib.h, time.h, dan math.h. */

int randomnumbergen(int batas, unsigned long long seed)
{
    unsigned long long a = 48271;
    unsigned long long c = 0;
    unsigned long long m = (1ULL << 31) - 1; // 2^31 - 1
    unsigned long long rng = (a * seed + c) % m;
    return (int)(rng % batas);
}

boolean CharExist(char c, Word *wordAns)
{
    for (int i = 0; i < wordAns->Length; i++)
    {
        if (c == wordAns->TabWord[i])
        {
            return true;
        }
    }
    return false;
}

void TandaTebakan(char *guess, Word *wordAns, char grid[5][6], int attempt, char answer[6])
{

    for (int i = 0; i < 5; i++)
    {
        if (guess[i] == answer[i])
        {
            grid[attempt][i] = guess[i]; // huruf benar di posisi yang benar
        }
        else if (CharExist(guess[i], wordAns))
        {
            grid[attempt][i] = '#'; // huruf benar tetapi posisi salah
        }
        else
        {
            grid[attempt][i] = '*'; // huruf tidak ada di jawaban
        }
    }
    grid[attempt][5] = '\0'; // null row untuk menge-print string
}

void DisplayGrid(char grid[5][6])
{
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int WORDL3()
{
    int chances = 0;
    unsigned long long seed;
    seed = (unsigned long long)time(NULL);
    int batas = 100;
    int r = randomnumbergen(batas, seed);
    char answer[6];

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
        "yacht", "yummy", "youth", "zebra", "zesty", "zonal"};

    for (int i = 0; i < 5; i++)
    {
        answer[i] = solution[r][i];
    }
    answer[5] = '\0';

    Word wordAns = StringToWord(answer);

    printf("WELCOME TO W0RDL3, YOU HAVE 6 CHANCES TO ANSWER BEFORE YOU LOSE!\n");
    printf(" \n");
    printf("aturan main:\n"
           "1. Terdapat 6 kesempatan.\n"
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
        "_____"};

    while (chances < 6)
    {
        DisplayGrid(grid);

        printf("Masukkan kata tebakan Anda: ");
        STARTWORD();
        char guess[6];
        for (int i = 0; i < currentWord.Length; i++)
        {
            guess[i] = currentWord.TabWord[i];
        }
        guess[currentWord.Length] = '\0'; // null-terminate the string

        if (currentWord.Length != 5)
        {
            printf("Tebakan invalid. Silakan masukkan kata dengan 5 karakter.\n");
            continue;
        }

        // update grid
        TandaTebakan(guess, &wordAns, grid, chances, answer);

        if (IsWordEqual(currentWord, wordAns))
        {
            printf("SELAMAT, ANDA MENEBAK KATA: %s\n", answer);
            return chances + 1;
        }

        chances++;
    }

    DisplayGrid(grid);
    printf("OH TIDAK Anda kehabisan kesempatan! Jawaban yang benar adalah: %s\n", answer);
    return 6; // gagal menebak kata
}