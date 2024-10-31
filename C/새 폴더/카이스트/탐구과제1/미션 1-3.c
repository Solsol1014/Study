#include <stdio.h>

int main() {
	int a, b;
	double c;
	char oper;
	printf("첫 번째 정수를 입력하세요:");
	scanf("%d", &a);
	printf("두 번째 정수를 입력하세요:");
	scanf("%d", &b);
	rewind(stdin);
	printf("수행할 연산을 입력하세요:");
	scanf("%c", &oper);
	rewind(stdin);
	if(a<30000&&-30000<a&&-30000<b&&b<30000) {
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
					printf("오류"); //오류라고 출력 
				else { //b가 0이 아닌 경우 
					c=(double)a/b; //실수형으로 바꾸면서 a에서 b나눈 값을 c에 저장 
					printf("%d/%d=%.4lf", a, b, c); //연산한 값 출력 (소수 몇자리까지인지는 안적혀있길래 너무 길어질듯 해 .4로 넣었습니다.) 
				}
				break;
			case '%':
				if(b==0)
					printf("오류");
				else {
					c=a%b;
					printf("%d/%d=%d", a, b, c);
				}
				break;
			default: //입력받은 연산자가 +-*/가 아닌 경우 
				printf("연산자를 +, -, *, /, % 중 하나로 입력해주십시오."); //라고 출력
		}
	}
	else printf("절댓값이 3만 이하인 정수를 입력하십시오.");
	return 0; 
	}
