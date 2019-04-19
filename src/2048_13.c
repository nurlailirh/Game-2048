/* Nomor Kelompok   : 13                            */
/* Nama File        : 2048_13.c                     */
/* Deskripsi        : File Realisasi ADT 2048_13.h  */

#include "2048_13.h"
    int retval;
    FILE *filegame;



address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
// Kamus
    address P;
// Algoritma
    P=(address) malloc (sizeof(ElemenKotak));
    if (P==Nil){
        return Nil;
    } else {
        /* Inisiasi elemen kotak dengan info=X dan pointer Up, Down, Right dan Left = Nil */
        Info(P)=X;
        Up(P)=Nil;
        Down(P)=Nil;
        Left(P)=Nil;
        Right(P)=Nil;
        return(P);
    }
}

int RandomAppear (infotype *r)
{
	srand (time(NULL));
	do
	{
		*r = rand() % 5; //merandom angka dari 0-4
	} while (*r==0 || *r==3 || *r==1);
	//angka hasil random adalah 2 atau 4
	return (*r);
}

void IsiKotak(KotakAngka *K)
{
    // Kamus
    address Isi[5][5]; //array of address sebagai penampung sementara
    int i,j;
    int n1, n2;

    /* Algoritma */

    // Inisiasi kotak dengan angka 0
    // Set Right dan Left dari masing-masing kotak

    i=1;
    do
    {
        Isi[i][1]=Alokasi(0);
        Isi[i][2]=Alokasi(0);
        Right(Isi[i][1])= Isi[i][2];
        Left(Isi[i][2]) = Isi[i][1];

        j=3;
        do
        {
            Isi[i][j] = Alokasi(0);
            Right(Isi[i][j-1])=Isi[i][j];
            Left(Isi[i][j]) = Isi[i][j-1];
            j=j+1;
        } while (j<=4);
    i= i+1;
    } while (i<=4);

    // Set Down dan Up dari masing-masing kotak
    j=1;
    do
    {
        Down(Isi[1][j])= Isi[2][j];
        Up(Isi[2][j]) = Isi[1][j];

        i=3;
        do
        {
            Down(Isi[i-1][j])=Isi[i][j];
            Up(Isi[i][j]) = Isi[i-1][j];
            i=i+1;
        } while (i<=4);
    j= j+1;
    } while (j<=4);

    n1 = RandomAppear(&n1); //memunculkan angka awal pertama secara acak
    n2 = RandomAppear(&n2); //memunculkan angka awal kedua secara acak
    srand (time(NULL));
    Info(Isi[(rand()%4)+1][(rand()%4)+1]) = n1;
    Info(Isi[(rand()%4)+1][(rand()%4)+1]) = n2;
    /* Assign corner-corner pada list dari matriks Isi */
    C1(*K) = Isi[1][1];
    C2(*K) = Isi[1][4];
    C3(*K) = Isi[4][1];
    C4(*K) = Isi[4][4];
}

void ListToMatriks(KotakAngka K, infotype Mat[5][5])
{
    /* Kamus Lokal */
    address X,Y; //X dan Y sebagai acuan elemen kotak angka
    int i,j;

    /* Algoritma */
    //acuan dimulai dari C1 (kotak paling kiri atas)
    X = C1(K);
    Y = C1(K);
    i=1;
    /* Proses penyalinan nilai-nilai elemen di list ke matriks */
    while ((Y)!=Nil)
    {
        j=1;
        X=Y;
        while (((X))!=Nil)
        {
            Mat[i][j]=Info(X); //Proses menyalin ke list
            X = Right(X); //X bergeser ke Right(X) untuk diproses
            j=j+1;
        }
        Y = Down(Y); //Y bergeser ke Down(Y) setelah proses penyalinan dalam satu baris telah selesai
        i=i+1;
    }
}

void MatriksToList(KotakAngka *K, infotype Mat[5][5])
{
    /* Kamus Lokal */
    address X,Y;
    int i,j;

    /* Algoritma */

    //acuan dimulai dari C1 (kotak paling kiri atas)
    X = C1(*K);
    Y = C1(*K);
    i=1;
    /* Proses penyalinan nilai-nilai elemen dari matriks ke list */
    while ((Y)!=Nil)
    {
        j=1;
        X=Y;
        while (((X))!=Nil)
        {
            Info(X)=Mat[i][j]; //Proses menyalin ke matriks
            X = Right(X); //X bergeser ke Right(X) untuk diproses
            j=j+1;
        }
        Y = Down(Y);  //Y bergeser ke Down(Y) setelah proses penyalinan dalam satu baris telah selesai
        i=i+1;
    }
}

