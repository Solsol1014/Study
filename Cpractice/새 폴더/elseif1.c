#include <stdio.h>

int main() {
	int A;
	scanf("%d", &A);
	if (A>=90)			printf("A");
	else if (A>=80)		printf("B");
	else if (A>=70)		printf("C");
	else				printf("F");
	return 0;
}
