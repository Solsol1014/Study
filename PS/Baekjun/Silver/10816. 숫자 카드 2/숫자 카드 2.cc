#include <iostream>
#include <vector>
// #include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>
#include <map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::map<int, int> numcards;
    for(int i = 0 ; i<n ; i++) {
        int tmp;
        std::cin >> tmp;
        if(numcards.find(tmp)==numcards.end()) {
            numcards[tmp] = 1;
        }
        else {
            numcards[tmp]++;
        }
    }

    int m;
    std::cin >> m;
    std::vector<int> searchs;
    for (int i = 0 ; i<m ; i++) {
        int tmp;
        std::cin >> tmp;
        searchs.push_back(tmp);
    }

    for(auto itr = searchs.begin() ; itr!=searchs.end() ; itr++) {
        if(numcards.find(*itr)==numcards.end()) {
            std::cout << "0";
        }
        else {
            std::cout << numcards.find(*itr)->second;
        }

        if(itr!=searchs.end()-1) {
            std::cout << " ";
        }
    }

    return 0;
}