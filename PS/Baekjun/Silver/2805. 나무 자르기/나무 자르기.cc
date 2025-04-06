#include <iostream>
#include <vector>
// #include <set>
// #include <deque>
#include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>

bool compare(int a, int b) {
    return a>b;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    long long n, m;
    std::cin >> n >> m;

    std::vector<long long> trees;
    for(int i = 0 ; i<n ; i++) {
        long long tmp;
        std::cin >> tmp;
        trees.push_back(tmp);
    }

    std::sort(trees.begin(), trees.end(), compare);

    std::vector<long long> length;
    for(auto itr = trees.begin()+1 ; itr!=trees.end() ; itr++) {
        length.push_back(*(itr-1) - *itr);
    }
    length.push_back(*(trees.end()-1));
    
    long long sum = 0;
    long long i = 1;
    long long answer = 0;
    for(auto itr = length.begin() ; itr!=length.end() ; itr++) {
        sum += *itr * i;
        if(sum>=m) {
            sum -= *itr * i;
            for(long long j = 1 ; j<=*itr ; j++) {
                long long tmp = sum + j*i;
                if(tmp >= m) {
                    answer += j;
                    break;
                }
            }
            break;
        }
        i++;
        answer += *itr;
    }

    std::cout << *(trees.begin())-answer;

    return 0;
}