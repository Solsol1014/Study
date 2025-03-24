#include <iostream>
#include <vector>
#include <set>
#include <deque>
// #include <algorithm>
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

    std::vector<int> fruits;
    for (int i = 0 ; i < n ; i++) {
        int tmp;
        std::cin >> tmp;
        fruits.push_back(tmp);
    }

    std::set<int> types;
    std::deque<int> realfruit;
    int max = 0;
    int lasttype = 0;
    int count = 0;

    for (auto itr = fruits.begin() ; itr != fruits.end() ; itr++) {
        if(types.find(*itr)==types.end()) {
            if(types.size()<2) {
                types.insert(*itr);
                realfruit.push_back(*itr);
                count = 1;
            }
            else {
                if(max < realfruit.size())
                    max = realfruit.size();
                
                types.clear();
                types.insert(lasttype);
                types.insert(*itr);

                while(realfruit.size()!=count)
                    realfruit.pop_front();
                
                realfruit.push_back(*itr);
                count = 1;
            }
        }
        else {
            realfruit.push_back(*itr);
            if (lasttype==*itr)
                count++;
            else
                count = 1;
        }

        lasttype = *itr;
        if(realfruit.size() > max)
            max = realfruit.size();
    }

    if(max==0)
        max = fruits.size();
        
    std::cout << max;

    return 0;
}