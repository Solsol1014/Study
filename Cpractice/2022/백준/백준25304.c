#include <stdio.h>

int main(void) {
    int totalAmount, n, price, num, i, sum=0;
    
    while(1)
    {
        scanf("%d", &totalAmount);

        if (totalAmount>0&&totalAmount<=1000000000)
            break;
    }

    while(1)
    {
        scanf("%d", &n);

        if (n>0&&n<=100)
            break;
    }

    for (i=0;i<n;i++)
    {
        while (1)
        {
            scanf("%d %d", &price, &num);

            if (price>=1&&price<=1000000&&num>=1&&num<=10)
                break;
        }

        sum += price*num;
    }

    if (sum==totalAmount)
        printf("Yes");
    else
        printf("No");

    return 0;
}