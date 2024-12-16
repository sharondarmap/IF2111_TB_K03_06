#include "../../boolean.h"

#ifndef SETMAP_H
#define SETMAP_H

#include "../Kustom/barang.h"

#define MaxEl 100

typedef struct {
    Barang Key;   // Key is a Barang type
    int Quantity; // Quantity of the item in the cart
} item;

typedef struct {
    item *Elements; // Dynamically allocated array of items
    int Count;       // Current count of items in the cart
} Map;

// Function declarations
void CreateEmptyKeranjang(Map *M);
boolean IsKeranjangEmpty(Map M);
boolean IsKeranjangFull(Map M);
boolean IsItemInKeranjang(Map M, Barang barang);
int GetItemQuantity(Map M, Barang barang);
void AddToKeranjang(Map *M, Barang barang, int quantity);
void RemoveFromKeranjang(Map *M, Barang barang);
void UpdateKeranjangItemQuantity(Map *M, Barang barang, int newQuantity);
int HitungTotalHargaKeranjang(Map M);
void TampilkanKeranjang(Map M);
void FreeKeranjang(Map *M); // Free dynamically allocated memory for cart

#endif