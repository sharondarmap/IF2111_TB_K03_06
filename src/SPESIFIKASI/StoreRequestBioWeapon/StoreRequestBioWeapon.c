#include "StoreRequestBioWeapon.h"

/* Fungsi Transkripsi DNA ke RNA */
Word DNAtoRNA(Word DNASequence) {
    Word RNASequence;
    RNASequence.Length = DNASequence.Length;

    for (int i = 0; i < DNASequence.Length; i++) {
        char ch = DNASequence.TabWord[i];
        if (ch == 'A') RNASequence.TabWord[i] = 'U';
        else if (ch == 'T') RNASequence.TabWord[i] = 'A';
        else if (ch == 'C') RNASequence.TabWord[i] = 'G';
        else if (ch == 'G') RNASequence.TabWord[i] = 'C';
    }

    // Debug: Transkripsi selesai
    // printf("[DEBUG] Transkripsi DNA ke RNA selesai.\n");

    return RNASequence;
}

Word RNAtoProtein(Word RNASequence) {
    Word ProteinSequence;
    ProteinSequence.Length = 0;

    for (int i = 0; i <= RNASequence.Length - 3; i += 3) {
        char codon[3] = {RNASequence.TabWord[i], RNASequence.TabWord[i + 1], RNASequence.TabWord[i + 2]};
        char aminoAcid = '-'; // Default untuk kodon tidak dikenal

        // Definisi kodon dan asam amino berdasarkan tabel
        if (codon[0] == 'A' && codon[1] == 'U' && codon[2] == 'G') aminoAcid = 'M'; // Metionin (Start)
        else if (codon[0] == 'U' && codon[1] == 'U' && (codon[2] == 'U' || codon[2] == 'C')) aminoAcid = 'F'; // Fenilalanin
        else if (codon[0] == 'U' && codon[1] == 'U' && (codon[2] == 'A' || codon[2] == 'G')) aminoAcid = 'L'; // Leusin
        else if (codon[0] == 'C' && codon[1] == 'U' && (codon[2] == 'U' || codon[2] == 'C' || codon[2] == 'A' || codon[2] == 'G')) aminoAcid = 'L'; // Leusin
        else if (codon[0] == 'A' && codon[1] == 'U' && (codon[2] == 'U' || codon[2] == 'C' || codon[2] == 'A')) aminoAcid = 'I'; // Isoleusin
        else if (codon[0] == 'G' && codon[1] == 'U' && (codon[2] == 'U' || codon[2] == 'C' || codon[2] == 'A' || codon[2] == 'G')) aminoAcid = 'V'; // Valin
        else if (codon[0] == 'U' && codon[1] == 'C' && (codon[2] == 'U' || codon[2] == 'C' || codon[2] == 'A' || codon[2] == 'G')) aminoAcid = 'S'; // Serin
        else if (codon[0] == 'C' && codon[1] == 'C' && (codon[2] == 'U' || codon[2] == 'C' || codon[2] == 'A' || codon[2] == 'G')) aminoAcid = 'P'; // Prolin
        else if (codon[0] == 'A' && codon[1] == 'C' && (codon[2] == 'U' || codon[2] == 'C' || codon[2] == 'A' || codon[2] == 'G')) aminoAcid = 'T'; // Treonin
        else if (codon[0] == 'G' && codon[1] == 'C' && (codon[2] == 'U' || codon[2] == 'C' || codon[2] == 'A' || codon[2] == 'G')) aminoAcid = 'A'; // Alanin
        else if (codon[0] == 'U' && codon[1] == 'A' && (codon[2] == 'U' || codon[2] == 'C')) aminoAcid = 'Y'; // Tirosin
        else if (codon[0] == 'C' && codon[1] == 'A' && (codon[2] == 'U' || codon[2] == 'C')) aminoAcid = 'H'; // Histidin
        else if (codon[0] == 'C' && codon[1] == 'A' && (codon[2] == 'A' || codon[2] == 'G')) aminoAcid = 'Q'; // Glutamin
        else if (codon[0] == 'A' && codon[1] == 'A' && (codon[2] == 'U' || codon[2] == 'C')) aminoAcid = 'N'; // Asparagin
        else if (codon[0] == 'A' && codon[1] == 'A' && (codon[2] == 'A' || codon[2] == 'G')) aminoAcid = 'K'; // Lisin
        else if (codon[0] == 'G' && codon[1] == 'A' && (codon[2] == 'U' || codon[2] == 'C')) aminoAcid = 'D'; // Asam Aspartat
        else if (codon[0] == 'G' && codon[1] == 'A' && (codon[2] == 'A' || codon[2] == 'G')) aminoAcid = 'E'; // Asam Glutamat
        else if (codon[0] == 'U' && codon[1] == 'G' && codon[2] == 'G') aminoAcid = 'W'; // Triptofan
        else if (codon[0] == 'C' && codon[1] == 'G' && (codon[2] == 'U' || codon[2] == 'C' || codon[2] == 'A' || codon[2] == 'G')) aminoAcid = 'R'; // Arginin
        else if (codon[0] == 'A' && codon[1] == 'G' && (codon[2] == 'U' || codon[2] == 'C')) aminoAcid = 'S'; // Serin
        else if (codon[0] == 'A' && codon[1] == 'G' && (codon[2] == 'A' || codon[2] == 'G')) aminoAcid = 'R'; // Arginin
        else if (codon[0] == 'G' && codon[1] == 'G' && (codon[2] == 'U' || codon[2] == 'C' || codon[2] == 'A' || codon[2] == 'G')) aminoAcid = 'G'; // Glisin
        else if ((codon[0] == 'U' && codon[1] == 'A' && (codon[2] == 'A' || codon[2] == 'G')) || (codon[0] == 'U' && codon[1] == 'G' && codon[2] == 'A')) continue; // STOP

        // Debug: Cetak kodon dan hasil translasi
        // printf("[DEBUG] Kodon: %c%c%c -> Amino Acid: %c\n", codon[0], codon[1], codon[2], aminoAcid);

        // Tambahkan ke ProteinSequence
        ProteinSequence.TabWord[ProteinSequence.Length++] = aminoAcid;
    }

    // printf("[DEBUG] Translasi RNA ke Protein selesai.\n");
    return ProteinSequence;
}

