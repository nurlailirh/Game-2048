/* Nomor Kelompok   : 13                                      */
/* Nama File        : 2048_13.h                               */
/* Deskripsi        : File Header                             */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "highscore_13.h"
#ifndef Tubes_H
#define Tubes_H

/* Definisi Konstanta dan Tipe Bentukan */
#define Nil NULL
typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
                        infotype info; //nilai elemen kotak
                        address left; //pointer ke kotak di kiri
                        address right; //pointer ke kotak di kanan
                        address up; //pointer ke kotak di atas
                        address down; //pointer ke kotak di bawak
                        } ElemenKotak;

typedef struct {
                address C1; //Corner 1 kotak (kiri atas)
                address C2; //Corner 2 kotak (kanan atas)
                address C3; //Corner 3 kotak (kiri bawah)
                address C4; //Corner 4 kotak (kanan bawah)
                } KotakAngka;

#define Info(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Up(P) (P)->up
#define Down(P) (P)->down

#define C1(L) ((L).C1)
#define C2(L) ((L).C2)
#define C3(L) ((L).C3)
#define C4(L) ((L).C4)


//boolean IsEmpty (List L);
/* Mengirimkan true jika list kosong */

address Alokasi(infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */

int RandomAppear (infotype *r);
/* Memunculkan angka 2 atau 4 */

void IsiKotak (KotakAngka *K);
/* Membuat sebuah kotak angka baru dengan dua kotak angka terisi elemen acak 2 atau 4. */
/* I.S. FileSkor terdefinisi */
/* F.S. Nilai-nilai skor di-reset, Nama = "-" dan Nilai = 0 */

void ListToMatriks(KotakAngka K, infotype Mat[5][5]);

void MatriksToList(KotakAngka *K, infotype Mat[5][5]);

void RandomFill (KotakAngka *K, infotype matr[5][5]);

void CetakKotakAngka(KotakAngka K);
/* Prosedur mencetak seluruh elemen kotak angka */

void MoveRight (KotakAngka *K, long int *score);
/* Prosedur untuk menggeser angka ke kanan */

void MoveLeft (KotakAngka *K, long int *score);
/* Prosedur untuk menggeser angka ke kiri */

void MoveUp (KotakAngka *K, long int *score);
/* Prosedur untuk menggeser angka ke atas */

void MoveDown (KotakAngka *K, long int *score);
/* Prosedur untuk menggeser angka ke bawah */

boolean IsSama (infotype Mat1 [5][5], infotype Mat2 [5][5]);

boolean IsKotakFull (KotakAngka K);

boolean GeserHorizontal(KotakAngka K);

boolean GeserVertikal(KotakAngka K);

boolean GameOver(KotakAngka K);

boolean IsMenang (KotakAngka K);

void SaveGame(infotype Mat[5][5], TScore CurrentSkor);

void LoadGame(infotype Mat[5][5], TScore *CurrentSkor);

void main2048 (KotakAngka *K, TScore *CurrentUser);
/* Prosedur main */

#endif // Tubes_H
