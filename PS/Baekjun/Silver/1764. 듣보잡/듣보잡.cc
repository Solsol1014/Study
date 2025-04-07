#include <iostream>
#include <vector>
#include <set>
// #include <deque>
#include <algorithm>
// #include <cstdio>
#include <string>
// #include <list>
// #include <iterator>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::set<std::string> listen;
    for(int i = 0 ; i<n ; i++) {
        std::string tmp;
        std::cin >> tmp;
        listen.insert(tmp);
    }

    std::vector<std::string> seelisten;
    for(int i = 0 ; i<m ; i++) {
        std::string tmp;
        std::cin >> tmp;
        auto itr = listen.find(tmp);
        if(itr!=listen.end()) {
            seelisten.push_back(tmp);
        }
    }

    std::sort(seelisten.begin(), seelisten.end());

    std::cout << seelisten.size() << "\n";
    for(auto itr = seelisten.begin() ; itr != seelisten.end() ; itr++) {
        std::cout << *itr << "\n";
    }

    return 0;
}