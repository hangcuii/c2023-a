#include <stdio.h>
void ha_pr(char from ,char to ,char lo,int i )
{if(i==1)
    printf("%c -> %c\n",from, to);
    else{
        ha_pr(from,lo,to,i-1);
        printf("%c -> %c\n",from, to);
        ha_pr(lo,to,from,i-1);

    }

}

int main() {
    ha_pr( 'a', 'b', 'c', 2);


    return 0;
}