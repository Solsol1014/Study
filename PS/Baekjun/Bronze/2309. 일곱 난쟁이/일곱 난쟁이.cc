#include <iostream>
#include <vector>
#include <algorithm>
//#include <cstdio>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int sum = 0;
    std::vector<int> nines;
    for (int i = 0;i<9;i++) {
        int tmp;
        std::cin >> tmp;
        sum += tmp;
        nines.push_back(tmp); 
    }

    std::vector<int> sevens;
    bool trigger = false;
    for (std::vector<int>::iterator itr = nines.begin() ; itr < nines.end()-1 ; itr++) {
        for (std::vector<int>::iterator itr2 = itr+1 ; itr2 < nines.end() ; itr2++) {
            if (sum-*itr-*itr2 == 100) {
                for (std::vector<int>::iterator itr3 = nines.begin() ; itr3 < nines.end() ; itr3++) {
                    if(itr3!=itr) {
                        if(itr3!=itr2) {
                            sevens.push_back(*itr3);
                        }
                    }
                }
                trigger = true;
                break;
            }
        }
        if(trigger)
            break;
    }

    std::sort(sevens.begin(), sevens.end());
    for (std::vector<int>::iterator itr = sevens.begin() ; itr != sevens.end() ; itr++) {
        std::cout << *itr << "\n";
    }

    return 0;
}