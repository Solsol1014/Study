#include <stdio.h>

int main(void) {
    int h, m;

    while (1)
    {
        scanf("%d %d", &h, &m);

        if (h>=0&&h<=23&&m>=0&&m<=59)
            break;
    }

    if (m<45)
    {
        m+=15;
        h-=1;

        if (h<0)
            h=23;
    }
    else
    {
        m-=45;
    }

    printf("%d %d", h, m);

    return 0;
}