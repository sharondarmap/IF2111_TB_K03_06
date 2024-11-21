#ifndef __LOAD_H__
#define __LOAD_H__

#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/Kustom/barang.h"
#include "../../ADT/Kustom/user.h"
#include "../../ADT/MesinKarakter/mesinkarakter.h"
#include "../../ADT/MesinKarakter/mesinkarakter.c"
#include "../../ADT/MesinKata/mesinkata.h"
#include "../../ADT/MesinKata/mesinkata.c"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/Queue/queue.c"
#include "../../ADT/List/arraydin.h"
#include "../../ADT/List/arraydin.c"
#include "../../ADT/List/list.h"
#include "../../ADT/List/list.c"
#include "../../ADT/MesinKalimat/MesinKalimat.h"
#include "../../ADT/MesinKalimat/MesinKalimat.c"

void Load(char *filename, ArrayDin *daftarBarang, List *userList);

#endif