#include <iostream>
#include <vector>
#include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>
#include <map>

void search(std::map<int, std::vector<int>> &graph, std::map<int, int> &visit, std::set<int> &count, int node, int group);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
    int v, e; //vertex, edge
    std::cin >> v >> e;
    
    std::map<int, std::vector<int>> graph;
    std::map<int, int> visit;
    std::set<int> count;
    
    for(int i = 1 ; i<=v ; i++) {
        std::vector<int> tmp;
        graph[i] = tmp;
        visit[i] = 0;
    }
    
    for(int i = 0 ; i<e ; i++) {
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        graph.find(tmp1)->second.push_back(tmp2);
        graph.find(tmp2)->second.push_back(tmp1);
    }
    
    for(int i = 1 ; i<=v ; i++) {
        if(visit.find(i)->second==0) {
            search(graph, visit, count, i, 0);
        }
    }
    
    std::cout << count.size();
    
    return 0;
}

void search(std::map<int, std::vector<int>> &graph, std::map<int, int> &visit, std::set<int> &count, int node, int group) {
    if(group==0) {
        visit.find(node)->second = count.size()+1;
        count.insert(count.size()+1);
    }
    else {
        visit.find(node)->second = group;
    }
    
    auto graphitr = graph.find(node);
    
    for(auto itr = graphitr->second.begin() ; itr!=graphitr->second.end() ; itr++) {
        if(visit.find(*itr)->second==0) {
            search(graph, visit, count, *itr, count.size());
        }
    }
    
    return;
}