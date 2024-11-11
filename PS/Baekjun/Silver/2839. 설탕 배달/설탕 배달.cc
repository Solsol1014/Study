#include <iostream>
//#include <cstdio>

int main() {
    int n;

    std::cin >> n;

    int m3 = 0;
    int m5 = 0;
    int rem = 0;

    if (n<5) {
        if (n==3) {
            m3++;
        }
        else {
            std::cout << -1;
            return 0;
        }
    }
    else {
        m5 = n/5;
        rem = n%5;
        switch (rem) {
            case 0:
                break;
            case 1:
                m5--;
                m3 += 2;
                break;
            case 2:
                if(m5<2) {
                    std::cout << -1;
                    return 0;
                }
                else {
                    m5 -= 2;
                    m3 += 4;
                }
                break;
            case 3:
                m3++;
                break;
            case 4:
                m5--;
                m3 += 3;
                break;
        }
    }

    std::cout << m3+m5;

    return 0;
}