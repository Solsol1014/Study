#include <iostream>
// #include <vector>
// #include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>

void check(int correct[], int th, int lastnum, int lastcount, int* wholecorrect, int correctnum);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int correct[10];
    for (int i = 0 ; i<10 ; i++) {
        int tmp;
        std::cin >> tmp;
        correct[i] = tmp;
    }

    int wholecorrect = 0;
    check(correct, 0, 0, 0, &wholecorrect, 0);

    std::cout << wholecorrect;

    return 0;
}

void check(int correct[], int th, int lastnum, int lastcount, int* wholecorrect, int correctnum) {
    for(int i = 1 ; i<=5 ; i++) {
        int nlastnum = lastnum;
        int nlastcount = lastcount;
        int ncorrectnum = correctnum;

        if(lastnum==i) {
            nlastcount++;
            if(nlastcount==3)
                continue;
        }
        else {
            nlastnum = i;
            nlastcount = 1;
        }

        if (correct[th]==i) {
            ncorrectnum++;
        }
        
        if(th==9) {
            // std::cout << ncorrectnum << "\n";
            if(ncorrectnum>=5)
                (*wholecorrect)++;
        }
        else {
            check(correct, th+1, nlastnum, nlastcount, wholecorrect, ncorrectnum);
        }
    }

    return;
}