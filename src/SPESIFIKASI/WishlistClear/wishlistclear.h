#ifndef WISHLISTCLEAR_H
#define WISHLISTCLEAR_H

#include <stdio.h>
#include "../../boolean.h"
#include "../../ADT/ListDinamis/arraydin.h"
#include "../../ADT/MesinKata/mesinkata.h"
#include "../../ADT/MesinKarakter/mesinkarakter.h"
#include "../../ADT/MesinKalimat/mesinkalimat.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/Kustom/barang.h"
#include "../../ADT/Kustom/user.h"
#include "../../ADT/List/list.h"
#include "../../ADT/Setmap/setmap.h"

void WishlistClear(Linkedlist *wishList);
/**
 * I.S.: Wishlist terisi dengan beberapa barang.
 * F.S.: Semua barang di dalam wishlist dihapus, jumlah barang menjadi nol.
 */

#endif