/* Fungsi Validasi Kode Rahasia */
boolean IsSubstring(Word sequence, Word subSequence) {
    if (subSequence.Length > sequence.Length) return false;

    for (int i = 0; i <= sequence.Length - subSequence.Length; i++) {
        boolean match = true;
        for (int j = 0; j < subSequence.Length; j++) {
            if (sequence.TabWord[i + j] != subSequence.TabWord[j]) {
                match = false;
                break;
            }
        }

        // Debug: Tampilkan pencocokan substring
        // printf("[DEBUG] Memeriksa substring mulai indeks %d: %s\n", i, match ? "Cocok" : "Tidak Cocok");

        if (match) return true;
    }

    return false;
}

/* Fungsi untuk Menambahkan Barang ke Queue */
void AddToQueue(Queue *q, Word namaBarang) {
    Barang newBarang;

    // Mengisi nama barang dari TabWord
    for (int i = 0; i < namaBarang.Length; i++) {
        newBarang.name[i] = namaBarang.TabWord[i];
    }
    newBarang.name[namaBarang.Length] = '\0'; // Null-terminator untuk string

    // Isi harga barang (price) dengan nilai default
    newBarang.price = 0;

    // Debug: Cetak nama dan harga sebelum enqueue
    // printf("[DEBUG] Barang '%s' dengan harga %d siap ditambahkan ke queue.\n", newBarang.name, newBarang.price);

    // Tambahkan barang ke queue
    enqueue(q, newBarang);

    // Debug: Barang berhasil ditambahkan
    // printf("[DEBUG] Barang '%s' telah ditambahkan ke dalam queue.\n", newBarang.name);
}

