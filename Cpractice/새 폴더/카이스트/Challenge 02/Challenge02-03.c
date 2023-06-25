#include <stdio.h>

int main() {
	int a, b, c; //입력받을 정수 3개  
	double aver; //출력할 평균값 
	scanf("%d %d %d", &a, &b, &c); //정수 3개 입력 
	aver=(double)(a+b+c)/3; //실수형으로 바꾸면서 평균값 계산 
	printf("%.2lf", aver); //평균값 출력 
	return 0;
}
