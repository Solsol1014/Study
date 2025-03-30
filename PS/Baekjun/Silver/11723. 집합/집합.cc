#include <iostream>
// #include <vector>
#include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
#include <string>
// #include <list>
// #include <iterator>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    std::set<int> st;
    std::string cmd;
    int tmp;
    
    for (int i = 0 ; i<n ; i++) {
        std::cin >> cmd;
        
        if (cmd=="add") {
            std::cin >> tmp;
            st.insert(tmp);
        }
        else if (cmd=="remove") {
            std::cin >> tmp;
            auto itr = st.find(tmp);
            if(itr!=st.end()) {
                st.erase(itr);
            }
        }
        else if (cmd=="check") {
            std::cin >> tmp;
            if(st.find(tmp)==st.end()) {
                std::cout << "0" << "\n";
            }
            else {
                std::cout << "1" << "\n";
            }
        }
        else if (cmd=="toggle") {
            std::cin >> tmp;
            if(st.find(tmp)==st.end()) {
                st.insert(tmp);
            }
            else {
                st.erase(st.find(tmp));
            }
        }
        else if (cmd=="all") {
            st = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        }
        else if (cmd=="empty") {
            std::set<int> temp;
            st = temp;
        }
    }
    
    return 0;
}