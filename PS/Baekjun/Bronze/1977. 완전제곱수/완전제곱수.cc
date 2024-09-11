#include <iostream>
#include <cmath>

int main() {
    int min;
    int max;
    std::cin >> min;
    std::cin >> max;

    float minsqrt, maxsqrt;
    minsqrt = std::sqrt(min);
    maxsqrt = std::sqrt(max);

    int sum = 0;
    if (minsqrt-(int)minsqrt == 0) {
        int intminsqrt = (int)minsqrt;

        while(intminsqrt <= maxsqrt) {
            sum += intminsqrt*intminsqrt;
            intminsqrt++;
        }
        std::cout << sum << '\n';
        std::cout << (int)minsqrt*minsqrt << '\n';
    }
    else {
        int intminsqrt = (int)minsqrt + 1;

        if (intminsqrt > maxsqrt) {
            std::cout << -1 << '\n';
        }
        else {
            while(intminsqrt <= maxsqrt) {
                sum += intminsqrt*intminsqrt;
                intminsqrt++;
            }
            std::cout << sum << '\n';
            std::cout << ((int)minsqrt+1)*((int)minsqrt+1) << '\n';
        }
    }

    return 0;
}