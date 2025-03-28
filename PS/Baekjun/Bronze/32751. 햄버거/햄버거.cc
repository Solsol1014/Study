#include <iostream>
//#include <vector>
// #include <set>
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

    int abcd[4];
    int sum = 0;
    for (int i=0 ; i<4 ; i++) {
        int tmp;
        std::cin >> tmp;
        abcd[i] = tmp;
        sum += tmp;
    }

    if(n>sum) {
        std::cout << "No";
        return 0;
    }

    std::string hamburger;
    std::cin >> hamburger;

    char last;
    int realabcd[4] = {0, 0, 0, 0};
    for (int i = 0 ; i<hamburger.size() ; i++) {
        char now = hamburger[i];
        if (i==0 || i==hamburger.size()-1) {
            if(now!='a') {
                std::cout << "No";
                return 0;
            }
        }

        if (i!=0) {
            if(last==now) {
                std::cout << "No";
                return 0;
            }
        }

        if(now=='a')
            realabcd[0]++;
        else if (now=='b')
            realabcd[1]++;
        else if (now=='c')
            realabcd[2]++;
        else
            realabcd[3]++;
        
        last = now;
    }

    for (int i = 0 ; i<4 ; i++) {
        if(abcd[i]<realabcd[i]) {
            std::cout << "No";
            return 0;
        }
    }

    std::cout << "Yes";
    return 0;
}