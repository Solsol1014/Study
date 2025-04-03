#include <iostream>
#include <vector>
#include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>

int factorial(int n);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int t;
    std::cin >> t;

    std::vector<int> ns;
    for (int i = 0 ; i<t ; i++) {
        int tmp;
        std::cin >> tmp;
        ns.push_back(tmp);
    }

    for(auto itr = ns.begin() ; itr!=ns.end() ; itr++) {
        std::set<int> counts; //321순
        int n3 = (*itr) / 3;
        for (int i = 0 ; i<=n3 ; i++) {
            int n2 = ((*itr)-(i*3))/2;
            for (int j = 0 ; j<=n2 ; j++) {
                int n1 = (*itr)-(i*3)-(j*2);
                int tmp = i*100+j*10+n1;
                counts.insert(tmp);
            }
        }
        
        int count = 0;
        for(auto itrset = counts.begin() ; itrset!=counts.end() ; itrset++) {
            if(*itrset<10 || (*itrset<100 && *itrset % 10 == 0) || *itrset%100==0) {
                count++;
            }
            else if(*itrset<100) {
                int nn2 = *itrset/10;
                int nn1 = *itrset%10;
                int tmp = factorial(nn2+nn1)/(factorial(nn1)*factorial(nn2));
                count += tmp;
            }
            else {
                int nn3 = *itrset/100;
                int nn2 = ((*itrset)-nn3*100)/10;
                int nn1 = *itrset % 10;
                if(nn2==0) {
                    int tmp = factorial(nn3+nn1)/(factorial(nn3)*factorial(nn1));
                    count += tmp;
                }
                else if (nn1==0) {
                    int tmp = factorial(nn3+nn2)/(factorial(nn3)*factorial(nn2));
                    count += tmp;
                }
                else {
                    int tmp = factorial(nn1+nn2+nn3)/(factorial(nn3)*factorial(nn2)*factorial(nn1));
                    count += tmp;
                }
            }
        }

        std::cout << count << "\n";
    }

    return 0;
}

int factorial(int n) {
    int sum = 1;
    for (int i = n ; i>0 ; i--) {
        sum *= i;
    }
    return sum;
}