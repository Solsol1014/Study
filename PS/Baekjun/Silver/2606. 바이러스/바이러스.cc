#include <iostream>
#include <vector>
#include <set>
// #include <deque>
#include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>

void dfs(std::set<int> &check, int start, std::set<int> info[]);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n, edges;
    std::cin >> n >> edges;

    std::set<int> nodes[n];
    for (int i = 0 ; i<edges ; i++) {
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        nodes[tmp1-1].insert(tmp2-1);
        nodes[tmp2-1].insert(tmp1-1);
    }
    
    std::set<int> check;
    check.insert(0);
    dfs(check, 0, nodes);

    std::cout << check.size()-1;

    return 0;
}

void dfs(std::set<int> &check, int start, std::set<int> info[]) {
    for(auto itr = info[start].begin() ; itr != info[start].end() ; itr++) {
        if(check.find(*itr)==check.end()) {
            check.insert(*itr);
            dfs(check, *itr, info);
        }
    }
    return;
}