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

    std::vector<long> cmds;
    for(int i = 0 ; i<n ; i++) {
        long tmp;
        std::cin >> tmp;
        cmds.push_back(tmp);
    }

    std::map<long, int> sets;
    for(auto itr = cmds.begin() ; itr!=cmds.end() ; itr++) {
        if(*itr==0) {
            if(sets.size()==0) {
                std::cout << "0" << "\n";
            }
            else {
                std::cout << sets.begin()->first << "\n";
                if(sets.begin()->second==1) {
                    sets.erase(sets.begin()->first);
                }
                else {
                    (sets.begin()->second)--;
                }
            }
        }
        else {
            if(sets.find(*itr)==sets.end()) {
                sets[*itr] = 1;
            }
            else {
                sets[*itr]++;
            }
        }
    }

    return 0;
}