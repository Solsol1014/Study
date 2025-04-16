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

int answers[1000001] = {0, };

void calculate(int n);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    answers[2] = 1;
    answers[3] = 1;

    int n;
    std::cin >> n;

    if(n!=1) {
        calculate(n);
        std::cout << answers[n];
    }
    if(n==1) {
        std::cout << 0;
    }

    return 0;
}

void calculate(int n) {
    if(answers[n]!=0) {
        return;
    }
    else {
        bool onlytwo = false, onlythree = false, twothree = false;
        if(n%2==0) {
            if(n%3==0) {
                twothree = true;
            }
            else {
                onlytwo = true;
            }
        }
        else if(n%3==0) {
            onlythree = true;
        }

        int min = 0;
        if(twothree) {
            if(answers[n/3]==0 && n/3!=1)
                calculate(n/3);
            if(answers[n/2]==0 && n/2!=1)
                calculate(n/2);
            if(answers[n-1]==0)
                calculate(n-1);
            
            if(answers[n/3] < answers[n/2])
                min = answers[n/3];
            else
                min = answers[n/2];
            
            if(min > answers[n-1])
                min = answers[n-1];
        }
        else if(onlythree) {
            if(answers[n/3]==0 && n/3!=1)
                calculate(n/3);
            if(answers[n-1]==0)
                calculate(n-1);

            if(answers[n/3] < answers[n-1])
                min = answers[n/3];
            else
                min = answers[n-1];
        }
        else if(onlytwo) {
            if(answers[n/2]==0 && n/2!=1)
                calculate(n/2);
            if(answers[n-1]==0)
                calculate(n-1);

            if(answers[n/2] < answers[n-1])
                min = answers[n/2];
            else
                min = answers[n-1];
        }
        else {
            if(answers[n-1]==0)
                calculate(n-1);
            
            min = answers[n-1];
        }
    
        answers[n] = min + 1;
        return;
    }
}