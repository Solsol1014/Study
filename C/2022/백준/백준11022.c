#include <stdio.h>

int main(void) {
    int n, i, a, b;

    scanf("%d", &n);

    for (i=0;i<n;i++)
    {
        while(1)
        {
            scanf("%d %d", &a, &b);

            if (a>0&&b<10)
                break;
        }

        printf("Case #%d: %d + %d = %d\n", i+1, a, b, a+b);
    }

    return 0;
}