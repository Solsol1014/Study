#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char ch;
	int x, y;

	x = 0;
	y = 0;

	printf("문자 i, j, k, l 중 하나를 입력하시오\n");

	while (1)
	{
		printf("입력된 문자: ");
		scanf(" %c", &ch);
		
		if (ch == 'Q')
		{
			printf("종료되었습니다.");
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

			printf("x좌표: %d, y좌표: %d\n", x, y);
		}
	}

	return 0;
}

