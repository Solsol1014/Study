#include <iostream>
#include <vector>
// #include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
#include <string>
// #include <list>
// #include <iterator>
#include <map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n;
    std::cin >> n;
    
    std::map<int, std::vector<std::string>> people;
    for(int i = 0 ; i<n ; i++) {
        int tmp;
        std::string name;
        std::cin >> tmp >> name;

        if(i==0 || people.find(tmp)==people.end()) {
            std::vector<std::string> names;
            names.push_back(name);
            people[tmp] = names;
        }
        else {
            people.find(tmp)->second.push_back(name);
        }
    }

    for(auto itr1 = people.begin() ; itr1 != people.end() ; itr1++) {
        for(auto itr2 = itr1->second.begin() ; itr2 != itr1->second.end() ; itr2++) {
            std::cout << itr1->first << " " << *itr2 << "\n";
        }
    }

    return 0;
}