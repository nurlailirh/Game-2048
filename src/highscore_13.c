/* Nomor Kelompok   : 13                                      */
/* Nama File        : highscore_13.c                          */
/* Deskripsi        : File Realisasi ADT highscore_13.h       */

#include "highscore_13.h"

    int retval;
    FILE *filehighscore; //file eksternal highscore
    TScore FileSkor; //tipe fileskor untuk proses r/w
    TScore CurrentSkorTab[11]; //array [0..10] of TScore

void ResetHighScore(void)
{
    /* Kamus Lokal */
    int i;

    /* Algoritma */
    filehighscore = fopen("highscore.txt","w"); //Membuka file eksternal untuk ditulis
    for (i=1 ; i<=10; i++)
    {
        /* Inisiasi nilai-nilai di file eksternal */
        (FileSkor).No = i;
        strcpy((FileSkor).Nama, "-");
        (FileSkor).Nilai = 0;
        retval = fprintf(filehighscore, "%d %s %ld\n", (FileSkor).No, (FileSkor).Nama, (FileSkor).Nilai); //Proses penulisan ke file eksternal
    }
    fclose(filehighscore);
}

void PrintHighScore(void)
{
    /* Kamus Lokal */
    int i;

    /* Algoritma */
    gotoxy(68,22);
    printf("  ========= HIGH SCORE =========\n\n");
    gotoxy(68,23);
    printf("   No\t Nama\t\t Skor\n");
    printf("\n");
    filehighscore = fopen("highscore.txt","r"); //Membuka file eksternal untuk dibaca
    retval = fscanf(filehighscore, "%d %s %ld", &FileSkor.No, FileSkor.Nama, &FileSkor.Nilai); //Proses pembacaan file eksternal
    i = 24;
    while (retval!= EOF)
    {
        gotoxy(68,i);
        printf("   %d\t %s\t\t %ld\n", FileSkor.No, FileSkor.Nama, FileSkor.Nilai); //Proses pencetakan nilai ke layar
        retval = fscanf(filehighscore, "%d %s %ld", &FileSkor.No, FileSkor.Nama, &FileSkor.Nilai);
        i = i + 1;
    }
    fclose(filehighscore);
}

void LoadToCurrentScoreTab(void)
{
    /* Kamus Lokal */
    int i;

    /* Algoritma */
    filehighscore = fopen("highscore.txt","r"); //Membuka file eksternal untuk dibaca
    retval = fscanf(filehighscore, "%d %s %ld", &FileSkor.No, FileSkor.Nama, &FileSkor.Nilai);
    i=1;
    while (retval!= EOF)
    {
        /* Proses pengisian array */
        strcpy((CurrentSkorTab)[i].Nama,FileSkor.Nama);
        (CurrentSkorTab)[i].No = FileSkor.No;
        (CurrentSkorTab)[i].Nilai = FileSkor.Nilai;
        retval = fscanf(filehighscore, "%d %s %ld\n", &FileSkor.No, FileSkor.Nama, &FileSkor.Nilai);
        i++;
    }
    fclose(filehighscore);
}

void SaveHighScore(void)
{
    /* Kamus Lokal */
    int i;

    /* Algoritma */
    filehighscore = fopen("highscore.txt","w"); //Membuka file eksternal untuk ditulis
    for (i=1 ; i<=10; i++)
    {
        /* Proses penulisan ke file eksternal */
        (FileSkor).No = i;
        strcpy((FileSkor).Nama, CurrentSkorTab[i].Nama);
        (FileSkor).Nilai = CurrentSkorTab[i].Nilai;
        retval = fprintf(filehighscore, "%d %s %ld\n", (FileSkor).No, (FileSkor).Nama, (FileSkor).Nilai);
    }
    fclose(filehighscore);
}

void UpdateHighScore(TScore CurrentUser)
{
    /* Kamus Lokal */
    boolean found;
    int i,j;

    /* Algoritma */
    found=false;
    i=1;
    while ((i<=10) && (!found))
    {
        if (CurrentUser.Nilai>CurrentSkorTab[i].Nilai) //ketika nilai current user masuk ke 10 skor teratas
        {
            /* Proses penggeseran elemen-elemen dibawah indeks yang ditemukan ke bawah */
            j=10;
            do
            {
                strcpy(&CurrentSkorTab[j].Nama,&CurrentSkorTab[j-1].Nama);
                CurrentSkorTab[j].Nilai = CurrentSkorTab[j-1].Nilai;
                j = j-1;
            } while (j>i); //penggeseran dilakukan dari array ke-10 sampai ke satu elemen dibawah indeks i
            /* Proses pengisian data skor baru */
            strcpy(&CurrentSkorTab[i].Nama,&CurrentUser.Nama);
            CurrentSkorTab[i].Nilai = CurrentUser.Nilai;

            found = true;
        }
        else i++;
    } // i>10 atau found = true
}
