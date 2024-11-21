/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../../boolean.h"

#define MARK '\n'
/* State Mesin */
extern char currentChar;
extern boolean EOP;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC();
/* Mengirimkan currentChar */

boolean IsEOP();
/* Mengirimkan true jika currentChar = MARK */

void ADVFILE();
/* Memajukan pembacaan karakter dari file
   I.S. : currentChar sembarang
   F.S. : currentChar adalah karakter berikutnya dari file
          Jika currentChar adalah karakter terakhir dari file, pita ditutup */

void STARTFILE(char filename[]);
/* Memulai pembacaan karakter dari file
   I.S. : filename adalah nama file yang valid
   F.S. : pita dibuka untuk membaca, currentChar adalah karakter pertama dari file
          Jika file tidak ditemukan, program akan keluar dengan pesan error */

#endif