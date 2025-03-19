#include <iostream>
#include <vector>
//#include <cstdio>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> n;
    std::cin >> m;

    std::vector<int> numbers;
    for (int i = 0;i<n;i++) {
        int tmp;
        std::cin >> tmp;
        numbers.push_back(tmp); 
    }
    
    int max = 0;

    for (std::vector<int>::iterator itr = numbers.begin() ; itr != numbers.end()-2 ; itr++) {
        for (std::vector<int>::iterator itr2 = itr+1 ; itr2 != numbers.end()-1 ; itr2++) {
            for (std::vector<int>::iterator itr3 = itr2+1 ; itr3 != numbers.end() ; itr3++) {
                int tmp = *itr + *itr2 + *itr3;
                if(tmp <= m && tmp > max) {
                    max = tmp;
                }
            }
        }
    }

    std::cout << max;
    return 0;
}