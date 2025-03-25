#include <iostream>
#include <vector>
// #include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> nums;
    for (int i = 0 ; i<n ; i++) {
        int tmp;
        std::cin >> tmp;
        
        if(tmp==0) {
            nums.pop_back();
        }
        else {
            nums.push_back(tmp);
        }
    }

    int sum = 0;
    for (auto itr = nums.begin() ; itr!=nums.end() ; itr++) {
        sum += *itr;
    }

    std::cout << sum;
    return 0;
}