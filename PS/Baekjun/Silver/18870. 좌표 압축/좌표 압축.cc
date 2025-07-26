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
    
    std::vector<int> coord;
    std::map<int, int> type;
    
    for(int i = 0 ; i<n ; i++) {
        int tmp;
        std::cin >> tmp;
        coord.push_back(tmp);
        type[tmp] = 0;
    }
    
    int i = 0;
    for(auto itr = type.begin() ; itr!=type.end() ; itr++) {
        itr->second = i;
        i++;
    }
    
    for(auto itr = coord.begin() ; itr!=coord.end() ; itr++) {
        std::cout << type.find(*itr)->second;
        if(itr!=coord.end()-1)
            std::cout << " ";
    }
    
    return 0;
}