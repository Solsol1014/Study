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

	std::vector<int> nums;
	for (int i = 0; i<n ; i++) {
		int tmp;
		std::cin >> tmp;
		nums.push_back(tmp);
	} 

	if(n==2 && nums[0]>nums[1]) {
		std::cout << "NO";
	}
	else
		std::cout << "YES";

    return 0;
}

