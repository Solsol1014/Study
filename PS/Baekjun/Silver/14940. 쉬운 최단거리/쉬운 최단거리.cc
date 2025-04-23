#include <iostream>
#include <vector>
// #include <set>
#include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>
// #include <map>

struct Coord {
    int x;
    int y;
};

void bfs(Coord start, std::vector<std::vector<int>> &allmap, std::vector<std::vector<int>> &answer, int n, int m);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> allmap;
    std::vector<std::vector<int>> answer;
    Coord start;

    for(int i = 0 ; i<n ; i++) {
        std::vector<int> tmpvec;
        std::vector<int> initanswer;

        for(int j = 0 ; j<m ; j++) {
            int tmp;
            std::cin >> tmp;

            tmpvec.push_back(tmp);

            if(tmp==2) {
                start.x = i;
                start.y = j;
                initanswer.push_back(-2);
            }
            else if(tmp==0) {
                initanswer.push_back(-1);
            }
            else
                initanswer.push_back(0);
        }

        allmap.push_back(tmpvec);
        answer.push_back(initanswer);
    }

    bfs(start, allmap, answer, n, m);

    for(auto itr = answer.begin() ; itr!=answer.end() ; itr++) {
        for(auto itr2 = itr->begin() ; itr2!=itr->end() ; itr2++) {
            if(*itr2==-2)
                std::cout << "0";
            else if(*itr2==-1)
                std::cout << "0";
            else if(*itr2==0)
                std::cout << "-1";
            else
                std::cout << *itr2;

            if(itr2==itr->end()-1)
                std::cout << "\n";
            else
                std::cout << " ";
        }
    }
    
    return 0;
}

void bfs(Coord start, std::vector<std::vector<int>> &allmap, std::vector<std::vector<int>> &answer, int n, int m) {
    std::deque<Coord> havetogo;
    havetogo.push_back(start);

    while(!havetogo.empty()) {
        Coord search = *(havetogo.begin());
        havetogo.pop_front();

        for(int i = 0 ; i<4 ; i++) {
            Coord tmp;
            if(i==0) {
                if(search.x==0)
                    continue;
                else {
                    tmp.x = search.x-1;
                    tmp.y = search.y;
                }
            }
            else if(i==1) {
                if(search.y==0)
                    continue;
                else {
                    tmp.x = search.x;
                    tmp.y = search.y-1;
                }
            }
            else if(i==2) {
                if(search.x==n-1)
                    continue;
                else {
                    tmp.x = search.x+1;
                    tmp.y = search.y;
                }
            }
            else {
                if(search.y==m-1)
                    continue;
                else {
                    tmp.x = search.x;
                    tmp.y = search.y+1;
                }
            }

            if(allmap[tmp.x][tmp.y]==0)
                continue;
            
            if(answer[tmp.x][tmp.y]!=0)
                continue;

            if(answer[search.x][search.y]==-2)
                answer[tmp.x][tmp.y] = 1;
            else
                answer[tmp.x][tmp.y] = answer[search.x][search.y]+1;
                
            havetogo.push_back(tmp);
        }
    }
}