void RandomFill (KotakAngka *K, infotype matr[5][5])
{
	/* Kamus Lokal */
	int i, j, x;

	/* Algoritma */
	ListToMatriks(*K,matr);
	do
	{
		i = rand() % 4;
		j = rand() % 4;
	} while (matr[i+1][j+1]!=0);
	x = RandomAppear(&x);
	matr[i+1][j+1] = x;
	MatriksToList(&*K,matr);
}

void CetakKotakAngka(KotakAngka K)
{
    /* Kamus Lokal */
    int i,j,k;
    address X,Y;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Algoritma */
    X = C1(K);
    Y = C1(K);
    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    /* Pembuatan kerangka kotak angka */
    gotoxy(60,10);
    printf ("________________________________________________________\n");
    gotoxy(60,14);
    printf ("________________________________________________________\n");
    gotoxy(60,18);
    printf ("________________________________________________________\n");
    gotoxy(60,22);
    printf ("________________________________________________________\n");
    gotoxy(60,26);
    printf ("________________________________________________________\n");
    //Membuat garis horizontal terkiri
    for (i = 11; i<=26; i++)
    {
        gotoxy(59,i);
        printf ("|\n");
    }
    //Membuat garis horizontal tengah
    for (i = 11; i<=26; i++)
    {
        gotoxy(73,i);
        printf ("|\n");
    }
    //Membuat garis horizontal kedua dari kiri
    for (i = 11; i<=26; i++)
    {
        gotoxy(88,i);
        printf ("|\n");
    }
    //Membuat garis horizontal kedua dari kanan
    for (i = 11; i<=26; i++)
    {
        gotoxy(102,i);
        printf ("|\n");
    }
    //Membuat garis horizontal terkanan
    for (i = 11; i<=26; i++)
    {
        gotoxy(116,i);
        printf ("|\n");
    }
    X = C1(K);
    Y = C1(K);
    k = 12; //k adalah koordinat y angka baris 1 kolom 1
    while (((Y)!=Nil) && (k<=25))
    {
        X=Y;
        j = 62; //j adalah koordinat x
        while (((X)!=Nil) && (j<=104)) //angka pada kolom ke-4 baris ke-1 dicetak pada koordinat x=104
        {
             switch (Info(X))
             {
                 case 2 : SetConsoleTextAttribute(hConsole, 1); break;
                 case 4 : SetConsoleTextAttribute(hConsole, 2); break;
                 case 8 : SetConsoleTextAttribute(hConsole, 3); break;
                 case 16 : SetConsoleTextAttribute(hConsole, 4); break;
                 case 32 : SetConsoleTextAttribute(hConsole, 5); break;
                 case 64 : SetConsoleTextAttribute(hConsole, 6); break;
                 case 128 : SetConsoleTextAttribute(hConsole, 7); break;
                 case 256 : SetConsoleTextAttribute(hConsole, 8); break;
                 case 512 : SetConsoleTextAttribute(hConsole, 9); break;
                 case 1024 : SetConsoleTextAttribute(hConsole, 10); break;
                 case 2048 : SetConsoleTextAttribute(hConsole, 11); break;
                 case 4096 : SetConsoleTextAttribute(hConsole, 12); break;
                 case 8192 : SetConsoleTextAttribute(hConsole, 13); break;
                 case 16384 : SetConsoleTextAttribute(hConsole, 14); break;
            }
            gotoxy(j, k);
            if (Info(X)==0)
            {
                printf(" \t"); //jika info(x) = 0 maka kotak kosong
            }
            else
            {
                printf("%d\t",Info(X)); //pencetakan elemen kotak angka
            }

            X = Right(X);
            /* Restore original attributes */
            SetConsoleTextAttribute(hConsole, saved_attributes);
            j = j+14;
        }
        printf("\n");
        Y = Down(Y);
        k = k+4;
    }
}

