#include <stdio.h>

int main(void) {
    int price, inputmoney;

    printf("물건 값을 입력하세요: ");
    scanf("%d", &price);

    printf("사용자가 낸 돈을 입력하세요: ");
    scanf("%d", &inputmoney);

    int m5, m, t5, t, h5, h, f5, f, outmoney;

    outmoney = inputmoney - price;
    m5 = outmoney/50000;
    outmoney -= 50000*m5;
    m = outmoney/10000;
    outmoney -= 10000*m;
    t5 = outmoney/5000;
    outmoney -= 5000*t5;
    t = outmoney/1000;
    outmoney -= 1000*t;
    h5 = outmoney/500;
    outmoney -= 500*h5;
    h = outmoney/100;
    outmoney -= 100*h;
    f5 = outmoney/50;
    outmoney -= 50*f5;
    f = outmoney/10;
    outmoney -= 10*f;

    printf("오만원권: %d \n만원권: %d \n오천원권: %d \n천원권: %d \n오백원: %d \n백원: %d \n오십원: %d \n십원: %d \n", m5, m, t5, t, h5, h, f5, f);
}