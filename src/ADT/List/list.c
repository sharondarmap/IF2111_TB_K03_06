#include <stdio.h>
#include "list.h"

// String Comparison
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

// String Copy
void CopyString(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Constructor
List MakeList() {
    List L;
    IdxType i;
    for (i = 0; i < MaxEl; i++) {
        L.A[i].name[0] = '\0';
        L.A[i].password[0] = '\0';
        L.A[i].money = -1;

        // Assume auxiliary functions are implemented in list.h
        CreateEmptyKeranjang(&L.A[i].keranjang);
        CreateEmptyStack(&L.A[i].riwayat_pembelian);
        CreateEmptyWishlist(&L.A[i].wishList);
    }
    return L;
}

// Check if List is Empty
boolean IsEmptyList(List L) {
    return (LengthList(L) == 0);
}

// List Length
int LengthList(List L) {
    int i = 0;
    while (i < MaxEl && L.A[i].money != -1) {
        i++;
    }
    return i;
}

// Get and Set Elements
ElType GetList(List L, IdxType i) {
    if (i < 0 || i >= MaxEl || L.A[i].money == -1) {
        printf("Error: Invalid index %d.\n", i);
        return L.A[0]; // Return a default value in case of error
    }
    return L.A[i];
}

void SetList(List *L, IdxType i, ElType v) {
    if (i < 0 || i >= MaxEl) {
        printf("Error: Invalid index %d.\n", i);
        return;
    }
    (*L).A[i] = v;
}

// Index Operations
IdxType FirstIdxList(List L) {
    return 0;
}

IdxType LastIdxList(List L) {
    int len = LengthList(L);
    return (len > 0) ? len - 1 : -1; // Return -1 if the list is empty
}

boolean IsIdxValidList(List L, IdxType i) {
    return (i >= 0 && i < MaxEl);
}

boolean IsIdxEffList(List L, IdxType i) {
    return (i >= FirstIdxList(L) && i <= LastIdxList(L));
}

// Search for a User by Name
boolean SearchList(List L, char *name) {
    if (name == NULL) {
        return 0; // Name is invalid
    }
    for (int i = FirstIdxList(L); i <= LastIdxList(L); i++) {
        if (CompareStrings(L.A[i].name, name)) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

// Insert Operations
void InsertFirstList(List *L, ElType v) {
    // Ensure the list is initialized and not full
    if (L == NULL) {
        printf("Error: List is uninitialized.\n");
        return;
    }
    if (LengthList(*L) >= MaxEl) {
        printf("Error: List is full.\n");
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = LastIdxList(*L); i >= 0; i--) {
        SetList(L, i + 1, GetList(*L, i));
    }

    // Insert the new element at the first position
    SetList(L, 0, v);
}

void InsertLastList(List *L, ElType u) {
    if (IsEmptyList(*L)) {
        InsertFirstList(L, u);
    } else {
        SetList(L, LastIdxList(*L) + 1, u);
    }
}

void InsertAtList(List *L, ElType u, IdxType i) {
    if (i < 0 || i > LastIdxList(*L) + 1 || LengthList(*L) >= MaxEl) {
        printf("Error: Invalid index or list is full.\n");
        return;
    }
    for (int j = LastIdxList(*L); j >= i; j--) {
        SetList(L, j + 1, GetList(*L, j));
    }
    SetList(L, i, u);
}

// Delete Operations
void DeleteFirstList(List *L) {
    for (int i = FirstIdxList(*L); i < LastIdxList(*L); i++) {
        SetList(L, i, GetList(*L, i + 1));
    }
    (*L).A[LastIdxList(*L)].money = -1;
}

void DeleteAtList(List *L, IdxType i) {
    for (int j = i; j < LastIdxList(*L); j++) {
        SetList(L, j, GetList(*L, j + 1));
    }
    (*L).A[LastIdxList(*L)].money = -1;
}

void DeleteLastList(List *L) {
    if (!IsEmptyList(*L)) {
        (*L).A[LastIdxList(*L)].money = -1;
    }
}

void CopyWordToCharArray(Word src, char *dest) {
    int i;
    for (i = 0; i < src.Length && i < MAX_LEN - 1; i++) {
        dest[i] = src.TabWord[i];
    }
    dest[i] = '\0'; // Add null-terminator
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

// Concatenate Two Lists
List ConcatList(List L1, List L2) {
    List L3 = MakeList();
    int len1 = LengthList(L1);
    int len2 = LengthList(L2);

    if (len1 + len2 > MaxEl) {
        printf("Error: Resultant list exceeds maximum size.\n");
        return L3;
    }

    for (int i = 0; i < len1; i++) {
        SetList(&L3, i, GetList(L1, i));
    }
    for (int j = 0; j < len2; j++) {
        SetList(&L3, len1 + j, GetList(L2, j));
    }
    return L3;
}

// Print User
void PrintUser(ElType u) {
    printf("{name: %s, password: %s, money: %d}", u.name, u.password, u.money);
}

// Print List
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