void MoveRight (KotakAngka *K, long int *score)
{
    // Kamus
    address acuan, cek, basis;

    // Algoritma
    basis=(*K).C2;
    do
    {
        acuan=basis;
        do
        {
            cek=(Left(acuan)); // kiri yang ditunjuk acuan
            do
            {
                if (Info(acuan)==0)
                {
                    if (Info(cek)==0)
                    {
                        cek=Left(cek);
                    } else //cek!=0
                        {
                            Info(acuan)=Info(cek);
                            Info(cek)=0;
                            cek=Left(cek);
                        }
                } else //Info(acuan)!=0
                    {
                        if (Info(cek)==0)
                        {
                            cek=Left(cek);
                        } else //cek!=0
                            {
                                if (Info(cek)!=Info(acuan))
                                {
                                  if (Info(Right(cek))==0) //info dari elemen kanan yang ditunjuk cek
                                    {
                                        Info(Right(cek))=Info(cek);
                                        Info(cek)=0;
                                    }
                                    cek=Nil;
                                } else //Info(cek)==Info(acuan)
                                    {
                                        Info(acuan)=Info(acuan)+Info(cek);
                                        *score=*score+Info(acuan);
                                        Info(cek)=0;
                                        cek=Nil;
                                    }
                            }

                    }
            } while (cek!=Nil);
            acuan=Left(acuan);
        } while (Left(acuan)!=Nil);
        basis=Down(basis);
    } while(basis!=Nil);
}

void MoveLeft (KotakAngka *K, long int *score)
{
    // Kamus
    address acuan, cek, basis;

    // Algoritma
    basis=(*K).C1;
    do
    {
        acuan=basis;
        do
        {
            cek=(Right(acuan)); // kiri yang ditunjuk acuan
            do
            {
                if (Info(acuan)==0)
                {
                    if (Info(cek)==0)
                    {
                        cek=Right(cek);
                    } else //cek!=0
                        {
                            Info(acuan)=Info(cek);
                            Info(cek)=0;
                            cek=Right(cek);
                        }
                } else //Info(acuan)!=0
                    {
                        if (Info(cek)==0)
                        {
                            cek=Right(cek);
                        } else //cek!=0
                            {
                                if (Info(cek)!=Info(acuan))
                                {
                                    if (Info(Left(cek))==0) //info dari elemen kanan yang ditunjuk cek
                                    {
                                        Info(Left(cek))=Info(cek);
                                        Info(cek)=0;
                                    }
                                    cek=Nil;
                                } else //Info(cek)==Info(acuan)
                                    {
                                        Info(acuan)=Info(acuan)+Info(cek);
                                        *score=*score+Info(acuan);
                                        Info(cek)=0;
                                        cek=Nil;
                                    }
                            }
                    }
            } while (cek!=Nil);
            acuan=Right(acuan);
        } while (Right(acuan)!=Nil);
        basis=Down(basis);
    } while(basis!=Nil);
}

void MoveUp (KotakAngka *K, long int *score)
{
    // Kamus
    address acuan, cek, basis;

    // Algoritma
    basis=(*K).C1;
    do
    {
        acuan=basis;
        do
        {
            cek=(Down(acuan)); // kiri yang ditunjuk acuan
            do
            {
                if (Info(acuan)==0)
                {
                    if (Info(cek)==0)
                    {
                        cek=Down(cek);
                    } else //cek!=0
                        {
                            Info(acuan)=Info(cek);
                            Info(cek)=0;
                            cek=Down(cek);
                        }
                } else //Info(acuan)!=0
                    {
                        if (Info(cek)==0)
                        {
                            cek=Down(cek);
                        } else //cek!=0
                            {
                                if (Info(cek)!=Info(acuan))
                                {
                                    if (Info(Up(cek))==0) //info dari elemen kanan yang ditunjuk cek
                                    {
                                        Info(Up(cek))=Info(cek);
                                        Info(cek)=0;
                                    }
                                    cek=Nil;
                                } else //Info(cek)==Info(acuan)
                                    {
                                        Info(acuan)=Info(acuan)+Info(cek);
                                        *score=*score+Info(acuan);
                                        Info(cek)=0;
                                        cek=Nil;
                                    }
                            }
                    }
            } while (cek!=Nil);
            acuan=Down(acuan);
        } while (Down(acuan)!=Nil);
        basis=Right(basis);
    } while(basis!=Nil);
}

