#include <iostream>
#include <vector>
#include <algorithm>
//#include <cstdio>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int p3, p4, pn;
	std::cin >> p3 >> p4 >> pn;

    for (int i = 0; i <= pn ; i++) {
        if ((p3+i)%3==0 && (p4+pn-i)%4==0) {
            std::cout << (p3+i)/3 << " " << (p4+pn-i)/4;
            return 0;
        }
    }

    std::cout << -1;
    return 0;
}