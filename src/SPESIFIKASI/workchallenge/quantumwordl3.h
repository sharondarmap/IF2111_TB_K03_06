#ifndef QUANTUMWORDL3_H
#define QUANTUMWORDL3_H

#include "../../ADT/Kustom/user.h"
#include "../../ADT/MesinKata/mesinkata.h"

// Menandai tebakan pemain dengan simbol (*, #, atau huruf asli)
void TandaTebakanQuantum(char *guess, Word *wordAns, char grid[9][6], int attempt);

// Fungsi utama untuk menjalankan permainan Quantum W0RDL3
int QuantumWORDL3();

#endif // QUANTUMWORDL3_H
