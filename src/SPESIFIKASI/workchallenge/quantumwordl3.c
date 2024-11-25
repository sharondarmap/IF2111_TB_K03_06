#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "wordl3.h"

void TandaTebakanQuantum(char *guess, Word *wordAns, char grid[9][6], int attempt) {
    for (int i = 0; i < 5; i++) {
        if (guess[i] == wordAns->TabWord[i]) {
            grid[attempt][i] = guess[i]; // Huruf benar di posisi yang benar
        } else if (CharExist(guess[i], wordAns)) {
            grid[attempt][i] = '#'; // Huruf benar tetapi salah posisi
        } else {
            grid[attempt][i] = '*'; // Huruf tidak ada di kata target
        }
    }
    grid[attempt][5] = '\0'; // Null-terminate string
}


int QuantumWORDL3() {
    int attempts = 0;
    int max_attempts = 9; // Batas maksimal percobaan
    int is_correct[4] = {0, 0, 0, 0}; // Status benar untuk setiap kata target (0: belum benar, 1: benar)
    char answers[4][6];   // Empat kata target
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

    // Pilih empat kata target secara acak
    unsigned long long seed = (unsigned long long)time(NULL);
    int chosen_indices[4] = {-1, -1, -1, -1}; // Indeks kata yang dipilih
    for (int i = 0; i < 4; i++) {
        int new_index;
        int is_unique;
        do {
            new_index = randomnumbergen(100, seed + i); // Seed berbeda untuk tiap kata
            is_unique = 1; // Asumsikan unik
            for (int j = 0; j < i; j++) {
                if (new_index == chosen_indices[j]) {
                    is_unique = 0; // Tidak unik
                    break;
                }
            }
        } while (!is_unique); // Ulang jika tidak unik
        chosen_indices[i] = new_index;
        for (int j = 0; j < 5; j++) {
            answers[i][j] = solution[new_index][j];
        }
        answers[i][5] = '\0'; // Null-terminate kata
    }

    // Buat Word dari kata-kata target
    Word wordAnswers[4];
    for (int i = 0; i < 4; i++) {
        wordAnswers[i].Length = 5;
        for (int j = 0; j < 5; j++) {
            wordAnswers[i].TabWord[j] = answers[i][j];
        }
    }

    // Inisialisasi grid
    char grid[4][9][6] = {
        { "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____" },
        { "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____" },
        { "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____" },
        { "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____" }
    };

    // Aturan main
    printf("\n=====================================================================================\n");
    printf("WELCOME TO QUANTUM W0RDL3!\n");
    printf("Aturan main:\n");
    printf("1. Terdapat %d kesempatan.\n", max_attempts);
    printf("2. Setiap tebakan harus merupakan kata valid 5 huruf kecil (lowercase) bahasa Inggris.\n");
    printf("3. * menunjukkan huruf tidak ada di dalam jawaban\n");
    printf("4. # menunjukkan huruf ada di dalam jawaban tetapi posisi salah\n");
    printf("5. Jika huruf benar dan posisi benar, huruf akan dikembalikan tanpa tanda\n");
    printf("\n=====================================================================================\n");

    // Loop permainan
    while (attempts < max_attempts) {
        printf("\nPercobaan yang tersisa: %d\n", max_attempts - attempts);

        // Tampilkan grid untuk setiap kata
        for (int i = 0; i < 4; i++) {
            if (is_correct[i]) {
                printf("Kata %d benar: %s\n", i + 1, answers[i]);
            } else {
                printf("Kata %d:\n", i + 1);
                for (int j = 0; j < max_attempts; j++) { // Menampilkan seluruh grid
                    for (int k = 0; k < 5; k++) {
                        printf("%c ", grid[i][j][k]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
        }

        // Input tebakan menggunakan ADT Word
        printf("\nMasukkan kata tebakan Anda: ");
        STARTWORD();
        Word guess = StringToWord(currentWord.TabWord);

        // Evaluasi tebakan untuk setiap kata target
        int all_correct = 1; // Asumsikan semua benar
        for (int i = 0; i < 4; i++) {
            if (!is_correct[i]) { // Periksa hanya kata yang belum benar
                TandaTebakanQuantum(guess.TabWord, &wordAnswers[i], grid[i], attempts);
                
                int is_match = 1;
                for (int j = 0; j < 5; j++) {
                    if (guess.TabWord[j] != wordAnswers[i].TabWord[j]) {
                        is_match = 0;
                        break;
                    }
                }
                if (is_match) {
                    is_correct[i] = 1; // Tandai kata ini sudah benar
                }
            }
            if (!is_correct[i]) {
                all_correct = 0; // Set ke false jika ada kata yang belum benar
            }
        }
        // Jika semua kata benar
        if (all_correct) {
            printf("\n==================================================================\n");
            printf("SELAMAT! Anda menebak semua kata dengan benar dalam %d percobaan.\n", attempts + 1);
            printf("\n==================================================================\n");
            return attempts + 1;
        }

        attempts++;
    }

    // Jika pemain gagal menebak semua kata
    int correct_count = 0;
    for (int i = 0; i < 4; i++) {
        if (is_correct[i]) {
            correct_count++;
        }
    }

    printf("\n=========================================\n");
    printf("ANDA KEHABISAN KESEMPATAN!\n");
    printf("Jawaban yang benar adalah:\n");
    for (int i = 0; i < 4; i++) {
        printf("Kata %d: %s\n", i + 1, answers[i]);
    }
    printf("\nAnda berhasil menebak %d dari 4 kata.\n", correct_count);
    printf("\n=========================================\n");

    return max_attempts + 1;
}
