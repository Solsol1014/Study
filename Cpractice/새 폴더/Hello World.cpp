#include <stdio.h>

int main() {
  double a, b, area;
  printf("밑변과 높이를 차례대로 입력하시오: ");
  scanf("%lf %lf", &a, &b);
  area=a*b/2;
  printf("\n삼각형의 넓이는 %.2lf입니다.", area);
  return 0;
}
