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

boolean IsEmpty(List L) {
    return (L.A[0].money == -1);
}

int Length(List L) {
    int i = 0;
    while (i < MaxEl && L.A[i].money != -1) {
        i++;
    }
    return i;
}

User Get(List L, IdxType i) {
    return L.A[i];
}

void Set(List *L, IdxType i, User u) {
    (*L).A[i] = u;
}

IdxType FirstIdx(List L) {
    return 0;
}

IdxType LastIdx(List L) {
    return Length(L) - 1;
}

boolean IsIdxValid(List L, IdxType i) {
    return (i >= 0 && i < MaxEl);
}

boolean IsIdxEff(List L, IdxType i) {
    return (i >= FirstIdx(L) && i <= LastIdx(L));
}

boolean Search(List L, char *name) {
    int i = FirstIdx(L);
    boolean found = false;
    while (i <= LastIdx(L) && !found) {
        if (CompareStrings(L.A[i].name, name)) { // Menggunakan CompareStrings
            found = true;
        }
        i++;
    }
    return found;
}

void InsertFirst(List *L, User u) {
    IdxType i = LastIdx(*L);
    while (i >= FirstIdx(*L)) {
        Set(L, i + 1, Get(*L, i));
        i--;
    }
    Set(L, FirstIdx(*L), u);
}

void InsertAt(List *L, User u, IdxType i) {
    IdxType j = LastIdx(*L);
    while (j >= i) {
        Set(L, j + 1, Get(*L, j));
        j--;
    }
    Set(L, i, u);
}

void InsertLast(List *L, User u) {
    if (IsEmpty(*L)) {
        InsertFirst(L, u);
    } else {
        Set(L, LastIdx(*L) + 1, u);
    }
}

void DeleteFirst(List *L) {
    IdxType i = FirstIdx(*L);
    while (i < LastIdx(*L)) {
        Set(L, i, Get(*L, i + 1));
        i++;
    }
    (*L).A[i].name[0] = '\0';
    (*L).A[i].password[0] = '\0';
    (*L).A[i].money = -1;
}

void DeleteAt(List *L, IdxType i) {
    while (i < LastIdx(*L)) {
        Set(L, i, Get(*L, i + 1));
        i++;
    }
    (*L).A[i].name[0] = '\0';
    (*L).A[i].password[0] = '\0';
    (*L).A[i].money = -1;
}

void DeleteLast(List *L) {
    if (!IsEmpty(*L)) {
        IdxType lastIdx = LastIdx(*L);
        (*L).A[lastIdx].name[0] = '\0';
        (*L).A[lastIdx].password[0] = '\0';
        (*L).A[lastIdx].money = -1;
    }
}

List Concat(List L1, List L2) {
    List L3 = MakeList();
    int idx = 0;

    // Tambahkan elemen dari L1
    for (int i = FirstIdx(L1); i <= LastIdx(L1); i++) {
        Set(&L3, idx++, Get(L1, i));
    }

    // Tambahkan elemen dari L2
    for (int i = FirstIdx(L2); i <= LastIdx(L2); i++) {
        Set(&L3, idx++, Get(L2, i));
    }

    return L3;
}

void PrintUser(User u) {
    printf("{name: %s, password: %s, money: %d}", u.name, u.password, u.money);
}

void PrintList(List L) {
    printf("[");
    for (int i = FirstIdx(L); i <= LastIdx(L); i++) {
        PrintUser(L.A[i]);
        if (i < LastIdx(L)) {
            printf(", ");
        }
    }
    printf("]\n");
}