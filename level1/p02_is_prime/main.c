#include <stdio.h>
int main() {
    int i, j = 2, k;
    scanf("%d", &i);
    while (i % j != 0 && j < i) {
        j++;
    }
    k = (i == j);
    if (k == 1) {
        printf("prime");
    } else printf(" not prime");
    return 0;


}