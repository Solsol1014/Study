#include <stdio.h>

int main(void) {
    int h, m, t;

    while (1)
    {
        scanf("%d %d", &h, &m);

        if (h>=0&&h<=23&&m>=0&&m<=59)
            break;
    }

    while (1)
    {
        scanf("%d", &t);

        if(t>=0&&t<=1000)
            break;
    }

    h += t/60;
    m += t%60;

    if (m>=60)
    {
        m -= 60;
        h += 1;
    }

    if (h>=24)
        h-=24;

    printf("%d %d", h, m);

    return 0;
}