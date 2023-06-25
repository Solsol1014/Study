/*실습과제 두번째*/
#include <stdio.h>

int main() {
	int A;
	scanf("%d", &A);
	switch (A) {
		case 0:
			printf("모");
			break;
		case 1:
			printf("도");
			break;
		case 2:
			printf("개");
			break;
		case 3:
			printf("걸");
			break;
		case 4:
			printf("윷");
			break;
		default:
			printf("입력 오류");
	}
	return 0;
} 
