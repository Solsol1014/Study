#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, *sang, m, *given, num;

    scanf("%d", &n);

    sang = (int *)malloc(sizeof(int)*n);

    for (int i=0;i<n;i++)
    {
        scanf("%d", sang+i);
    }

    scanf("%d", &m);

    given = (int *)malloc(sizeof(int)*m);

    for (int i=0;i<m;i++)
    {
        scanf("%d", given+i);
    }

    for (int i=0;i<m;i++)
    {
        num = 0;

        for (int j=0;j<n;j++)
        {
            if (*(given+i)==*(sang+j))
                num++;
        }

        printf("%d ", num);
    }

    return 0;
} //sort를 하는게 문제였나