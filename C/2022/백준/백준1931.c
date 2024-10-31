//not finished//
#include <stdio.h>
#include <stdlib.h>

typedef struct time {
    int starttime;
    int endtime;
}time;

int main(void) {
    int n, i, j, a, b, max=0, index, num;
    time *arr, *test;

    while (1)
    {
        scanf("%d", &n);

        if (n>=1&&n<=100000)
            break;
    }

    arr = (time *)malloc(sizeof(time)*n);

    for (i=0;i<n;i++)
    {
        scanf("%d %d", &a, &b);

        arr[i].starttime = a;
        arr[i].endtime = b;
    }

    for (i=0)
    

    printf("%d", max);

    free(arr);

    return 0;
}