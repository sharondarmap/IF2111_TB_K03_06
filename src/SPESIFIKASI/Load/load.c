#include "load.h"

void Load(char *filename, ArrayDin *daftarBarang, List *userList) {

    STARTKALIMATFILE(filename);

    if (EndKalimat) {
        printf("ERROR: File tidak valid atau tidak ditemukan.\n");
        return;
    }

    /** TAHAP 1: MEMBACA DATA BARANG **/
    // Membaca jumlah barang
    int jumlahBarang = atoi(CLine.TabLine);
    // printf("[DEBUG] Jumlah barang: %d\n", jumlahBarang);

    // Inisialisasi array dinamis
    *daftarBarang = MakeArrayDin();

    // Membaca barang satu per satu
    for (int i = 0; i < jumlahBarang; i++) {
        ADVKALIMAT();
        if (EndKalimat) {
            printf("ERROR: Data barang tidak lengkap.\n");
            return;
        }

        // Parsing data barang
        int harga;
        char nama[MAX_LEN];
        ParseBarang(CLine, &harga, nama);

        // Membuat elemen barang
        Barang barang;
        barang.price = harga;
        CopyWordToCharArray(StringToWord(nama), barang.name);

        // Menambahkan barang ke ArrayDin
        InsertLast(daftarBarang, barang);

        // Debugging informasi barang
        // printf("[DEBUG] Barang ke-%d: {Harga: %d, Nama: %s}\n", i + 1, barang.price, barang.name);
    }

    /** TAHAP 2: MEMBACA DATA PENGGUNA **/
    ADVKALIMAT(); // Pindah ke baris jumlah pengguna
    if (EndKalimat) {
        printf("ERROR: Data pengguna tidak ditemukan.\n");
        return;
    }

    // Membaca jumlah pengguna
    int jumlahUser = atoi(CLine.TabLine);
    // printf("[DEBUG] Jumlah pengguna: %d\n", jumlahUser);

    // Inisialisasi list pengguna
    *userList = MakeList();

    // Membaca data setiap pengguna
    for (int i = 0; i < jumlahUser; i++) {
        ADVKALIMAT(); // Pindah ke baris data pengguna
        if (EndKalimat) {
            printf("ERROR: Data pengguna tidak lengkap.\n");
            return;
        }

        // Parsing data pengguna
        int uang;
        char nama[MAX_LEN];
        char password[MAX_LEN];
        ParseUser(CLine, &uang, nama, password);

        // Membuat elemen pengguna
        User user;
        user.money = uang;
        CopyWordToCharArray(StringToWord(nama), user.name);
        CopyWordToCharArray(StringToWord(password), user.password);

        // Debugging informasi pengguna
        // printf("[DEBUG] Pengguna ke-%d: {Nama: %s, Password: %s, Uang: %d}\n", i + 1, user.name, user.password, user.money);
        CreateEmptyStack(&user.riwayat_pembelian); // Untuk riwayat pembelian
        CreateEmptyWishlist(&user.wishList);      // Untuk wishlist

        /** MEMBACA RIWAYAT PEMBELIAN **/
        ADVKALIMAT(); // Pindah ke baris jumlah riwayat pembelian
        int jumlahRiwayat = atoi(CLine.TabLine);
        // printf("[DEBUG] Jumlah riwayat pembelian pengguna '%s': %d\n", user.name, jumlahRiwayat);

        for (int j = 0; j < jumlahRiwayat; j++) {
            ADVKALIMAT(); // Pindah ke baris riwayat berikutnya
            if (EndKalimat) {
                printf("ERROR: Data riwayat pembelian tidak lengkap untuk pengguna '%s'.\n", user.name);
                return;
            }

            // Debug baris yang sedang diproses
            // printf("[DEBUG] Membaca riwayat pembelian ke-%d untuk '%s': %s\n", j + 1, user.name, CLine.TabLine);

            // Parsing data riwayat
            int biaya;
            char barang[MAX_LEN];
            ParseBarang(CLine, &biaya, barang);

            // Debug hasil parsing
            // printf("[DEBUG] Parsed riwayat: {Biaya: %d, Barang: %s}\n", biaya, barang);

            // Validasi hasil parsing
            if (biaya <= 0 || barang[0] == '\0') {
                printf("ERROR: Data riwayat pembelian tidak valid: {Biaya: %d, Barang: %s}\n", biaya, barang);
                return;
            }

            // Tambahkan ke stack riwayat pembelian
            Barang riwayatBarang;
            riwayatBarang.price = biaya;
            CopyWordToCharArray(StringToWord(barang), riwayatBarang.name);

            // Debug sebelum push
            // printf("[DEBUG] Menambahkan ke stack: {Biaya: %d, Barang: %s}\n", riwayatBarang.price, riwayatBarang.name);

            // Push elemen ke stack
            PushToStack(&user.riwayat_pembelian, riwayatBarang);

            // Debug setelah push
            // printf("[DEBUG] Riwayat ke-%d ditambahkan: {Biaya: %d, Barang: %s}\n", j + 1, riwayatBarang.price, riwayatBarang.name);
        }

        /** MEMBACA WISHLIST **/
        ADVKALIMAT(); // Pindah ke baris jumlah wishlist

        int jumlahWishlist = atoi(CLine.TabLine);
        // printf("[DEBUG] Jumlah wishlist pengguna '%s': %d\n", user.name, jumlahWishlist);

        for (int j = 0; j < jumlahWishlist; j++) {
            ADVKALIMAT();
            if (EndKalimat) {
                printf("ERROR: EOF tercapai saat membaca wishlist pengguna '%s'.\n", user.name);
                return;
            }

            // Parsing wishlist
            char wishlistBarang[MAX_LEN];
            CopyWordToCharArray(StringToWord(CLine.TabLine), wishlistBarang);

            if (wishlistBarang[0] == '\0') {
                printf("ERROR: Data wishlist tidak valid untuk pengguna '%s'.\n", user.name);
                return;
            }

            // Tambahkan ke wishlist
            Barang wishlistItem;
            CopyWordToCharArray(StringToWord(wishlistBarang), wishlistItem.name);
            InsertLastWishlist(&user.wishList, wishlistItem);

            // Debug setelah menambahkan wishlist
            // printf("[DEBUG] Wishlist ke-%d ditambahkan: %s\n", j + 1, wishlistItem.name);
        }

        // Tambahkan pengguna ke List
        InsertLastList(userList, user);
    }
    // printf("[DEBUG] Semua pengguna berhasil dimuat ke dalam List.\n\n");
}