void MoveDown (KotakAngka *K, long int *score)
{
    // Kamus
    address acuan, cek, basis;

    // Algoritma
    basis=(*K).C3;
    do
    {
        acuan=basis;
        do
        {
            cek=(Up(acuan)); // kiri yang ditunjuk acuan
            do
            {
                if (Info(acuan)==0)
                {
                    if (Info(cek)==0)
                    {
                        cek=Up(cek);
                    } else //cek!=0
                        {
                            Info(acuan)=Info(cek);
                            Info(cek)=0;
                            cek=Up(cek);
                        }
                } else //Info(acuan)!=0
                    {
                        if (Info(cek)==0)
                        {
                            cek=Up(cek);
                        } else //cek!=0
                            {
                                if (Info(cek)!=Info(acuan))
                                {
                                    if (Info(Down(cek))==0) //info dari elemen kanan yang ditunjuk cek
                                    {
                                        Info(Down(cek))=Info(cek);
                                        Info(cek)=0;
                                    }
                                    cek=Nil;
                                } else //Info(cek)==Info(acuan)
                                    {
                                        Info(acuan)=Info(acuan)+Info(cek);
                                        *score=*score+Info(acuan);
                                        Info(cek)=0;
                                        cek=Nil;
                                    }
                            }
                    }
            } while (cek!=Nil);
            acuan=Up(acuan);
        } while (Up(acuan)!=Nil);
        basis=Right(basis);
    } while(basis!=Nil);
}

boolean IsSama (int Mat1 [5][5], int Mat2 [5][5])
{
    /* Kamus Lokal */
    int i, j;
    boolean found;

    /* Algoritma */
    found = false;
    i = 1;
    while ((i<=4) && !(found))
    {
        j = 1;
        while ((j<=4) && !(found))
        {
            if (Mat1[i][j] != Mat2[i][j])
            {
                found = true; //ada elemen Mat1[i][j] dengan Mat2[i][j] yang tidak sama
            }
            j = j+1;
        }
        i = i+1;
    }
    return (!(found));
}

boolean IsKotakFull (KotakAngka K)
{
    int i,j;
    boolean found;
    int M[5][5];

    ListToMatriks(K,M);
    found=false;
    i=1;
    while ((i<=4) && (!found))
    {
        j=1;
        while ((j<=4) && (!found))
        {
            if (M[i][j]==0) //ada elemen yang bernilai 0
            {
              found=true;
            }
            else
            {
                j=j+1;
            }
        }
        i=i+1;
    }
    return (!found);
}

boolean GeserHorizontal(KotakAngka K)
{

    /* Kamus */
    boolean found;
    int i,j;
    int M[5][5];

    ListToMatriks(K,M);
    found=false;
    i=1;
    while ((i<=4) && (!found))
    {
        j=1;
        while ((j<=3) && (!found))
        {
            if (M[i][j]==M[i][j+1]) //elemen kotak yang berdekatan ber-angka samaa
            {
              found=true;
            }
            else
            {
                j=j+1;
            }
        }
        i=i+1;
    }
    return found;
}
boolean GeserVertikal(KotakAngka K)
{

    /* Kamus */
    boolean found;
    int i,j;
    int M[5][5];

    ListToMatriks(K,M);
    found=false;
    j=1;
    while ((j<=4) && (!found))
    {
        i=1;
        while ((i<=3) && (!found))
        {
            if (M[i][j]==M[i+1][j]) //elemen kotak yang berdekatan ber-angka sama
            {
              found=true;
            }
            else
            {
                i=i+1;
            }
        }
        j=j+1;
    }
    return found;
}
boolean GameOver(KotakAngka K)
{
    return ((IsKotakFull(K)) && (!GeserHorizontal(K)) && (!GeserVertikal(K)));
}

boolean IsMenang (KotakAngka K)
{
    int i,j;
    boolean found;
    int M[5][5];

    ListToMatriks(K,M);
    found=false;
    i=1;
    while ((i<=4) && (!found))
    {
        j=1;
        while ((j<=4) && (!found))
        {
            if (M[i][j]>=2048) //angka 2048 atau lebih sebagai salah satu elemen kotak
            {
              found=true;
            }
            else
            {
                j=j+1;
            }
        }//j>4 atau found
        i=i+1;
    } //i>4 atau found
    return (found);
}

void SaveGame(int Mat[5][5], TScore CurrentSkor)
{
    /* Kamus Lokal */
    int i,j;
    TScore FileSkor;
    int FileMat;

    /* Algoritma */
    filegame = fopen("game.txt","w"); //Membuka file eksternal untuk ditulis
    (FileSkor).No = 0;
    //Proses penyimpanan nama dan nilai ke file eksternal
    strcpy((FileSkor).Nama, CurrentSkor.Nama);
    (FileSkor).Nilai = CurrentSkor.Nilai;
    retval = fprintf(filegame, "%s %ld\n", (FileSkor).Nama, (FileSkor).Nilai);
    for (i=1 ; i<=4; i++)
    {
        /* Proses penulisan angka-angka ke file eksternal */
        for (j=1 ; j<=4; j++)
        {
            FileMat = Mat[i][j];
            retval = fprintf(filegame, "%d ", FileMat);
        }
        retval = fprintf(filegame, "\n");
    }
    fclose(filegame);
}

