#include <stdio.h>

int main() {
	int a, b;
	double c;
	char oper;
	printf("ù ��° ������ �Է��ϼ���:");
	scanf("%d", &a);
	printf("�� ��° ������ �Է��ϼ���:");
	scanf("%d", &b);
	rewind(stdin);
	printf("������ ������ �Է��ϼ���:");
	scanf("%c", &oper);
	rewind(stdin);
	if(a<30000&&-30000<a&&-30000<b&&b<30000) {
		switch (oper) { //�����ڸ� �������� ������ �����ų switch�Լ�  
			case '+': //�����ڰ� +�϶�  
				c=a+b; //�� ���� ���� ���� c�� ���� 
				printf("%d+%d=%.0lf", a, b, c); //������ �� ��� 
				break;
			case '-': //�����ڰ� -�϶� 
				c=a-b; //a���� b�� ���� c�� ���� 
				printf("%d-%d=%.0lf", a, b, c); //������ �� ��� 
				break;
			case '*': //�����ڰ� *�϶� 
				c=a*b; // �� ������ ���� ���� c�� ���� 
				printf("%d*%d=%.0lf", a, b, c); //������ �� ��� 
				break;
			case '/': //�����ڰ� /�϶� 
				if(b==0) //b�� 0�� ��� 
					printf("����"); //������� ��� 
				else { //b�� 0�� �ƴ� ��� 
					c=(double)a/b; //�Ǽ������� �ٲٸ鼭 a���� b���� ���� c�� ���� 
					printf("%d/%d=%.4lf", a, b, c); //������ �� ��� (�Ҽ� ���ڸ����������� �������ֱ淡 �ʹ� ������� �� .4�� �־����ϴ�.) 
				}
				break;
			case '%':
				if(b==0)
					printf("����");
				else {
					c=a%b;
					printf("%d/%d=%d", a, b, c);
				}
				break;
			default: //�Է¹��� �����ڰ� +-*/�� �ƴ� ��� 
				printf("�����ڸ� +, -, *, /, % �� �ϳ��� �Է����ֽʽÿ�."); //��� ���
		}
	}
	else printf("������ 3�� ������ ������ �Է��Ͻʽÿ�.");
	return 0; 
	}
