#ifndef __WORK_H__
#define __WORK_H__

#include "load.h"
#include "boolean.h"

typedef struct {
    char nama[100];
    int pendapatan;
    int durasi;
} Job;

void Work(List *userList, IdxType idxUser);

#endif
