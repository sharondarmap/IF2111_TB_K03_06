#ifndef __WORK_H__
#define __WORK_H__

#include "../../ADT/MesinKata/mesinkata.h"
#include "../../ADT/MesinKarakter/mesinkarakter.h"
#include "../../ADT/Kustom/user.h"
#include "../../ADT/List/list.h"
#include "../../boolean.h"

typedef struct {
    char nama[100];
    int pendapatan;
    int durasi;
} Job;

void Work(List *userList, IdxType idxUser);

#endif

