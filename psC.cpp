#include <iostream>
// #include <vector>
// #include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>

long long hanoi(int n);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;

	std::cout << hanoi(n);

    return 0;
}

long long hanoi(int n) {
	if(n==1)
		return 1;
	
	else {
		long long prv = hanoi(n-1);
		return n+prv;
	}
}

