#ifndef STORE_REQUEST_H
#define STORE_REQUEST_H

#include <stdio.h>
#include "../../boolean.h"
#include "../../ADT/List/arraydin.h"
#include "../../ADT/MesinKata/mesinkata.h"
#include "../../ADT/Queue/queue.h"

void StoreRequest(Queue *barangQueue, ArrayDin *barangToko);
/*
I.S.: requestQueue mungkin kosong atau terisi.
F.S.: Barang baru ditambahkan ke requestQueue.
*/
#endif
