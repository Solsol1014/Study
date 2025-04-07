#include <iostream>
#include <vector>
// #include <set>
// #include <deque>
#include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> times;
    for(int i = 0 ; i<n ; i++) {
        int tmp;
        std::cin >> tmp;
        times.push_back(tmp);
    }

    std::sort(times.begin(), times.end());
    int sum = 0;
    int size = times.size();
    for(auto itr = times.begin() ; itr!=times.end() ; itr++) {
        sum += (*itr)*size;
        size--;
    }

    std::cout << sum;

    return 0;
}