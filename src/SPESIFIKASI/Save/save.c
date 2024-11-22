#include "save.h"

void Save(ArrayDin *barang, List *userList, char *filename) {
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
    printf("Data berhasil disimpan ke '%s'.\n", filename);
}