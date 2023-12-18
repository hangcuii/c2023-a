#include <stdio.h>

int jianyan=0;
int j=2;
int sushu(int p)
{int j=2;
    while(p%j!=0&&j<p)
    {j++;
    }
    if (p==j||p==2)
    {return	1;}
    else
    { return 0;}






}






int main() {
    int a=5;
    for(;a<=100;a++)
    { int b=2,c=3;
        for(;b<=a-3;b++)
        {
            c=3;
            for(;b+c<=a;c++){
                jianyan=((b+c==a)&&(sushu(b)==1)&&(sushu(c)==1));
                if((b+c==a)&&sushu(b)==1&&sushu(c)==1)
                {printf("%d+%d=%d  " ,b,c,a);

                }
            }
        }

















    }

    return 0;
}
