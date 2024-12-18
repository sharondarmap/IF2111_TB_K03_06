#ifndef WISHLISTSHOW_H
#define WISHLISTSHOW_H

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

void wishlistShow(Linkedlist *wishList);
/**
 * Fungsi untuk menampilkan isi wishlist.
 * I.S.: Wishlist terisi atau kosong.
 * F.S.: Jika wishlist terisi, seluruh barang dalam wishlist ditampilkan.
 *       Jika wishlist kosong, pesan bahwa wishlist kosong ditampilkan.
 */

#endif