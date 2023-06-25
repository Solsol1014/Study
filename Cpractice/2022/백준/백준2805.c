#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int treenum, totalLength, *trees, maxidx, max=0, testnum=2, cutheight, sum, maxcutheight, leastsum=0, testnum2=0;

    scanf("%d %d", &treenum, &totalLength);

    trees = (int *)malloc(sizeof(int)*treenum);

    for (int i=0;i<treenum;i++)
    {
        scanf("%d", trees+i);
    }

    for (int i=0;i<treenum;i++)
    {
        if (*(trees+i)>max)
        {
            maxidx = i;
            max = *(trees+i);
        }
        leastsum += *(trees+i);
    }

    printf("%d", max/16);

    cutheight = max/2;

    while(1)
    {
        sum = 0;
        for (int i=0;i<treenum;i++)
        {
            if(*(trees+i)>cutheight)
                sum += *(trees+i) - cutheight;
        }

        if (sum>=totalLength)
        {
            if (leastsum-totalLength>=sum-totalLength)
            {
                leastsum = sum;
                maxcutheight = cutheight;
            }
        }

        if (sum==totalLength)
            break;

        testnum *= 2;

        if (sum>totalLength)
            cutheight += max/testnum;
        else if (sum<totalLength)
            cutheight -= max/testnum;
        
        if (max/testnum==0)
            break;
    }


    printf("%d", maxcutheight);

    return 0; //짝홀
    // if (totalLength<=max)
    // {
    //     cutheight = max - totalLength;

    //     sum = 0;
    //     for (int i=0;i<treenum;i++)
    //     {
    //         if(*(trees+i)>cutheight)
    //             sum += *(trees+i) - cutheight;
    //     }

    //     if (leastsum-totalLength>=sum-totalLength)
    //     {
    //         leastsum = sum;
    //         maxcutheight = cutheight;
    //     }

    //     if (sum>totalLength)
    //     {
    //         while (1)
    //         {
    //             testnum *= 2;
                
    //             if (totalLength/testnum==0)
    //             {
    //                 if (sum>totalLength)
    //                     cutheight += 1;
    //                 else if (sum<totalLength)
    //                     cutheight -= 1;
    //             }
    //             else
    //             {
    //                 if (sum>totalLength)
    //                     cutheight += totalLength/testnum;
    //                 else if (sum<totalLength)
    //                     cutheight -= totalLength/testnum;
    //             }

    //             sum = 0;
    //             for (int i=0;i<treenum;i++)
    //             {
    //                 if(*(trees+i)>cutheight)
    //                     sum += *(trees+i) - cutheight;
    //             }

    //             if (sum>=totalLength)
    //             {
    //                 if (leastsum-totalLength>=sum-totalLength)
    //                 {
    //                     leastsum = sum;
    //                     maxcutheight = cutheight;
    //                 }
    //                 else
    //                     testnum2++;
    //             }

    //             if (sum==totalLength || testnum2>100)
    //                 break;
    //         }
    //     }
    // }
    // else
    // {
    //     cutheight = 0;

    //     sum = 0;
    //     for (int i=0;i<treenum;i++)
    //     {
    //         if(*(trees+i)>cutheight)
    //             sum += *(trees+i) - cutheight;
    //     }

    //     if (leastsum-totalLength>=sum-totalLength)
    //     {
    //         leastsum = sum;
    //         maxcutheight = cutheight;
    //     }

    //     if (sum>totalLength)
    //     {
    //         while (1)
    //         {
    //             testnum *= 2;
                
    //             if (totalLength/testnum==0)
    //             {
    //                 if (sum>totalLength)
    //                     cutheight += 1;
    //                 else if (sum<totalLength)
    //                     cutheight -= 1;
    //             }
    //             else
    //             {
    //                 if (sum>totalLength)
    //                     cutheight += max/testnum;
    //                 else if (sum<totalLength)
    //                     cutheight -= max/testnum;
    //             }

    //             sum = 0;
    //             for (int i=0;i<treenum;i++)
    //             {
    //                 if(*(trees+i)>cutheight)
    //                     sum += *(trees+i) - cutheight;
    //             }

    //             if (sum>=totalLength)
    //             {
    //                 if (leastsum-totalLength>=sum-totalLength)
    //                 {
    //                     leastsum = sum;
    //                     maxcutheight = cutheight;
    //                 }
    //                 else
    //                     testnum2++;
    //             }

    //             if (sum==totalLength||testnum2>100)
    //                 break;
    //         }
    //     }
    // }

    // printf("%d", maxcutheight);

    // return 0;
}