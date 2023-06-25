#include <stdio.h>

int main() {
	int a, b;
	double c;
	printf("첫 번째 정수를 입력하세요:");
	scanf("%d", &a);
	printf("두 번째 정수를 입력하세요:");
	scanf("%d", &b);
	if (a<30000&&-30000<a&&-30000<b&&b<30000) {
		printf("%d + %d = %d\n%d - %d = %d\n%d * %d = %d\n", a, b, a+b, a, b, a-b, a, b, a*b);
		if (b!=0) {
			c=(double)a/b;
			printf("%d / %d = %lf", a, b, c);
		}
	}
	else printf("절댓값이 3만이하인 정수를 입력하십시오.");
	return 0;
}
