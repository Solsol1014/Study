#include <stdio.h>

int main() {
	int a, b;
	double c;
	printf("ù ��° ������ �Է��ϼ���:");
	scanf("%d", &a);
	printf("�� ��° ������ �Է��ϼ���:");
	scanf("%d", &b);
	if (a<30000&&-30000<a&&-30000<b&&b<30000) {
		printf("%d + %d = %d\n%d - %d = %d\n%d * %d = %d\n", a, b, a+b, a, b, a-b, a, b, a*b);
		if (b!=0) {
			c=(double)a/b;
			printf("%d / %d = %lf", a, b, c);
		}
	}
	else printf("������ 3�������� ������ �Է��Ͻʽÿ�.");
	return 0;
}
