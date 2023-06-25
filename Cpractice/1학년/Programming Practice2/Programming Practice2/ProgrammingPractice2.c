#include <stdio.h>

int main(void)
{
	float rent = 3852.99;

	printf("*%f*\n", rent);
	printf("*%e*\n", rent);
	printf("*%4.2f*\n", rent);
	printf("*%13.1f*\n", rent);
	printf("*%10.3e*\n", rent);
	printf("*%+4.2f*\n", rent);
	printf("*%019.2f*\n", rent);

	return 0;
}
