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
#include <cmath>

int search(int n, int r, int c);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
    int n, r, c;
    std::cin >> n >> r >> c;
    
    std::cout << search(n, r, c);
    
    return 0;
}

int search(int n, int r, int c) {
    if(n==1) {
        if(r==0) {
            if(c==0)
                return 0;
            else
                return 1;
        }
        else {
            if(c==0)
                return 2;
            else
                return 3;
        }
    }
    else{
        int edge = std::pow(2, n);
        if(r<edge/2) {
            if(c<edge/2)
                return search(n-1, r, c);
            else
                return search(n-1, r, c-edge/2)+(int)std::pow(edge/2, 2);
        }
        else {
            if(c<edge/2)
                return search(n-1, r-edge/2, c)+(int)std::pow(edge/2, 2)*2;
            else
                return search(n-1, r-edge/2, c-edge/2)+(int)std::pow(edge/2, 2)*3;
        }
    }
}