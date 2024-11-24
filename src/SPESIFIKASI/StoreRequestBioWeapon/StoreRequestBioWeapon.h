#ifndef STORE_REQUEST_BIO_WEAPON_H
#define STORE_REQUEST_BIO_WEAPON_H

#include <stdio.h>
#include "../../boolean.h"
#include "../../ADT/ListDinamis/arraydin.h"
#include "../../ADT/MesinKata/mesinkata.h"
#include "../../ADT/MesinKarakter/mesinkarakter.h"
#include "../../ADT/MesinKalimat/mesinkalimat.h"
#include "../../ADT/Kustom/barang.h"
#include "../../ADT/Queue/queue.h"

// I.S. : DNASequence terdefinisi
// F.S. : Mengembalikan RNASequence hasil transkripsi dari DNASequence
Word DNAtoRNA(Word DNASequence);

// I.S. : RNASequence terdefinisi
// F.S. : Mengembalikan ProteinSequence hasil translasi dari RNASequence
Word RNAtoProtein(Word RNASequence);

// I.S. : sequence dan subSequence terdefinisi
// F.S. : Mengembalikan true jika subSequence adalah substring dari sequence, false jika tidak
boolean IsSubstring(Word sequence, Word subSequence);

// I.S. : q terdefinisi, namaBarang terdefinisi
// F.S. : Menambahkan barang dengan nama namaBarang ke dalam queue q
void AddToQueue(Queue *q, Word namaBarang);

// I.S. : barang terdefinisi
// F.S. : Mencetak barang dalam format {name, price}
void PrintBarang(Barang barang);

// I.S. : barangQueue dan barangList terdefinisi
// F.S. : Menambahkan barang ke dalam queue jika validasi berhasil
void StoreRequestBioWeapon(Queue *barangQueue, ArrayDin *barangList);

#endif
