#include <stdio.h>

int main(void)
{
	int pages = 931;

	printf("*%d*\n", pages);
	printf("*%2d*\n", pages);
	printf("*%10d*\n", pages);
	printf("*%-10d*\n", pages);
	printf("*%+d*\n", pages);

	return 0;
}
