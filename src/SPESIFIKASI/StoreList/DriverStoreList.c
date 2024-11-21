#include "StoreList.h"
#include "StoreList.c"

int main() {
    ArrayDin barangList = MakeArrayDin();
    
    Barang barang1 = {"Buku", 20000};
    Barang barang2 = {"Pensil", 5000};
    Barang barang3 = {"Buku", 20000}; // Barang duplikat

    InsertLast(&barangList, barang1);
    InsertLast(&barangList, barang2);
    InsertLast(&barangList, barang3);

    StoreList(&barangList);

    return 0;
}