#ifndef CART_ADD_H
#define CART_ADD_H

#include <stdio.h>
#include "../../boolean.h"
#include "../../ADT/ListDinamis/arraydin.h"
#include "../../ADT/MesinKata/mesinkata.h"
#include "../../ADT/MesinKarakter/mesinkarakter.h"
#include "../../ADT/MesinKalimat/mesinkalimat.h"
#include "../../ADT/List/list.h"
#include "../../ADT/Kustom/barang.h"
#include "../../ADT/Kustom/user.h"
#include "../../ADT/Setmap/setmap.h"

void CartAdd(List *userList, IdxType currentIndex, Barang *store, int storeCount);


#endif