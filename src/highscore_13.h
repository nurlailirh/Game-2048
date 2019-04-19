/* Nomor Kelompok   : 13                                      */
/* Nama File        : highscore_13.h                          */
/* Deskripsi        : File Header                             */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean_13.h"


#ifndef highscore_h
#define highscore_h

/* Definisi tipe HighScore */
typedef struct
{
    int No;
    char Nama[10];
    long int Nilai;
}
TScore; // Tipe bentukan TScore, terdiri dari No, Nama dan Nilai

void ResetHighScore(void);
/* I.S. FileSkor terdefinisi */
/* F.S. Nilai-nilai skor di-reset, Nama = "-" dan Nilai = 0 */

void LoadToCurrentScoreTab(void);
/* I.S. Array CurrentSkorTab dan FileSkor terdefinisi */
/* F.S. Tabel CurrentSkorTab terisi nilai-nilai dari file eksternal FileSkor */

void UpdateHighScore(TScore CurrentUser);
/* I.S. Array CurrentSkorTab terdefinisi, CurrentUser terdefinisi dan memiliki nilai tertentu */
/* F.S. Nilai-nilai di CurrentSkorTab ter-update sesuai urutan high score. Apabila current user memiliki
        nilai skor di urutan 10 terbesar maka akan disimpan ke tabel CurrentSkorTab */

void SaveHighScore(void);
/* I.S. Array CurrentSkorTab dan FileSkor terdefinisi */
/* F.S. Nilai-nilai di CurrentSkorTab disimpan ke file eksternal FileSkor */

void PrintHighScore(void);
/* I.S. Array of THighScore FileSkor terdefinisi */
/* F.S. Nilai-nilai pada FileSkor tercetak di layar*/


#endif
