#include <iostream>
#include <vector>
#include <algorithm>
//#include <cstdio>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n;
    std::cin >> n;
    if (n==1 || n==2) {
        std::cout << n;
        return 0;
    }

    std::vector<int> fruits1, fruits2;
    for (int i=0 ; i<n/2 ; i++) {
        int tmp;
        std::cin >> tmp;
        fruits1.push_back(tmp);
    }
    for (int i=n/2 ; i<n ; i++) {
        int tmp;
        std::cin >> tmp;
        fruits2.push_back(tmp);
    }

    // for(std::vector<int>::iterator itr = fruits1.begin() ; itr != fruits1.end() ; itr++) {
    //     std::cout << *itr << "\n";
    // }

    // std::cout << "\n";

    // for(std::vector<int>::iterator itr = fruits2.begin() ; itr != fruits2.end() ; itr++) {
    //     std::cout << *itr << "\n";
    // }

    int type2[2];
    
    if(n%2==1) {
        type2[0] = fruits2[0];
        fruits2.erase(fruits2.begin());
    }

    std::vector<int>::reverse_iterator itr1 = fruits1.rbegin();
    std::vector<int>::iterator itr2 = fruits2.begin();

    for (int i = 0; i<n/2 ; i++) {
        
    }

    return 0;
}