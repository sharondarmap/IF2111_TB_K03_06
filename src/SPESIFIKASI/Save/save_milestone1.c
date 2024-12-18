#include "save.h"

void Save(ArrayDin *barang, List *userList, char *filename) {
    // Meminta input nama file dari pengguna
    boolean valid = false;
    while (!valid) {
        printf("Masukkan nama file untuk menyimpan data (harus .txt dan tidak berawalan 'default'): ");
        STARTWORD(); // Gunakan mesin kata untuk membaca nama file
        for (int i = 0; i < currentWord.Length; i++) {
            filename[i] = currentWord.TabWord[i];
        }
        filename[currentWord.Length] = '\0'; // Null-terminate string

        // Validasi nama file
        valid = true;

        // Periksa apakah nama file berakhiran .txt
        int len = currentWord.Length;
        if (!(len > 4 &&
              filename[len - 4] == '.' &&
              filename[len - 3] == 't' &&
              filename[len - 2] == 'x' &&
              filename[len - 1] == 't')) {
            printf("Nama file harus berakhiran .txt!\n");
            valid = false;
        }

        // Periksa apakah nama file berawalan default
        char defaultPrefix[] = "default";
        int prefixLength = 7; // Panjang "default"
        boolean isDefaultPrefix = true;

        if (len >= prefixLength) { // Hanya periksa jika panjang mencukupi
            for (int i = 0; i < prefixLength; i++) {
                if (filename[i] != defaultPrefix[i]) {
                    isDefaultPrefix = false;
                    break;
                }
            }
        } else {
            isDefaultPrefix = false; // Jika panjang kurang dari 7, pasti bukan prefix
        }

        if (isDefaultPrefix) {
            printf("Nama file tidak boleh berawalan 'default'!\n");
            valid = false;
        }

        if (!valid) {
            printf("Silakan coba lagi.\n");
        }
    }

    FILE *file;
    STARTWRITEKALIMATFILE(&file, filename);

    if (file == NULL) {
        printf("\nGAGAL MENYIMPAN FILE\n\n");
        return;
    }

    Kalimat kalimat;

    // Menulis jumlah barang
    kalimat.Length = 0;
    Word jumlahBarangWord = IntToWord(Length(*barang));
    for (int i = 0; i < jumlahBarangWord.Length; i++) {
        kalimat.TabLine[kalimat.Length++] = jumlahBarangWord.TabWord[i];
    }
    kalimat.TabLine[kalimat.Length] = '\0';
    WRITELINEFILE(file, kalimat);

    // Menulis data barang
    for (int i = 0; i < Length(*barang); i++) {
        Barang b = Get(*barang, i);

        kalimat.Length = 0;
        Word hargaWord = IntToWord(b.price);
        for (int j = 0; j < hargaWord.Length; j++) {
            kalimat.TabLine[kalimat.Length++] = hargaWord.TabWord[j];
        }
        kalimat.TabLine[kalimat.Length++] = ' '; // Tambahkan spasi
        Word namaWord = StringToWord(b.name);
        for (int j = 0; j < namaWord.Length; j++) {
            kalimat.TabLine[kalimat.Length++] = namaWord.TabWord[j];
        }
        kalimat.TabLine[kalimat.Length] = '\0';
        WRITELINEFILE(file, kalimat);
    }

    // Menulis jumlah pengguna
    kalimat.Length = 0;
    Word jumlahUserWord = IntToWord(LengthList(*userList));
    for (int i = 0; i < jumlahUserWord.Length; i++) {
        kalimat.TabLine[kalimat.Length++] = jumlahUserWord.TabWord[i];
    }
    kalimat.TabLine[kalimat.Length] = '\0';
    WRITELINEFILE(file, kalimat);

    // Menulis data pengguna
    for (int i = 0; i < LengthList(*userList); i++) {
        User u = GetList(*userList, i);

        kalimat.Length = 0;
        Word uangWord = IntToWord(u.money);
        for (int j = 0; j < uangWord.Length; j++) {
            kalimat.TabLine[kalimat.Length++] = uangWord.TabWord[j];
        }
        kalimat.TabLine[kalimat.Length++] = ' '; // Tambahkan spasi
        Word namaWord = StringToWord(u.name);
        for (int j = 0; j < namaWord.Length; j++) {
            kalimat.TabLine[kalimat.Length++] = namaWord.TabWord[j];
        }
        kalimat.TabLine[kalimat.Length++] = ' '; // Tambahkan spasi
        Word passwordWord = StringToWord(u.password);
        for (int j = 0; j < passwordWord.Length; j++) {
            kalimat.TabLine[kalimat.Length++] = passwordWord.TabWord[j];
        }
        kalimat.TabLine[kalimat.Length] = '\0';
        WRITELINEFILE(file, kalimat);
    }

    CLOSEWRITEKALIMATFILE(file);
}