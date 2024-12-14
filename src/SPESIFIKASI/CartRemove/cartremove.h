#ifndef CART_REMOVE_H
#define CART_REMOVE_H

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

void CartRemove(List *userList, IdxType currentIndex, Barang currentBarang, int jumlah);


#endif