#include <stdio.h>
#include "list.h"

int CompareStrings(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

void CopyString(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Konstruktor
List MakeList() {
    List L;
    IdxType i;
    for (i = 0; i < MaxEl; i++) {
        L.A[i].name[0] = '\0';
        L.A[i].password[0] = '\0';
        L.A[i].money = -1;
    }
    return L;
}

boolean IsEmptyList(List L) {
    return (L.A[0].money == -1);
}

int LengthList(List L) {
    int i = 0;
    while (i < MaxEl && L.A[i].money != -1) {
        i++;
    }
    return i;
}

User GetList(List L, IdxType i) {
    if (i < FirstIdxList(L) || i > LastIdxList(L)) {
        printf("Error: Indeks tidak valid.\n");
        exit(1); // Menghentikan program jika indeks tidak valid
    }
    return L.A[i];
}

void SetList(List *L, IdxType i, User u) {
    (*L).A[i] = u;
}

IdxType FirstIdxList(List L) {
    return 0;
}

IdxType LastIdxList(List L) {
    return LengthList(L) - 1;
}

boolean IsIdxValidList(List L, IdxType i) {
    return (i >= 0 && i < MaxEl);
}

boolean IsIdxEffList(List L, IdxType i) {
    return (i >= FirstIdxList(L) && i <= LastIdxList(L));
}

boolean SearchList(List L, char *name) {
    if (name == NULL) {
        return false; // Nama tidak valid
    }
    int i = FirstIdxList(L);
    boolean found = false;
    while (i <= LastIdxList(L) && !found) {
        if (CompareStrings(L.A[i].name, name)) { // Membandingkan nama
            found = true;
        }
        i++;
    }
    return found;
}

void InsertFirstList(List *L, User u) {
    IdxType i = LastIdxList(*L);
    while (i >= FirstIdxList(*L)) {
        SetList(L, i + 1, GetList(*L, i));
        i--;
    }
    SetList(L, FirstIdxList(*L), u);
}

void InsertAtList(List *L, User u, IdxType i) {
    IdxType j = LastIdxList(*L);
    while (j >= i) {
        SetList(L, j + 1, GetList(*L, j));
        j--;
    }
    SetList(L, i, u);
}

void InsertLastList(List *L, User u) {
    if (IsEmptyList(*L)) {
        InsertFirstList(L, u);
    } else {
        SetList(L, LastIdxList(*L) + 1, u);
    }
}

void DeleteFirstList(List *L) {
    IdxType i = FirstIdxList(*L);
    while (i < LastIdxList(*L)) {
        SetList(L, i, GetList(*L, i + 1));
        i++;
    }
    (*L).A[i].name[0] = '\0';
    (*L).A[i].password[0] = '\0';
    (*L).A[i].money = -1;
}

void DeleteAtList(List *L, IdxType i) {
    while (i < LastIdxList(*L)) {
        SetList(L, i, GetList(*L, i + 1));
        i++;
    }
    (*L).A[i].name[0] = '\0';
    (*L).A[i].password[0] = '\0';
    (*L).A[i].money = -1;
}

void DeleteLastList(List *L) {
    if (!IsEmptyList(*L)) {
        IdxType lastIdx = LastIdxList(*L);
        (*L).A[lastIdx].name[0] = '\0';
        (*L).A[lastIdx].password[0] = '\0';
        (*L).A[lastIdx].money = -1;
    }
}

List ConcatList(List L1, List L2) {
    List L3 = MakeList();
    int idx = 0;

    // Tambahkan elemen dari L1
    for (int i = FirstIdxList(L1); i <= LastIdxList(L1); i++) {
        SetList(&L3, idx++, GetList(L1, i));
    }

    // Tambahkan elemen dari L2
    for (int i = FirstIdxList(L2); i <= LastIdxList(L2); i++) {
        SetList(&L3, idx++, GetList(L2, i));
    }

    return L3;
}

void PrintUser(User u) {
    printf("{name: %s, password: %s, money: %d}", u.name, u.password, u.money);
}

void PrintList(List L) {
    printf("[");
    for (int i = FirstIdxList(L); i <= LastIdxList(L); i++) {
        PrintUser(L.A[i]);
        if (i < LastIdxList(L)) {
            printf(", ");
        }
    }
    printf("]\n");
}

void CopyWordToCharArray(Word src, char *dest) {
    int i;
    for (i = 0; i < src.Length && i < MAX_LEN - 1; i++) {
        dest[i] = src.TabWord[i];
    }
    dest[i] = '\0'; // Tambahkan null-terminator
}

int SearchUserIndex(List L, char *name) {
    if (name == NULL) {
        return -1; // Nama tidak valid
    }
    int i = FirstIdxList(L);
    while (i <= LastIdxList(L)) {
        if (CompareStrings(L.A[i].name, name)) { // Membandingkan nama
            return i; // Kembalikan indeks jika ditemukan
        }
        i++;
    }
    return -1; // Tidak ditemukan
}
