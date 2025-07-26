#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
// #include <cstdio>
#include <string>
// #include <list>
// #include <iterator>
// #include <map>
// #include <cmath>

std::deque<std::string> answers;

void dfs(int n, int m, int count, std::string answer, std::vector<int> &numbers, std::set<int> &visited);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> numbers;
    for(int i = 0 ; i<n ; i++) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }
    std::sort(numbers.begin(), numbers.end());
    
    std::set<int> visited;
    dfs(n, m, 0, "", numbers, visited);
    
    auto enter = *(answers.rbegin());
    
    for(auto itr = answers.begin() ; itr!= answers.end() ; itr++) {
        std::cout << *itr;
        if(*itr != enter)
            std::cout << "\n";    
    }
    
    return 0;
}

void dfs(int n, int m, int count, std::string answer, std::vector<int> &numbers, std::set<int> &visited) {
    for(int i = 0 ; i<n ; i++) {
        std::string newstr;
        if(visited.find(numbers[i])==visited.end())
            newstr = answer+std::to_string(numbers[i]);
        else
            continue;
            
        if(count!=m-1) {
            newstr.append(" ");
            visited.insert(numbers[i]);
            dfs(n, m, count+1, newstr, numbers, visited);
            visited.erase(numbers[i]);
        }
        else
            answers.push_back(newstr);
    }
    
    if(count==m-1)
        return;
}