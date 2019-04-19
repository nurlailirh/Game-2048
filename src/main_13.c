/* Nomor Kelompok   : 13                                        */
/* Nama File        : main_13.c                                 */
/* Deskripsi        : File Driver                               */

#include "2048_13.h"

int main()
{
/* KAMUS GLOBAL */
int pilihan;
KotakAngka K;
//TScore FileSkor; //Skor yang disimpan di file eksternal
//TScore CurrentSkorTab[11]; //Tabel Skor yang di-load ke game
TScore CurrentUser; //Data untuk setiap kali bermain

/* MENU */
    do
    {
    PrintHeaderUtama();
    gotoxy(77,22);
    printf("1. Mulai\n");
    gotoxy(77,23);
    printf("2. Skor Tertinggi\n");
    gotoxy(77,24);
    printf("3. Cara Bermain\n");
    gotoxy(77,25);
    printf("4. Tentang Kami\n");
    gotoxy(77,26);
    printf("5. Keluar\n");
    LoadToCurrentScoreTab();
    gotoxy(77,28);
    printf("Pilihan anda : ");
    scanf("%d",&pilihan);
    switch (pilihan)
    {
        case 1 : { /*prosedur main */
                    system("cls");
                    main2048(&K,&CurrentUser);
                    break;
                 }
        case 2 : {
                    system("cls");
                    PrintHeaderUtama();
                    PrintHighScore();
					char reset;
					gotoxy(71,35);
					printf("Press x to reset high score\n");
					gotoxy(71,35);
					printf ("Press any key to continue...");
					reset=getch();
					if (reset=='x') ResetHighScore();
                    system("cls");
                    break;
                 }
        case 3 : {
                    system("cls");
                    PrintHeaderUtama();
                    gotoxy(63,22);
                    printf ("                CARA BERMAIN\n\n");
                    gotoxy(63,24);
                    printf ("     Perpindahan dilakukan dengan tombol: \n");
                    gotoxy(63,25);
                    printf ("                 w = atas\n");
                    gotoxy(63,26);
                    printf ("                 a = kiri\n");
                    gotoxy(63,27);
                    printf ("                 s = bawah\n");
                    gotoxy(63,28);
                    printf ("                 d = kanan\n\n");
                    gotoxy(63,29);
                    printf ("Ketika dua kotak dengan angka yang sama bertemu,\n");
                    gotoxy(63,30);
                    printf ("kedua kotak tersebut akan bergabung menjadi satu.\n");
                    gotoxy(63,31);
                    printf (" tekan u untuk kembali ke langkah sebelumnya \n\n");
                    gotoxy(63,33);
					printf (        "Press any key to continue...");getch();
                    system("cls");
                    break;
                 }
        case 4 : {
                    system("cls");
                    PrintHeaderUtama();
                    gotoxy(63,22);
                    printf("               BARAKALLAH TEAM\n");
                    gotoxy(63,24);
                    printf ("********************************************\n\n");
                    gotoxy(63,25);
                    printf("   Devita Yufliha Mahron        18214001\n");
                    gotoxy(63,26);
                    printf("   Pravitasari Anjani           18214032\n");
                    gotoxy(63,27);
                    printf("   Pebriani Artha               18214048\n");
                    gotoxy(63,28);
                    printf("   Nurlaili Rizki Hasanah       18214049\n\n");
                    gotoxy(63,30);
					printf ("Press any key to continue...");getch();
                    system("cls");
                    break;
                 }
        case 5 : {
                    system("cls");
                    PrintHeaderUtama();
                    gotoxy(63,22);
                    printf("             Selamat tinggal...\n");
                    break;
        }
        default : {
            gotoxy(71,35);
            printf("Inputan salah! Tekan 1/2/3/4/5\n");
            gotoxy(71,36);
            printf("   Press any key to continue..."); getch();
            system("cls");}
        }



    } while (pilihan!=5);

}
