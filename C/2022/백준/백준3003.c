//112228
#include <stdio.h>

int main(void) {
    int k, q, v, l, n, p;

    scanf("%d %d %d %d %d %d", &k, &q, &v, &l, &n, &p);

    printf("%d %d %d %d %d %d", 1-k, 1-q, 2-v, 2-l, 2-n, 8-p);

    return 0;
}