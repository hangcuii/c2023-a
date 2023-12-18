#include <stdio.h>
#include <conio.h>
int test(int i,int j)//下标检测，i是y，j是x
{ int result=0;
    if (i<=5&&i>=0&&j<=6&&j>=0)
        result=1;
    return result;
}
int map[6][7];
//= {
        //{1, 1, 1, 1, 1, 1, 1},
        //{1, 2, 0, 0, 0, 0, 1},
        //{1, 0, 0, 0, 0, 0, 1},
        //{1, 0, 0, 0, 3, 0, 1},
        //{1, 0, 0, 0, 0, 0, 1},
        //{1, 1, 1, 1, 1, 4, 1}//墙是1，人物是2，箱子是3，空地是0,横为x坐标，竖是y坐标,4是要移到的位置
//}:

int px = 1, py = 1;
int score,step=0;


int aimx,aimy;
int level=1;
FILE *fp;
void loadmap() {
     px = 1;
     py = 1;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            fscanf(fp, "%d,", &map[i][j]);
        }
    }
}


void shuru() {
    int order;
    map[py][px] = 0;

    order = _getch();

    switch (order) {
        case 119:
            if( map[py-1][px]==0)
            {
                py--;
            }
            else if (map[py-1][px]==3&&(map[py-2][px]==0||map[py-2][px]==4))

            {
                map[py-2][px]=3;
                py--;
            }
            break;
        case 115:
            if(map[py+1][px]==0)
                py++;
            else if(map[py+1][px]==3&&(map[py+2][px]==0||map[py+2][px]==4))
            {map[py+2][px]=3;
                        py++;
            }
            break;
        case 97:
            if (map[py][px-1]==0)
                px--;
            else if(map[py][px-1]==3&&(map[py][px-2]==0||map[py][px-2]==4))
            { map[py][px-2]=3;
                px--;
            }
            break;
        case 100:
            if(map[py][px+1]==0)
            {px++;}
            else if(map[py][px+1]==3&&(map[py][px+2]==0||map[py][px+2]==4))
            { map[py][px+2]=3;
                px++;}
            break;
        default:{}
            step++;
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
    else if(map[s1][s2]==3)
        printf("x");
    else if(map[s1][s2]==4)
    { aimx=s2;
    aimy=s1;
        printf("w");}
}

void printmap() {
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 6; j++) {
            scan(i, j);
        }
    }
}

int main() {
    // ...
    for (;;) {
        fp = fopen("C:\\Users\\cuihang\\CLionProjects\\c2023-a\\level1\\p08_push_boxes\\map.txt", "r");
        if (fp == NULL) {
            printf("Failed to open the file.\n");
            return 1;
        }
        loadmap();
        fclose(fp);
        printmap();
        printf("o is edge , p is player,x is box,w is the point\n ");
        while (map[aimy][aimx] != 3) {
            shuru();
            locate(px, py);
            printmap();
        }
        printf("win\n");
        level++;
        if (level == 4) { break; }
    }
    printf("win");
    return 0;
}
