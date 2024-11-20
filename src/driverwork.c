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

    // Pilih pengguna aktif (misalnya pengguna pertama)
    User *currentUser = &userList.A[3];

    // Tampilkan informasi awal pengguna
    printf("Selamat datang, %s!\n", currentUser->name);
    printf("Saldo Anda saat ini: Rp %d\n", currentUser->money);

    // Panggil fungsi Work
    Work(&userList, currentUser);

    // Tampilkan informasi setelah bekerja
    printf("Setelah bekerja, saldo Anda sekarang: Rp %d\n", currentUser->money);

    return 0;
}
