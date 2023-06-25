/*3차시 도전과제*/
/*두개의 정수와 연산자를 입력받아 두 수를 연산한 결과를 출력하는 프로그램 만들기*/ 
#include <stdio.h>

int main() {
	char oper; //연산자 변수  
	int a, b; //입력받을 두개의 정수 변수  
	double c; //얀신하여 출력할 결과 변수  
	printf("연산자를 입력하십시오:");
	scanf("%c", &oper); //연산자 입력받기  
	rewind(stdin);
	printf("계산할 두 정수를 입력하십시오:");
	scanf("%d %d", &a, &b); //두개의 정수 입력  
	switch (oper) { //연산자를 종류별로 구분해 연산시킬 switch함수  
		case '+': //연산자가 +일때  
			c=a+b; //두 정수 더한 값을 c에 저장 
			printf("%d+%d=%.0lf", a, b, c); //연산한 값 출력 
			break;
		case '-': //연산자가 -일때 
			c=a-b; //a에서 b뺀 값을 c에 저장 
			printf("%d-%d=%.0lf", a, b, c); //연산한 값 출력 
			break;
		case '*': //연산자가 *일때 
			c=a*b; // 두 정수를 곱한 값을 c에 저장 
			printf("%d*%d=%.0lf", a, b, c); //연산한 값 출력 
			break;
		case '/': //연산자가 /일때 
			if(b==0) //b가 0인 경우 
				printf("error"); //error라고 출력 
			else { //b가 0이 아닌 경우 
				c=(double)a/b; //실수형으로 바꾸면서 a에서 b나눈 값을 c에 저장 
				printf("%d/%d=%.4lf", a, b, c); //연산한 값 출력 
			}
			break;
		default: //입력받은 연산자가 +-*/가 아닌 경우 
			printf("연산자를 +, -, *, / 중 하나로 입력해주십시오."); //라고 출력 
	}
	return 0;
} 
