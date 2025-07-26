#include <iostream>
// #include <vector>
#include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
#include <string>
// #include <list>
// #include <iterator>
// #include <map>
// #include <cmath>

std::set<std::string> answers;

void dfs(int n, int m, int count, std::string answer, int prv);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
    int n, m;
    std::cin >> n >> m;
    
    dfs(n, m, 0, "", 0);
    
    auto enter = *(answers.rbegin());
    
    for(auto itr = answers.begin() ; itr!= answers.end() ; itr++) {
        std::cout << *itr;
        if(*itr != enter)
            std::cout << "\n";    
    }
    
    return 0;
}

void dfs(int n, int m, int count, std::string answer, int prv) {
    for(int i = prv+1 ; i<=n ; i++) {
        std::string newstr = answer+std::to_string(i);
        if(count!=m-1) {
            newstr.append(" ");
            dfs(n, m, count+1, newstr, i);
        }
        else
            answers.insert(newstr);
    }
    
    if(count==m-1)
        return;
}