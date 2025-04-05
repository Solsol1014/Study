#include <iostream>
#include <vector>
#include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    int sum = 0;
    int sums[n];
    for(int i = 0 ; i<n ; i++) {
        int tmp;
        std::cin >> tmp;
        sum += tmp;
        sums[i] = sum;
    }

    int answers[m][2];
    for(int i = 0 ; i<m ; i++) {
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        answers[i][0] = tmp1;
        answers[i][1] = tmp2;
    }

    for(int i = 0 ; i<m ; i++) {
        if(answers[i][0]==1) {
            std::cout << sums[answers[i][1]-1] << "\n";
        }
        else {
            std::cout << sums[answers[i][1]-1]-sums[answers[i][0]-2] << "\n";
        }
    }

    return 0;
}