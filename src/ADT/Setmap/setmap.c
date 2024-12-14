#include "setmap.h"
#include "../List/list.h"

void CreateEmptyKeranjang(Map *M) {
    M->Count = 0;
}

boolean IsKeranjangEmpty(Map M) {
    return M.Count == 0;
}

boolean IsKeranjangFull(Map M) {
    return M.Count == MaxEl;
}

boolean IsItemInKeranjang(Map M, Barang barang) {
    for (int i = 0; i < M.Count; i++) {
        if (CompareStrings(M.Elements[i].Key.name, barang.name)) {
            return true;
        }
    }
    return false;
}

int GetItemIndex(Map *M, Barang barang) {
    for (int i = 0; i < M->Count; i++) {
        if (CompareStrings(M->Elements[i].Key.name, barang.name)) {
            return i;  // Return the index if item exists
        }
    }
    return -1;  // Return -1 if item not found
}

int GetItemQuantity(Map M, Barang barang) {
    for (int i = 0; i < M.Count; i++) {
        if (CompareStrings(M.Elements[i].Key.name, barang.name)) {
            return M.Elements[i].Quantity;
        }
    }
    return 0;
}

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

int HitungTotalHargaKeranjang(Map M) {
    int totalHarga = 0;
    for (int i = 0; i < M.Count; i++) {
        totalHarga += M.Elements[i].Key.price * M.Elements[i].Quantity;
    }
    return totalHarga;
}

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
    