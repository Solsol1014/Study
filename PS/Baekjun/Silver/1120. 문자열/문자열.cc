#include <iostream>
// #include <vector>
// #include <set>
#include <deque>
// #include <algorithm>
// #include <cstdio>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    std::string a, b;
    std::cin >> a >> b;

    int lencomp = b.size()-a.size();
    int min = 51;

    for (int i = 0 ; i<lencomp+1 ; i++) {
        int comp = 0;
        for (int j = 0 ; j<a.size() ; j++) {
            if (a[j]!=b[j+i])
                comp++;
        }
        if (comp < min) {
            min = comp;
            if(min == 0)
                break;
        }
    }

    std::cout << min;

    return 0;
}