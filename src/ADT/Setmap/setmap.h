#ifndef map_H
#define map_H
#include <stdio.h>
#include "../../boolean.h"
#include "../Kustom/barang.h"

#define MaxElem 10
#define Undefined -999

typedef struct {
    Barang Key;   
    int Quantity; 
} item;

typedef struct {
    item Elements[MaxElem];
    int Count;
} Map;


int CompareStrings(char *s1, char *s2);

void CreateEmptyKeranjang(Map *M);

boolean IsKeranjangEmpty(Map M);

boolean IsKeranjangFull(Map M);

boolean IsItemInKeranjang(Map M, Barang barang);

int GetItemIndex(Map *M, Barang barang);

int GetItemQuantity(Map M, Barang barang);

void AddToKeranjang(Map *M, Barang barang, int quantity);

void RemoveFromKeranjang(Map *M, Barang barang);

void UpdateKeranjangItemQuantity(Map *M, Barang barang, int newQuantity);

int HitungTotalHargaKeranjang(Map M);

void TampilkanKeranjang(Map M);

#endif