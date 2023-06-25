#include <stdio.h>

int main(void) {
    int n, i, sum=0;

    while(1)
    {
        scanf("%d", &n);

        if (n>=1&&n<=10000)
            break;
    }

    for (i=1;i<=n;i++)
    {
        sum+=i;
    }

    printf("%d", sum);

    return 0;
}