void LoadGame(int Mat[5][5], TScore *CurrentSkor)
{
    /* Kamus Lokal */
    int i,j;
    int FileMat;
    TScore FileSkor;

    /* Algoritma */
    filegame= fopen("game.txt","r"); //Membuka file eksternal untuk dibaca
    //Pembacaan nama dan nilai user
    retval = fscanf(filegame, "%s %ld", FileSkor.Nama, &FileSkor.Nilai);
    strcpy((*CurrentSkor).Nama,FileSkor.Nama);
    (*CurrentSkor).No = 0;
    (*CurrentSkor).Nilai = FileSkor.Nilai;
    retval = fscanf(filegame, "\n");

    //Pembacaan kotak-kotak angka
    retval = fscanf(filegame, "%d ", &FileMat);
    for (i=1;i<=4;i++)
    {
        for (j=1;j<=4;j++)
        {
            Mat[i][j]= FileMat;
            retval = fscanf(filegame, "%d ", &FileMat);
        }
        retval = fscanf(filegame, "\n");
    }
    fclose(filegame);
}

void main2048 (KotakAngka *K, TScore *CurrentUser)
{
    /* Kamus Lokal */
    char pointer;
    int Mat1[5][5];
    int Mat2[5][5];
    long int scorebefore;
    int pil;
    boolean gmover, menang;

    /* Algoritma */

    //Submenu untuk memulai game
    do
    {
        system("cls");
        menang=false;
        PrintHeaderUtama();
        gotoxy(77,22);
        printf("1. New Game");
        gotoxy(77,23);
        printf("2. Load Game\n");
        gotoxy(77,24);
        printf("Pilihan anda: ");
        scanf("%d",&pil);
        //validasi input pilihan
        if ((pil!=1) && (pil!=2)) {
            gotoxy(77,25);
            printf("Inputan salah! Pilih 1/2\n\nPress any key to continue...");
            getch();
        }
    } while ((pil!=1) && (pil!=2)); //input pilihan telah divalidasi, pilihan adalah 1 atau 2

    //Pilihan new game atau load game
    system("cls");
    PrintHeaderBoard();
    IsiKotak (&(*K));
    if (pil==2) //load game
    {
        LoadGame(&Mat1, &*CurrentUser);
        MatriksToList(&*K,Mat1);
    }
    else if (pil==1) //new game
    {
        system("cls");
        PrintHeaderUtama();
        gotoxy(77,22);
        printf("Masukkan username : "); //meminta input nama
        gotoxy(77,23);
        scanf("%s", &(*CurrentUser).Nama);
        (*CurrentUser).Nilai=0; //inisiasi Score = 0
    }

    system("cls");
    PrintHeaderBoard();
    CetakKotakAngka(*K);
    gotoxy(60,9);
    printf("%s\n",(*CurrentUser).Nama);
    gotoxy(102,9);
    printf("Score : %ld\n",(*CurrentUser).Nilai);

    gmover=false;
    while ((gmover==false) && (pointer!='b'))
    {
        gotoxy(35,15);
        printf("w : up\n");
        gotoxy(35,16);
        printf("s : down\n");
        gotoxy(35,17);
        printf("a : left\n");
        gotoxy(35,18);
        printf("d : right\n");
        gotoxy(35,19);
        printf("u : undo\n");
        gotoxy(35,20);
        printf("b : back to main menu\n");

        //cek kondisi menang setiap akan melakukan pergerakan baru
        menang = (IsMenang(*K));
        if (menang==true)
        {
            BeruangWin();
        }
        pointer=getch();

        switch(pointer)
        {
            case 'a' : {//Perpindahan ke kiri

                        system("cls");
                        PrintHeaderBoard();
                        ListToMatriks(*K,Mat1); //matriks sebelum dilakukan move
                        scorebefore = (*CurrentUser).Nilai;
                        MoveLeft(K,&(*CurrentUser).Nilai);
                        ListToMatriks(*K,Mat2); //matriks setelah dilakukan move
                        if (!IsSama(Mat1,Mat2)) //Jika kotak angka berubah (bisa bergerak)
                        {
                            RandomFill(&*K, Mat2); //Pengisian angka baru 2 atau 4
                        }
                        CetakKotakAngka(*K);
                        gotoxy(60,9);
                        printf("%s\n",(*CurrentUser).Nama);
                        gotoxy(102,9);
                        printf("Score : %ld\n",(*CurrentUser).Nilai);
                        SaveGame(Mat2, *CurrentUser);
                        break;
                        }
            case 's' : {//Perpindahan ke bawah
                        system("cls");
                        PrintHeaderBoard();
                        ListToMatriks(*K,Mat1); //matriks sebelum dilakukan move
                        scorebefore = (*CurrentUser).Nilai;
                        MoveDown(K,&(*CurrentUser).Nilai);
                        ListToMatriks(*K,Mat2); //matriks setelah dilakukan move
                        if (!IsSama(Mat1,Mat2)) //Jika kotak angka berubah (bisa bergerak)
                        {
                            RandomFill(&*K, Mat2); //Pengisian angka baru 2 atau 4
                        }
                        CetakKotakAngka(*K);
                        gotoxy(60,9);
                        printf("%s\n",(*CurrentUser).Nama);
                        gotoxy(102,9);
                        printf("Score : %ld\n",(*CurrentUser).Nilai);
                        SaveGame(Mat2, *CurrentUser);
                        break;
                        }
            case 'w' : {
                        system("cls");
                        PrintHeaderBoard();
                        ListToMatriks(*K,Mat1); //matriks sebelum dilakukan move
                        scorebefore = (*CurrentUser).Nilai;
                        MoveUp(K,&(*CurrentUser).Nilai);
                        ListToMatriks(*K,Mat2);//matriks setelah dilakukan move
                        if (!IsSama(Mat1,Mat2)) //Jika kotak angka berubah (bisa bergerak)
                        {
                            RandomFill(&*K, Mat2); //Pengisian angka baru 2 atau 4
                        }
                        CetakKotakAngka(*K);
                        gotoxy(60,9);
                        printf("%s\n",(*CurrentUser).Nama);
                        gotoxy(102,9);
                        printf("Score : %ld\n",(*CurrentUser).Nilai);
                        SaveGame(Mat2, *CurrentUser);
                        break;
                        }
            case 'd' : {

                        system("cls");
                        PrintHeaderBoard();
                        ListToMatriks(*K,Mat1); //matriks sebelum dilakukan move
                        scorebefore = (*CurrentUser).Nilai;
                        MoveRight(K,&(*CurrentUser).Nilai);
                        ListToMatriks(*K,Mat2); //matriks setelah dilakukan move
                        if (!IsSama(Mat1,Mat2)) //Jika kotak angka berubah (bisa bergerak)
                        {
                            RandomFill(&*K, Mat2); //Pengisian angka baru 2 atau 4
                        }
                        CetakKotakAngka(*K);
                        gotoxy(60,9);
                        printf("%s\n",(*CurrentUser).Nama);
                        gotoxy(102,9);
                        printf("Score : %ld\n",(*CurrentUser).Nilai);
                        SaveGame(Mat2, *CurrentUser);
                        break;
                        }
             case 'u' : {
                        system("cls");
                        PrintHeaderBoard();
                        MatriksToList(K, Mat1); //matriks awal Mat1 (sebelum dilakukan pergerakan)
                        CetakKotakAngka(*K);
                        gotoxy(60,9);
                        printf("%s\n",(*CurrentUser).Nama);
                        gotoxy(102,9);
                        printf("Score : %ld\n",scorebefore);
                        (*CurrentUser).Nilai = scorebefore; //Nilai score yang dicetak adalah nilai sebelumnya
                        SaveGame(Mat1, *CurrentUser);
                        break;
                        }
            case 'b' : {
                        system("cls");
                        break;
                        }
            default : {
                        system("cls");
                        PrintHeaderBoard();
                        CetakKotakAngka(*K);
                        gotoxy(60,9);
                        printf("%s\n",(*CurrentUser).Nama);
                        gotoxy(102,9);
                        printf("Score : %ld\n",(*CurrentUser).Nilai);
                        gotoxy(35,23);
                        printf("Inputan salah!\n");
                        break;
                        }
        }
        //Pengecekan kondisi game over setiap selesai melakukan move
        gmover=(GameOver(*K));
        if (gmover==true)
        {
            char yorn;

            system ("cls");
            PrintGameOver();
            gotoxy(74,28);
            printf("Save high score? y/n: "); //Pilihan untuk menyimpan score atau tidak
            yorn=getch();
            if (yorn=='y')
            {   UpdateHighScore(*CurrentUser);
                SaveHighScore();
            }
            system("cls");
        }
    }
}

