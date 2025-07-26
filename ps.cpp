#include <iostream>
#include <vector>
#include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>
// #include <map>
// #include <cmath>

int bfs(std::vector<std::vector<int>> &box, int &noIc, std::set<std::pair<int, int>> &haveTo, int m, int n);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int m, n;
    std::cin >> n >> m;

    std::vector<std::vector<int>> box;
    int noIc = 0;
    std::set<std::pair<int, int>> haveTo;

    for(int i = 0 ; i<m ; i++) {
        std::vector<int> tmpvec;
        for(int j = 0 ; j<n ; j++) {
            int tmp;
            std::cin >> tmp;
            tmpvec.push_back(tmp);
            if(tmp==0)
                noIc++;
            else if (tmp==1)
                haveTo.insert(std::make_pair(i, j));
        }

        box.push_back(tmpvec);
    }

    if(noIc==0)
        std::cout << 0;
    else {
        int day = bfs(box, noIc, haveTo, m, n);
        if(noIc==0)
            std::cout << day;
        else
            std::cout << -1;
    }

    return 0;
}

int bfs(std::vector<std::vector<int>> &box, int &noIc, std::set<std::pair<int, int>> &haveTo, int m, int n) {
    std::set<std::pair<int, int>> newhaveTo;

    for(auto itr = haveTo.begin() ; itr!=haveTo.end() ; itr++) {
        std::pair<int, int> search = *itr;
        int x = search.first;
        int y = search.second;

        for(int i = 0 ; i<4 ; i++) {
            int tmpx, tmpy;
            if(i==0) {
                if(x==0)
                    continue;
                else {
                    tmpx = x-1;
                    tmpy = y;
                }
            }
            else if(i==1) {
                if(y==0)
                    continue;
                else {
                    tmpx = x;
                    tmpy = y-1;
                }
            }
            else if(i==2) {
                if(x==m-1)
                    continue;
                else {
                    tmpx = x+1;
                    tmpy = y;
                }
            }
            else if(i==3) {
                if(y==n-1)
                    continue;
                else {
                    tmpx = x;
                    tmpy = y+1;
                }
            }

            if(box[tmpx][tmpy]==0) {
                noIc--;
                box[tmpx][tmpy] = 1;
                newhaveTo.insert(std::make_pair(tmpx, tmpy));
            }
        }
    }
    
    haveTo.clear();

    if(newhaveTo.empty())
        return 0;
    else
        return bfs(box, noIc, newhaveTo, m, n)+1;
}