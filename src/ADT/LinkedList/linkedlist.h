#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../../boolean.h"
#include "../Kustom/barang.h"


#define NIL NULL
#define MAX_CAPACITY 10

typedef struct tElmtlist *addr_listdp;
typedef struct tElmtlist
{
    Barang wish;
    addr_listdp next;
    addr_listdp prev;
} ElmtList;

typedef struct
{
    addr_listdp First;
    addr_listdp Last;
    int count;
} Linkedlist;

/* Notasi Akses */
#define Wish(P) (P)->wish
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)
#define Count(L) ((L).count)

/* Function Prototypes */
void CreateEmptyWishlist(Linkedlist *L);

boolean WishlistIsEmpty(Linkedlist L);

addr_listdp AlokasiWishList(Barang X);

void DealokasiWishList(addr_listdp P);

void AddLastWishlist(Linkedlist *L, Barang X);

void DealokasiWishList(addr_listdp P);

/**
 * IS: wishList terdefinisi
 * FS: Semua elemen dalam wishList dicetak ke layar
 */
void PrintWishlist(Linkedlist wishList);

/**
 * IS: wishList terdefinisi, item terdefinisi
 * FS: item ditambahkan ke akhir wishList
 */
void InsertLastWishlist(Linkedlist *wishList, Barang item);

#endif