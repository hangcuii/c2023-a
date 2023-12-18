#include <stdio.h>
#include <conio.h>

int map[6][7] = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 2, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 1}
};

int px = 1, py = 1;

void shuru() {
    int order;
    map[py][px] = 0;

    order = _getch();

    switch (order) {
        case 119:
            if( map[py-1][px]==0)
                py--;
            break;
        case 115:
            if(map[py+1][px]==0)
                py++;
            break;
        case 97:
            if (map[py][px-1]==0)
                px--;
            break;
        case 100:
            if(map[py][px+1]==0)
            {px++;}
            break;
        default:
            return;
    }
}

void locate(int i, int j) {
    map[j][i] = 2;
}

void scan(int s1, int s2) {
    if (map[s1][s2] == 1 && s2 != 6)
        printf("o");
    else if (map[s1][s2] == 1 && s2 == 6)
        printf("o\n");
    else if (map[s1][s2] == 0)
        printf(" ");
    else if (map[s1][s2] == 2)
        printf("p");
}

void printmap() {
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 6; j++) {
            scan(i, j);
        }
    }
}

int main() {
    printmap();
    for (; ;) {
        shuru();
        locate(px, py);
        printmap();
        if (px==5&&py==5)
            break;
    }
    printf("win");
    return 0;
}