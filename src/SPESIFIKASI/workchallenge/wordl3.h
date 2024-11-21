#ifndef WORDL3_H
#define WORDL3_H

#include "../../ADT/Kustom/user.h"
#include "../../ADT/MesinKata/mesinkata.h"

// checks if a character exists in a Word
boolean CharExist(char c, Word *wordAns);

// tanda-tanda untuk tebakan huruf
void TandaTebakan(char *guess, Word *wordAns, char grid[5][6], int attempt, char answer[6]);

//display grid pada game
void DisplayGrid(char grid[5][6]);

//main game wordl3
int WORDL3();

#endif // WORDL3_H