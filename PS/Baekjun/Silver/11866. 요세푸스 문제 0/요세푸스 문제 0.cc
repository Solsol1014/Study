#include <iostream>
#include <vector>
// #include <set>
#include <deque>
// #include <algorithm>
// #include <cstdio>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::deque<int> nums;
    for (int i = 1 ; i<=n ; i++) {
        nums.push_back(i);
    }

    std::vector<int> josep;

    while (nums.size() != 0) {
        for (int i = 0 ; i<k-1 ; i++) {
            int tmp = *(nums.begin());
            nums.pop_front();
            nums.push_back(tmp);
        }

        josep.push_back(*(nums.begin()));
        nums.pop_front();
    }

    std::cout << "<";
    for (auto itr = josep.begin() ; itr!=josep.end() ; itr++) {
        std::cout << *itr;
        if(itr!=josep.end()-1)
            std::cout << ", ";
    }
    std::cout << ">";
    
    return 0;
}