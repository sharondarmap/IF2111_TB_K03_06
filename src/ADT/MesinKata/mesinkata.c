#include <stdio.h>
#include "mesinkata.h"
#include "../MesinKarakter/mesinkarakter.h"

boolean endWord;
Word currentWord;
Word currentInput;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK && !IsEOP())
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean isEndWord() {
    return endWord;
}

int WordToInt(Word w) {
    int result = 0;
    for (int i = 0; i < w.Length; i++) {
        result = result * 10 + (w.TabWord[i] - '0');
    }
    return result;
}

Word IntToWord(int num) {
    Word w;
    w.Length = 0;

    char temp[NMax];
    int i = 0;

    if (num == 0) {
        w.TabWord[0] = '0';
        w.Length = 1;
        return w;
    }

    while (num > 0) {
        temp[i++] = '0' + (num % 10);
        num /= 10;
    }

    for (int j = 0; j < i; j++) {
        w.TabWord[j] = temp[i - j - 1];
    }
    w.Length = i;

    return w;
}

Word StringToWord(char *str) {
    Word w;
    int i = 0;

    while (str[i] != '\0' && i < NMax) {
        w.TabWord[i] = str[i];
        i++;
    }
    w.Length = i;

    return w;
}

char* WordToString(Word w) {
    char *str = malloc((w.Length + 1) * sizeof(char)); // +1 untuk null-terminator
    for (int i = 0; i < w.Length; i++) {
        str[i] = w.TabWord[i];
    }
    str[w.Length] = '\0';
    return str;
}

void PrintWord(Word w) {
    for (int i = 0; i < w.Length; i++) {
        printf("%c", w.TabWord[i]);
    }
    printf("\n");
}

boolean IsWordEqual(Word w1, Word w2) {
    if (w1.Length != w2.Length) {
        return false;
    }
    for (int i = 0; i < w1.Length; i++) {
        if (w1.TabWord[i] != w2.TabWord[i]) {
            return false;
        }
    }
    return true;
}

// Fungsi tambahan untuk mereset state mesin kata
void ResetWord(Word *w) {
    w->Length = 0;
    for (int i = 0; i < NMax; i++) {
        w->TabWord[i] = '\0';
    }
}
