#include <iostream>
//#include <vector>
// #include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int squares[4][4];
    for (int i = 0 ; i<4 ; i++) {
        for (int j = 0 ; j<4 ; j++) {
            std::cin >> squares[i][j];
        }
    }
    
    int sum = 0;
    for (int i = 1 ; i<100 ; i++) {
        for (int j = 1 ; j<100 ; j++) {
            for (int s = 0 ; s<4 ; s++) {
                if (i>=squares[s][0] && i<squares[s][2]) {
                    if(j>=squares[s][1] && j<squares[s][3]) {
                        sum++;
                        break;
                    }
                }
            }
        }
    }

    std::cout << sum;
    return 0;
}