#include <stdio.h>

int main(void)
{
	float f;
	float c;

	printf("�̸�: �弭��\n�й�: 202211360\n��������: 2022. 3. 14\n\n");

	printf("ȭ�� �µ��� �Է��ϼ���: ");
	scanf("%f", &f);

	c = 5.0 / 9.0 * (f - 32);

	printf("���� �µ��� %0.2f�� �Դϴ�.", c);

	return 0;
}