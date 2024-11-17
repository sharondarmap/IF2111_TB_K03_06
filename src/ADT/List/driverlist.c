#include <stdio.h>
#include "list.h"
#include "list.c"

int main() {
    printf("=== DRIVER LIST ===\n\n");

    // Buat list kosong
    printf("[TEST: MakeList]\n");
    List L1 = MakeList();
    printf("List berhasil dibuat.\n");

    // Cek apakah list kosong
    printf("\n[TEST: IsEmpty]\n");
    if (IsEmpty(L1)) {
        printf("List kosong.\n");
    }

    // Tambahkan elemen ke list
    printf("\n[TEST: InsertFirst, InsertLast, InsertAt]\n");
    User u1 = {"Izhar", "pass123", 500};
    User u2 = {"Harfhan", "secure456", 1000};
    User u3 = {"Sharon", "mypassword", 750};
    User u4 = {"Gita", "hello789", 600};

    InsertFirst(&L1, u1);
    printf("Setelah InsertFirst:\n");
    PrintList(L1);

    InsertLast(&L1, u2);
    printf("Setelah InsertLast:\n");
    PrintList(L1);

    InsertAt(&L1, u3, 1);
    printf("Setelah InsertAt indeks 1:\n");
    PrintList(L1);

    // Hapus elemen dari list
    printf("\n[TEST: DeleteFirst, DeleteLast, DeleteAt]\n");
    DeleteFirst(&L1);
    printf("Setelah DeleteFirst:\n");
    PrintList(L1);

    DeleteLast(&L1);
    printf("Setelah DeleteLast:\n");
    PrintList(L1);

    DeleteAt(&L1, 0);
    printf("Setelah DeleteAt indeks 0:\n");
    PrintList(L1);

    // Tes Concat
    printf("\n[TEST: Concat]\n");
    List L2 = MakeList();
    InsertLast(&L2, u4);
    InsertLast(&L2, u3);
    printf("L2:\n");
    PrintList(L2);

    List L3 = Concat(L1, L2);
    printf("Setelah Concat L1 dan L2:\n");
    PrintList(L3);

    // Tes Search
    printf("\n[TEST: Search]\n");
    if (Search(L3, "Gita")) {
        printf("Gita ditemukan di list.\n");
    } else {
        printf("Gita tidak ditemukan di list.\n");
    }

    if (Search(L3, "Harfhan")) {
        printf("Harfhan ditemukan di list.\n");
    } else {
        printf("Harfhan tidak ditemukan di list.\n");
    }

    return 0;
}
