#ifndef STORE_SUPPLY_H
#define STORE_SUPPLY_H

#include "../../boolean.h"
#include "../../ADT/List/arraydin.h"
#include "../../ADT/MesinKata/mesinkata.h"
#include "../../ADT/Queue/queue.h"

void StoreSupply(Queue *barangQueue, ArrayDin *barangList);
/*
I.S.: requestQueue berisi barang; itemList terisi data barang.
F.S.: Barang dari requestQueue ditambahkan ke itemList.
*/
#endif