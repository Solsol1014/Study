#include <stdio.h>

int main(void) {
    int n, a, b, i;

    while(1)
    {
        scanf("%d", &n);

        if (n>=1&&n<=1000000)
            break;
    }

    for (i=0;i<n;i++)
    {
        while (1)
        {
            scanf("%d %d", &a, &b);

            if (a>=1&&a<=1000&&b>=1&&b<=1000)
                break;
        }

        printf("%d\n", a+b);
    }

    return 0;
}