/* Nomor Kelompok   : 13                                          */
/* Nama File        : asciiart_13.c                               */
/* Deskripsi        : File Realisasi ADT asciiart_13.h            */

#include "asciiart_13.h"

void gotoxy(int x, int y)
/* Prosedur yang digunakan untuk mengatur letak korrdinat pada layar */
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void PrintHeaderUtama (void)
/*Prosedur untuk menampilkan tampilan awal saat permainan dibuka */
{
    gotoxy(42,10);
    printf(" .----------------.    .----------------.    .----------------.    .----------------. \n");
    gotoxy(42,11);
    printf("| .--------------. |  | .--------------. |  | .--------------. |  | .--------------. |\n");
    gotoxy(42,12);
    printf("| |    _____     | |  | |     ____     | |  | |   _    _     | |  | |     ____     | |\n");
    gotoxy(42,13);
    printf("| |   / ___ `.   | |  | |   .'    '.   | |  | |  | |  | |    | |  | |   .' __ '.   | |\n");
    gotoxy(42,14);
    printf("| |  |_/___) |   | |  | |  |  .--.  |  | |  | |  | |__| |_   | |  | |   | (__) |   | |\n");
    gotoxy(42,15);
    printf("| |   .'____.'   | |  | |  | |    | |  | |  | |  |____   _|  | |  | |   .`____'.   | |\n");
    gotoxy(42,16);
    printf("| |  / /____     | |  | |  |  `--'  |  | |  | |      _| |_   | |  | |  | (____) |  | |\n");
    gotoxy(42,17);
    printf("| |  |_______|   | |  | |   '.____.'   | |  | |     |_____|  | |  | |  `.______.'  | |\n");
    gotoxy(42,18);
    printf("| |              | |  | |              | |  | |              | |  | |              | |\n");
    gotoxy(42,19);
    printf("| '--------------' |  | '--------------' |  | '--------------' |  | '--------------' |\n");
    gotoxy(42,20);
    printf(" '----------------'    '----------------'    '----------------'    '----------------' \n");
    printf("\n");
}

void PrintHeaderBoard (void)
{
    gotoxy(70,2);
    printf("  ,---.   ,----.    ,---.  ,---.  \n");
    gotoxy(70,3);
    printf(" '.-.  | |      |  /    | |  o  | \n");
    gotoxy(70,4);
    printf("  .-' .' |  ()  | /  '  | .'   '. \n");
    gotoxy(70,5);
    printf(" |   '-. |      | '--|  | |  o  | \n");
    gotoxy(70,6);
    printf(" '-----'  `----'     `--'  `---'  \n");
    printf("\n");
}

void PrintGameOver (void)
{
    gotoxy(45,13);
    printf(" _______  _______  __   __  _______    _______  __   __  _______  ______    __  \n");
    gotoxy(45,14);
    printf("|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  |  | \n");
    gotoxy(45,15);
    printf("|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  |  | \n");
    gotoxy(45,16);
    printf("|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ |  | \n");
    gotoxy(45,17);
    printf("|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  ||__| \n");
    gotoxy(45,18);
    printf("|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | | __  \n");
    gotoxy(45,19);
    printf("|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_||__| \n");
    printf("\n");
}

void BeruangWin(void)
{
gotoxy(118,10);
printf("          ,-~-. _.---._ ,-~-.\n");
gotoxy(118,11);
printf("         / .- ,'       `. -. \\\n");
gotoxy(118,12);
printf("         \\ ` /`        ' \\ ' /\n");
gotoxy(118,13);
printf("          `-/   'a___a`   \\-'\n");
gotoxy(118,14);
printf("            |   ,'(_)`.   |\n");
gotoxy(118,15);
printf("            \\  ( ._|_. )  /\n");
gotoxy(118,16);
printf("             \\  `.___,'  /\n");
gotoxy(118,17);
printf("            .-`._     _,'-.\n");
gotoxy(118,18);
printf("          ,'  ,' `---' `.  `.\n");
gotoxy(118,19);
printf("         /   /     :     \\   \\\n");
gotoxy(118,20);
printf("       ,'   /      :      \\   `.\n");
gotoxy(118,21);
printf("     ,'     |   YOU WIN!  |     `.\n");
gotoxy(118,22);
printf("    |     ,'|      :      |`.     |\n");
gotoxy(118,23);
printf("    `.__,' .-\\     :     /-. `.__,'\n");
gotoxy(118,24);
printf("          /   `.   :   ,'   \\\n");
gotoxy(118,25);
printf("   .""-.,'        `._:_,'      `.,-"".\n");
gotoxy(118,26);
printf("  / ,-. `         ) (         ' ,-. \\\n");
gotoxy(118,27);
printf(" ( (   `.       ,'   `.       ,'   ) )\n");
gotoxy(118,28);
printf("  \\ \\    \\   _,'       `._   /    / /\n");
gotoxy(118,29);
printf("   `.`._,'  /             \\  `._,','\n");
gotoxy(118,30);
printf("     `.__.-'               `-.__,'\n");
gotoxy(118,31);
printf("\n");
}
