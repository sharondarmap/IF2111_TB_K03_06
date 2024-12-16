#include "setmap.h"
#include "../List/list.h"
#include <stdlib.h> 

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

void CreateEmptyKeranjang(Map *M) {
    M->Elements = (item*) malloc(MaxEl * sizeof(item));  // Allocate memory for Elements dynamically
    if (M->Elements == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);  // Exit if memory allocation fails
    }
    M->Count = 0;
}

// Check if the Keranjang (Cart) is empty
boolean IsKeranjangEmpty(Map M) {
    return M.Count == 0;
}

// Check if the Keranjang (Cart) is full
boolean IsKeranjangFull(Map M) {
    return M.Count == MaxEl;
}

// Check if the item is in the Keranjang (Cart)
boolean IsItemInKeranjang(Map M, Barang barang) {
    for (int i = 0; i < M.Count; i++) {
        if (CompareStrings(M.Elements[i].Key.name, barang.name)) {
            return true;
        }
    }
    return false;
}

// Get the quantity of an item in the Keranjang (Cart)
int GetItemQuantity(Map M, Barang barang) {
    for (int i = 0; i < M.Count; i++) {
        if (CompareStrings(M.Elements[i].Key.name, barang.name)) {
            return M.Elements[i].Quantity;
        }
    }
    return 0;
}

// Add an item to the Keranjang (Cart)
void AddToKeranjang(Map *M, Barang barang, int quantity) {
    // If cart is full, can't add more items
    if (IsKeranjangFull(*M)) {
        printf("Keranjang penuh! Tidak bisa menambah barang.\n");
        return;
    }

    // Check if item already exists
    for (int i = 0; i < M->Count; i++) {
        if (CompareStrings(M->Elements[i].Key.name, barang.name)) {
            // Item exists, increase quantity
            M->Elements[i].Quantity += quantity;
            return;
        }
    }

    // If item doesn't exist, add new item
    M->Elements[M->Count].Key = barang;
    M->Elements[M->Count].Quantity = quantity;
    M->Count++;
}

// Remove an item from the Keranjang (Cart)
void RemoveFromKeranjang(Map *M, Barang barang) {
    for (int i = 0; i < M->Count; i++) {
        if (CompareStrings(M->Elements[i].Key.name, barang.name)) {
            for (int j = i; j < M->Count - 1; j++) {
                M->Elements[j] = M->Elements[j + 1];
            }
            M->Count--;
            return;
        }
    }
}

// Update the quantity of an item in the Keranjang (Cart)
void UpdateKeranjangItemQuantity(Map *M, Barang barang, int newQuantity) {
    for (int i = 0; i < M->Count; i++) {
        if (CompareStrings(M->Elements[i].Key.name, barang.name)) {
            if (newQuantity <= 0) { //mengurangi Jumlah
                RemoveFromKeranjang(M, barang);
            } else {
                M->Elements[i].Quantity = newQuantity;
            }
            return;
        }
    }
}

// Calculate the total price of items in the Keranjang (Cart)
int HitungTotalHargaKeranjang(Map M) {
    int totalHarga = 0;
    for (int i = 0; i < M.Count; i++) {
        totalHarga += M.Elements[i].Key.price * M.Elements[i].Quantity;
    }
    return totalHarga;
}

// Display the contents of the Keranjang (Cart)
void TampilkanKeranjang(Map M) {
    if (IsKeranjangEmpty(M)) {
        printf("Keranjang kosong.\n");
        return;
    }

    // Top border
    printf("+------------+-----------------+------------+\n");
    printf("| Kuantitas  | Nama Barang     | Total      |\n");
    printf("+------------+-----------------+------------+\n");

    // Items
    int totalHarga = 0;
    for (int i = 0; i < M.Count; i++) {
        int subtotal = M.Elements[i].Quantity * M.Elements[i].Key.price;
        totalHarga += subtotal;
        
        printf("| %-10d | %-15s | %-10d |\n", 
               M.Elements[i].Quantity, 
               M.Elements[i].Key.name, 
               subtotal);
    }
    printf("+------------+-----------------+------------+\n");
}

// Free dynamically allocated memory for Map
void FreeKeranjang(Map *M) {
    free(M->Elements);  // Free the dynamically allocated memory
}