/* Fungsi untuk mencetak barang */
void PrintBarang(Barang barang) {
    printf("{%s, %d}\n", barang.name, barang.price);
}

void StoreRequestBioWeapon(Queue *barangQueue, ArrayDin *barangList) {
    printf("Nama barang yang diminta: ");
    STARTWORD(); // Membaca nama barang
    Word namaBarang = currentWord;

    // Lanjut membaca jika nama barang lebih dari satu kata
    while (!isEndWord()) {
        ADVWORD();
        if (!isEndWord()) {
            namaBarang.TabWord[namaBarang.Length++] = ' '; // Tambahkan spasi
            for (int i = 0; i < currentWord.Length; i++) {
                namaBarang.TabWord[namaBarang.Length++] = currentWord.TabWord[i];
            }
        }
    }
    namaBarang = TrimWord(namaBarang); // Hapus spasi berlebih

    // Validasi input kosong
    if (namaBarang.Length == 0) {
        printf("Nama barang tidak boleh kosong!\n");
        return;
    }

    boolean isInStore = false;
    boolean isInQueue = false;

    // Cek apakah barang sudah ada di toko
    for (int i = 0; i < (*barangList).Neff; i++) {
        Word barangListName = StringToWord((*barangList).A[i].name);
        if (IsWordEqual(barangListName, namaBarang)) {
            isInStore = true;
            break;
        }
    }

    // Cek apakah barang sudah ada di queue
    if (!isInStore && !isEmpty(*barangQueue)) {
        int queueLen = length(*barangQueue);
        for (int i = 0; i < queueLen; i++) {
            Barang tempBarang;
            dequeue(barangQueue, &tempBarang);
            Word queueName = StringToWord(tempBarang.name);
            enqueue(barangQueue, tempBarang); // Masukkan kembali ke queue
            if (IsWordEqual(queueName, namaBarang)) {
                isInQueue = true;
            }
        }
    }

    if (isInStore) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
        return;
    }

    if (isInQueue) {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
        return;
    }

    // Input sekuens DNA
    printf("Masukan sekuens DNA: ");
    STARTWORD();
    Word DNASequence = currentWord;

    // Transkripsi DNA ke RNA
    Word RNASequence = DNAtoRNA(DNASequence);

    // Translasi RNA ke Protein
    Word ProteinSequence = RNAtoProtein(RNASequence);

    // Debug: Cetak hasil DNA, RNA, dan Protein
    // printf("[DEBUG] DNA Sequence: ");
    // PrintWord(DNASequence);
    // printf("[DEBUG] RNA Sequence: ");
    // PrintWord(RNASequence);
    // printf("[DEBUG] Protein Sequence: ");
    // PrintWord(ProteinSequence);

    // Input kode rahasia
    printf("Masukan kode rahasia: ");
    STARTWORD();
    Word kodeRahasia = currentWord;

    // Debug: Cetak kode rahasia
    // printf("[DEBUG] Kode Rahasia: ");
    // PrintWord(kodeRahasia);

    // Validasi kode rahasia
    if (IsSubstring(ProteinSequence, kodeRahasia)) {
        printf("Senjata biologis mengandung kode, barang akan ditambahkan ke dalam queue!\n");

        // Tambahkan barang ke queue
        Barang newBarang;
        char *barangName = WordToString(namaBarang);
        for (int i = 0; i < namaBarang.Length; i++) {
            newBarang.name[i] = barangName[i];
        }
        newBarang.name[namaBarang.Length] = '\0';
        newBarang.price = 0;
        enqueue(barangQueue, newBarang);

        // // Debug: Tampilkan isi queue
        // printf("[DEBUG] Barang berhasil ditambahkan ke dalam queue.\n");
        // displayQueue(*barangQueue);
    } else {
        printf("Kode rahasia tidak ditemukan, maka senjata biologis sudah disabotase, barang ditolak!\n");
    }
}
