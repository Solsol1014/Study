#include <iostream>
// #include <vector>
// #include <set>
#include <deque>
// #include <algorithm>
//#include <cstdio>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n;
    std::cin >> n;
    
    std::deque<int> line;
    for (int i = 0 ; i<n ; i++) {
        int tmp;
        std::cin >> tmp;
        line.push_back(tmp);
    }

    std::deque<int> waitline;
    int last = 0;
    while (true) {
        if(waitline.size()==0) {
            waitline.push_front(*(line.begin()));
            line.pop_front();
        }
        else if (*(waitline.begin())==last+1) {
            waitline.pop_front();
            last++;
            if(last==n) {
                std::cout << "Nice";
                return 0;
            }
        }
        else if (*(line.begin())==last+1) {
            line.pop_front();
            last++;
            if(last==n) {
                std::cout << "Nice";
                return 0;
            }
        }
        else {
            if (line.size()!=0) {
                waitline.push_front(*(line.begin()));
                line.pop_front();
            }
            else {
                std::cout << "Sad";
                return 0;
            }
        }
    }

    return 0;
}