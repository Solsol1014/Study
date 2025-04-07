#include <iostream>
// #include <vector>
// #include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>
// #include <map>

int min(int n, int arrsave[]) {
    if(n==1 || n==2 || n==3) {
        arrsave[n] = n;
        return n;
    }
    else {
        if(arrsave[n-2]==0) {
            min(n-2, arrsave);
        }
        if (arrsave[n-1]==0) {
            min(n-1, arrsave);
        }
        

        int min1 = arrsave[n-1]+1;
        int min2 = arrsave[n-2]+2;

        if(min1<min2) {
            arrsave[n] = min1;
            return min1;
        }
        else {
            arrsave[n] = min2;
            return min2;
        }
    }
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n;
    std::cin >> n;
    int arrsave[n+1];
    for(int i = 0 ; i<=n ; i++) {
        arrsave[i] = 0;
    }
    
    std::cout << min(n, arrsave);

    return 0;
}