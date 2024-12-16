#include <stdio.h>
#include <stdlib.h>
#include "setmap.h"

// Function to compare two strings
int CompareStringsSetmap(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

// Initialize an empty cart
void CreateEmptyKeranjang(Map *M) {
    M->Count = 0;
    M->Elements = (item*) malloc(MaxEl * sizeof(item));  // Dynamically allocate memory for Elements
    if (M->Elements == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);  // Exit if memory allocation fails
    }
}

// Check if the cart is empty
boolean IsKeranjangEmpty(Map M) {
    return M.Count == 0;
}

// Check if the cart is full
boolean IsKeranjangFull(Map M) {
    return M.Count == MaxEl;
}

// Check if the item exists in the cart
boolean IsItemInKeranjang(Map M, Barang barang) {
    for (int i = 0; i < M.Count; i++) {
        if (CompareStringsSetmap(M.Elements[i].Key.name, barang.name)) {
            return true;
        }
    }
    return false;
}

// Get the quantity of an item in the cart
int GetItemQuantity(Map M, Barang barang) {
    for (int i = 0; i < M.Count; i++) {
        if (CompareStringsSetmap(M.Elements[i].Key.name, barang.name)) {
            return M.Elements[i].Quantity;
        }
    }
    return 0;
}

// Add an item to the cart
void AddToKeranjang(Map *M, Barang barang, int quantity) {
    if (IsKeranjangFull(*M)) {
        printf("Keranjang penuh! Tidak bisa menambah barang.\n");
        return;
    }

    for (int i = 0; i < M->Count; i++) {
        if (CompareStringsSetmap(M->Elements[i].Key.name, barang.name)) {
            M->Elements[i].Quantity += quantity;
            return;
        }
    }

    M->Elements[M->Count].Key = barang;
    M->Elements[M->Count].Quantity = quantity;
    M->Count++;
}

// Remove an item from the cart
void RemoveFromKeranjang(Map *M, Barang barang) {
    for (int i = 0; i < M->Count; i++) {
        if (CompareStringsSetmap(M->Elements[i].Key.name, barang.name)) {
            for (int j = i; j < M->Count - 1; j++) {
                M->Elements[j] = M->Elements[j + 1];
            }
            M->Count--;
            return;
        }
    }
}

// Update the quantity of an item in the cart
void UpdateKeranjangItemQuantity(Map *M, Barang barang, int newQuantity) {
    for (int i = 0; i < M->Count; i++) {
        if (CompareStringsSetmap(M->Elements[i].Key.name, barang.name)) {
            if (newQuantity <= 0) {
                RemoveFromKeranjang(M, barang);
            } else {
                M->Elements[i].Quantity = newQuantity;
            }
            return;
        }
    }
}

// Calculate the total price of items in the cart
int HitungTotalHargaKeranjang(Map M) {
    int totalHarga = 0;
    for (int i = 0; i < M.Count; i++) {
        totalHarga += M.Elements[i].Key.price * M.Elements[i].Quantity;
    }
    return totalHarga;
}

// Display the items in the cart
void TampilkanKeranjang(Map M) {
    if (IsKeranjangEmpty(M)) {
        printf("Keranjang kosong.\n");
        return;
    }

    printf("+------------+-----------------------+------------+\n");
    printf("| Kuantitas  | Nama Barang           | Total      |\n");
    printf("+------------+-----------------------+------------+\n");

    int totalHarga = 0;
    for (int i = 0; i < M.Count; i++) {
        int subtotal = M.Elements[i].Quantity * M.Elements[i].Key.price;
        totalHarga += subtotal;
        
        printf("| %-10d | %-21s | %-10d |\n", 
               M.Elements[i].Quantity, 
               M.Elements[i].Key.name, 
               subtotal);
    }
    printf("+------------+-----------------------+------------+\n");
}

// Free dynamically allocated memory
void FreeKeranjang(Map *M) {
    free(M->Elements);  // Free the allocated memory
}