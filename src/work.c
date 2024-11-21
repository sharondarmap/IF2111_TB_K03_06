#include <stdio.h>
#include "work.h" 
#include <unistd.h> 

void Work(List *userList, User *currentUser) {
    Job WorkList[] = {
        {"Evil Lab Assistant", 100, 14},
        {"OWCA Hiring Manager", 4200, 21},
        {"Cikapundunginator Caretaker", 7000, 30},
        {"Mewing Specialist", 10000, 22},
        {"Inator Connoisseur", 997, 15}
    };

    int length = sizeof(WorkList) / sizeof(WorkList[0]);

    // Show WorkList
    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < length; i++) {
        printf("%d. %s (pendapatan = %d, durasi = %ds)\n", i + 1, WorkList[i].nama, WorkList[i].pendapatan, WorkList[i].durasi);
    }

    printf("\nMasukkan nama pekerjaan yang dipilih: ");
    STARTWORD(); 

    Word inputJob = currentWord; // Start input user
    while (!isEndWord()) {     
        ADVWORD();            
        if (!isEndWord()) {     
            inputJob.TabWord[inputJob.Length++] = ' ';
            for (int i = 0; i < currentWord.Length; i++) {
                inputJob.TabWord[inputJob.Length++] = currentWord.TabWord[i];
            }
        }
    }

    // Compare dengan WorkList.nama
    boolean found = false;
    for (int i = 0; i < length; i++) {
        Word jobName = StringToWord(WorkList[i].nama);
        if (IsWordEqual(inputJob, jobName)) {
            found = true;
            printf("Anda sedang bekerja sebagai %s... Harap tunggu selama %d detik.\n", WorkList[i].nama, WorkList[i].durasi);
            sleep(WorkList[i].durasi);

            currentUser->money += WorkList[i].pendapatan;
            printf("Pekerjaan selesai. %d rupiah telah ditambahkan ke saldo Anda.\n", WorkList[i].pendapatan);
            break;
        }
    }

    if (!found) {
        printf("Pekerjaan tidak valid. Silakan coba lagi.\n");
    }
}

