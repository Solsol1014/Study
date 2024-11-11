#include <stdio.h>

int main(void) {
    int a, b, c, max;

    while (1)
    {
        scanf("%d %d %d", &a, &b, &c);

        if (a<=6&&b<=6&&c<=6&&a>0&&b>0&&c>0)
            break;
    }

    if (a==b&&b==c)
        printf("%d", (10000+a*1000));
    else if (a==b||b==c||a==c)
    {
        if (a==b)
            printf("%d", (1000+a*100));
        else
            printf("%d", (1000+c*100));
    }
    else
    {
        max = a;
        if (max<b)
            max = b;
        if (max<c)
            max = c;
        
        printf("%d", max*100);
    }

    return 0;
}