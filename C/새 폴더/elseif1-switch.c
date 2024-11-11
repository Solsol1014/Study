/*elseif1.c switch ¹öÀü*/
#include <stdio.h>

int main() {
	int A;
	scanf("%d", &A);
	switch (A/10) {
		case 10: case 9:
			printf("A");
			break;
		case 8:
			printf("B");
			break;
		case 7:
			printf("C");
			break;
		default:
			printf("F");
	}
	return 0;
} 
