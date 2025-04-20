#include <iostream>
// #include <vector>
#include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
#include <string>
// #include <list>
// #include <iterator>
#include <map>

void bfs(std::string start, std::set<int> &groupcount, std::map<std::string, int> &whatgroup, int groupnum, int m, int n);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int tc;
    std::cin >> tc;

    int answers[tc];
    for(int i = 0 ; i<tc ; i++) {
        int m, n, k;
        std::cin >> m >> n >> k;

        std::set<int> groupcount;
        std::map<std::string, int> whatgroup;
        for(int j = 0 ; j<k ; j++) {
            std::string tmp1, tmp2;
            std::cin >> tmp1 >> tmp2;
            std::string tmp = "";
            tmp.append(tmp1);
            tmp.append("/");
            tmp.append(tmp2);
            whatgroup[tmp] = 0;
        }

        for(auto itr = whatgroup.begin() ; itr!=whatgroup.end() ; itr++) {
            if(itr->second==0) {
                bfs(itr->first, groupcount, whatgroup, 0, m, n);
            }
        }

        answers[i] = groupcount.size();
    }

    for(int i = 0 ; i<tc ; i++) {
        std::cout << answers[i];
        if(i!=tc-1) 
            std::cout << "\n";
    }

    return 0;
}

void bfs(std::string start, std::set<int> &groupcount, std::map<std::string, int> &whatgroup, int groupnum, int m, int n) {
    auto itr = whatgroup.find(start);
    if(groupnum==0) {
        itr->second = groupcount.size()+1;
        groupcount.insert(groupcount.size()+1);
    }
    else {
        itr->second = groupnum;
    }

    int x = std::stoi(start.substr(0, start.find('/')));
    int y = std::stoi(start.substr(start.find('/')+1));

    std::string tmp = "";
    if(y-1>=0) {
        tmp = "";
        tmp.append(std::to_string(x));
        tmp.append("/");
        tmp.append(std::to_string(y-1));

        if(whatgroup.find(tmp)!=whatgroup.end()&&whatgroup.find(tmp)->second==0) {
            bfs(tmp, groupcount, whatgroup, itr->second, m, n);
        }
    }
    if(x-1>=0) {
        tmp = "";
        tmp.append(std::to_string(x-1));
        tmp.append("/");
        tmp.append(std::to_string(y));

        if(whatgroup.find(tmp)!=whatgroup.end()&&whatgroup.find(tmp)->second==0) {
            bfs(tmp, groupcount, whatgroup, itr->second, m, n);
        }
    }
    if(x+1<m) {
        tmp = "";
        tmp.append(std::to_string(x+1));
        tmp.append("/");
        tmp.append(std::to_string(y));

        if(whatgroup.find(tmp)!=whatgroup.end()&&whatgroup.find(tmp)->second==0) {
            bfs(tmp, groupcount, whatgroup, itr->second, m, n);
        }
    }
    if(y+1<n) {
        tmp = "";
        tmp.append(std::to_string(x));
        tmp.append("/");
        tmp.append(std::to_string(y+1));

        if(whatgroup.find(tmp)!=whatgroup.end()&&whatgroup.find(tmp)->second==0) {
            bfs(tmp, groupcount, whatgroup, itr->second, m, n);
        }
    }

    return;
}