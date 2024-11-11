#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	double sum, limit ;

	sum = 0;
	n = 1;

	printf("limit : ");
	scanf("%lf", &limit);

	while (sum < limit)
	{
		if (n % 2 == 1)
		{
			sum += (double)n / (n + 1);
			printf("%d/%d - ", n, n + 1);
		}
		else
		{
			sum -= (double)n / (n + 1);
			printf("%d/%d + ", n, n + 1);
		}

		n++;
	}

	printf("\b\b= %lf", sum);

	return 0;
}