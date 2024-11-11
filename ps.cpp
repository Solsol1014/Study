#include <iostream>
#include <vector>
//#include <cstdio>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> citylen;
    for (int i = 0;i<n-1;i++) {
        int tmp;
        std::cin >> tmp;
        citylen.push_back(tmp); 
    }
    std::vector<int> price;
    for (int i = 0;i<n;i++) {
        int tmp;
        std::cin >> tmp;
        price.push_back(tmp);
    }

    std::vector<int>::iterator begin = price.begin();
    int sum = 0;
    std::vector<int>::iterator iter;

    while (true) {
        for (iter = begin;iter!=price.end();iter++) {
            if (*begin > *iter) {
                for (int i = std::distance(price.begin(), begin);i<std::distance(price.begin(), iter);i++) {
                    sum += *begin * citylen[i];
                }

                begin = iter;
                break;
            }
        }

        if (iter == price.end()) {
            for (int i = std::distance(price.begin(), begin);i<price.size();i++) {
                sum += *begin * citylen[i];
            }

            break;
        }
    }

    std::cout << sum;
    return 0;
}