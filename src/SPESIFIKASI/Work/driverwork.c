#include <stdio.h>
#include "work.h"

int main() {
    // Inisialisasi list pengguna
    List userList = MakeList();

    // Tambahkan pengguna ke dalam List
    InsertLastList(&userList, (User){"Izhar", "pass123", 500});
    InsertLastList(&userList, (User){"Harfhan", "secure456", 1000});
    InsertLastList(&userList, (User){"Sharon", "mypassword", 750});
    InsertLastList(&userList, (User){"Gita", "hello789", 600});

    // Pilih pengguna aktif (misalnya pengguna ke-3)
    int idxUser = 3;

    // Tampilkan informasi awal pengguna
    printf("Selamat datang, %s!\n", userList.A[idxUser].name);
    printf("Saldo Anda saat ini: Rp %d\n", userList.A[idxUser].money);

    // Panggil fungsi Work
    Work(&userList, idxUser);

    // Tampilkan informasi setelah bekerja
    printf("Setelah bekerja, saldo Anda sekarang: Rp %d\n", userList.A[idxUser].money);
    PrintList(userList);

    return 0;
}
