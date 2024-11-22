#ifndef SAVE_H
#define SAVE_H


#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/Kustom/barang.h"
#include "../../ADT/Kustom/user.h"
#include "../../ADT/MesinKarakter/mesinkarakter.h"
#include "../../ADT/MesinKata/mesinkata.h"
#include "../../ADT/List/arraydin.h"
#include "../../ADT/List/list.h"
#include "../../ADT/MesinKalimat/mesinkalimat.h"

void Save(ArrayDin *barang, List *userList, char *fileName);

#endif