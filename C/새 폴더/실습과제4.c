/*실습과제4*/
#include <stdio.h>

int main() {
	int A;
	scanf("%d", &A);
	if (A>=85)
		printf("상");
	else if (A>=70)
		printf("중");
	else
		printf("하");
	return 0;
} 
