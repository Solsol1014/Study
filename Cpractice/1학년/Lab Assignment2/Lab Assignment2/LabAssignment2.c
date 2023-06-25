#include <stdio.h>

int main(void)
{
	float f;
	float c;

	printf("이름: 장서현\n학번: 202211360\n수행일자: 2022. 3. 14\n\n");

	printf("화씨 온도를 입력하세요: ");
	scanf("%f", &f);

	c = 5.0 / 9.0 * (f - 32);

	printf("섭씨 온도는 %0.2f도 입니다.", c);

	return 0;
}