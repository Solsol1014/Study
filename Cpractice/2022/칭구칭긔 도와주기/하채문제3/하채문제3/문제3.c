#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char ch;
	int x, y;

	x = 0;
	y = 0;

	printf("���� i, j, k, l �� �ϳ��� �Է��Ͻÿ�\n");

	while (1)
	{
		printf("�Էµ� ����: ");
		scanf(" %c", &ch);
		
		if (ch == 'Q')
		{
			printf("����Ǿ����ϴ�.");
			break;
		}
		else
		{
			if (ch == 'i')
				y++;
			else if (ch == 'j')
				x--;
			else if (ch == 'k')
				y--;
			else if (ch == 'l')
				x++;

			printf("x��ǥ: %d, y��ǥ: %d\n", x, y);
		}
	}

	return 0;
}

