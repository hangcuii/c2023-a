#include "stdio.h"

#include "stdlib.h"
#include<windows.h>



void gotoxy(short x, short y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}

int main()
{
    int q;
    int x,y;
    x=0, y=0;
    printf("i");
    int j;
    int l;

    for(q=0;q<=10000000;q++){
        j=q/118;
        l=j%2;
        if (l==0){



            x++;}
        else{x--;
        }
        system("cls");
        gotoxy(x,y);
        printf(" ");
        printf("i");
        Sleep(100);

    }
    return 0;

}