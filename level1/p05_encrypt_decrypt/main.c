#include <stdio.h>
char jiami[];
char jiemi[];
int moshi;
int len;
int main() {
    printf("jiami=1,jiemi=2");
    scanf("%d",&moshi);
    printf("length of string");
    scanf("%d",&len);
    switch(moshi){
        case 1:
            scanf_s("%s",jiami);
            for(int n=0;n<len+1;n++)
            { jiami[n]++;
            }
            printf("%s",jiami);
            break;
        case 2:scanf_s("%s",jiemi);
            for(int j=0;j<len+1;j++)
            { jiemi[j]--;
            }
            printf("%s",jiemi);
            break;}
    return 0;
}

