#include <iostream>
// #include <vector>
#include <set>
#include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>
// #include <map>

struct Node {
    int node;
    int count;
};

std::deque<Node> visited;
std::set<int> visitnodes;

Node bfs(int end);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    if(k<=n) {
        std::cout << n-k;
    }
    else {
        Node start;
        start.node = n;
        start.count = 0;

        visited.push_back(start);
        visitnodes.insert(n);
        Node end = bfs(k);

        std::cout << end.count;
    }

    return 0;
}

Node bfs(int end) {
    while(true) {
        Node start = *(visited.begin());
        visited.pop_front();

        if(start.node==0) {
            start.node = 1;
            start.count++;
            visitnodes.insert(1);
            if(end==1)
                return start;
        }

        Node tmp1, tmp2, tmp3;
        tmp1.node = start.node + 1;
        tmp2.node = start.node - 1;
        tmp3.node = start.node * 2;

        tmp1.count = start.count + 1;
        tmp2.count = start.count + 1;
        tmp3.count = start.count + 1;

        if(tmp1.node==end)
            return tmp1;
        if(tmp2.node==end)
            return tmp2;
        if(tmp3.node==end)
            return tmp3;

        if(visitnodes.find(tmp3.node)==visitnodes.end() && start.node<end) {
            visited.push_back(tmp3);
            visitnodes.insert(tmp3.node);
        }
        if(visitnodes.find(tmp1.node)==visitnodes.end() && start.node<end) {
            visited.push_back(tmp1);
            visitnodes.insert(tmp1.node);
        }
        if(tmp2.node!=0 && visitnodes.find(tmp2.node)==visitnodes.end()) {
            visited.push_back(tmp2);
            visitnodes.insert(tmp2.node);
        }
    }
}