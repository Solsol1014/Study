#include <iostream>
#include <vector>
//#include <cstdio>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
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

    long long sum = 0;
    int current_price = price[0];

    for(int i = 0;i<n-1;i++) {
        if(price[i]<current_price) {
            current_price = price[i];
        }

        sum += static_cast<long long>(current_price)*citylen[i];
    }

    std::cout << sum;
    return 0;
}