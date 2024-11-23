#ifndef REGISTER_H
#define REGISTER_H

#include <stdio.h>
#include "../../ADT/MesinKata/mesinkata.h"
#include "../../ADT/List/list.h"
#include "../../ADT/Kustom/user.h"

// Deklarasi fungsi untuk REGISTER
void RegisterUser(List *userList);
/* Fungsi untuk melakukan registrasi pengguna baru.
   I.S. : List pengguna sudah terdefinisi (userList).
   F.S. : Jika username valid dan belum ada dalam list, pengguna baru ditambahkan ke userList.
          Jika username tidak valid atau sudah ada, pesan kesalahan ditampilkan.
*/

#endif