#ifndef __LOAD_H__
#define __LOAD_H__

#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/Kustom/barang.h"
#include "../../ADT/Kustom/user.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/ListDinamis/arraydin.h"
#include "../../ADT/List/list.h"
#include "../../ADT/MesinKalimat/mesinkalimat.h"
#include "../../ADT/Stack/stack.h"
#include "../../ADT/Setmap/setmap.h"
#include "../../ADT/LinkedList/linkedlist.h"

void Load(char *filename, ArrayDin *daftarBarang, List *userList);

#endif