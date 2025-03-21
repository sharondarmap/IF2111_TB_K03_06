#ifndef USER_H
#define USER_H

/* Kamus Umum */
#define MAX_LEN 100

#include "../LinkedList/linkedlist.h"
#include "../Stack/stack.h"
#include "../Setmap/setmap.h"


typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
  Map keranjang;
  Stack riwayat_pembelian;
  Linkedlist wishList;
} User;

#endif