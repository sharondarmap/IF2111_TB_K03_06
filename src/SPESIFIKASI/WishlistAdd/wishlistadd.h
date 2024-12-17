#ifndef WISHLISTADD_H
#define WISHLISTADD_H

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


/* Prototipe Fungsi WishlistAdd */

/* 
   Fungsi: WishlistAdd
   Deskripsi:
   - Menambahkan barang ke wishlist pengguna jika barang ada di toko dan belum ada di wishlist.
   - Menggunakan ADT LinkedList untuk menyimpan wishlist.
   - Input nama barang diambil menggunakan ADT Mesin Kata.

   I.S.:
   - user terdefinisi (berisi atribut LinkedList wishlist yang sudah diinisialisasi).
   - barangToko adalah array barang yang tersedia di toko.
   - jumlahBarangToko adalah jumlah barang yang ada di array barangToko.

   F.S.:
   - Barang ditambahkan ke wishlist jika valid.
   - Pesan keberhasilan atau kegagalan dicetak ke layar.

   Parameter:
   - User *user: Pointer ke pengguna yang wishlist-nya akan diubah.
   - Barang *barangToko: Array barang yang tersedia di toko.
   - int jumlahBarangToko: Jumlah barang di array barangToko.
*/
void WishlistAdd(User *user, Barang *barangToko, int jumlahBarangToko);

#endif
