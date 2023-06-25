#include <stdio.h>

int main(void) {
    int n, i;

    while(1)
    {
        scanf("%d", &n);
        
        if(n>0&&n<=9)
            break;
    }

    for (i=1;i<10;i++)
    {
        printf("%d * %d = %d\n", n, i, n*i);
    }

    return 0;
}