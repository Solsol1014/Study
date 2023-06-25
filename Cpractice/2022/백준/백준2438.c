#include <stdio.h>

int main(void) {
    int n, i, j;

    while(1)
    {
        scanf("%d", &n);

        if (n>=1&&n<=100)
            break;
    }

    for (i=1;i<=n;i++)
    {
        for (j=0;j<i;j++)
            printf("*");
        
        printf("\n");
    }

    return 0;
}