#include <iostream>
#include <vector>
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

    int n;
    std::cin >> n;

    std::vector<int> tests;
    for (int i = 0 ; i<n ; i++) {
        int tmp;
        std::cin >> tmp;
        tests.push_back(tmp);
    }

    int fibonacci[41][2];
    fibonacci[0][0] = 1;
    fibonacci[0][1] = 0;
    fibonacci[1][0] = 0;
    fibonacci[1][1] = 1;
    for (int i = 2; i<=40 ; i++) {
        fibonacci[i][0] = fibonacci[i-1][0] + fibonacci[i-2][0];
        fibonacci[i][1] = fibonacci[i-1][1] + fibonacci[i-2][1];
    }

    for (auto itr = tests.begin() ; itr != tests.end() ; itr++) {
        std::cout << fibonacci[*itr][0] << " " << fibonacci[*itr][1] << "\n";
    }

    return 0;
}