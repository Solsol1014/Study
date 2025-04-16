#include <iostream>
// #include <vector>
// #include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>
// #include <map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int answers[n+1];
    answers[1] = 1;
    answers[2] = 2;
    for(int i = 3 ; i<n+1 ; i++) {
        answers[i] = answers[i-1]+answers[i-2];
        if(answers[i]>10007)
            answers[i] = answers[i]%10007;
    }

    std::cout << answers[n];

    return 0;
}
