#include <iostream>
// #include <vector>
#include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>

void dfs(std::set<int> used, int last, int* correct, int count);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n;

    std::cin >> n;
    std::set<int> used;
    int correct = 0;
    used.insert(n);
    dfs(used, n, &correct, 0);

    std::cout << correct;

    return 0;
}

void dfs(std::set<int> used, int last, int* correct, int count) {
    std::set<int> nused = used;

    if(count==8) {
        (*correct)++;
        return;
    }

    if(last==1){
        int check = 0;
        if(nused.find(2)==nused.end()) {
            nused.insert(2);
            dfs(nused, 2, correct, count+1);
            nused.erase(2);
            check++;
        }
        if(nused.find(4)==nused.end()) {
            nused.insert(4);
            dfs(nused, 4, correct, count+1);
            nused.erase(4);
            check++;
        }
        if(check==0)
            return;
    }
    else if(last==2){
        int check = 0;
        if(nused.find(1)==nused.end()) {
            nused.insert(1);
            dfs(nused, 1, correct, count+1);
            nused.erase(1);
            check++;
        }
        if(nused.find(3)==nused.end()) {
            nused.insert(3);
            dfs(nused, 3, correct, count+1);
            nused.erase(3);
            check++;
        }
        if(nused.find(5)==nused.end()) {
            nused.insert(5);
            dfs(nused, 5, correct, count+1);
            nused.erase(5);
            check++;
        }
        if(check==0)
            return;
    }
    else if(last==3){
        int check = 0;
        if(nused.find(2)==nused.end()) {
            nused.insert(2);
            dfs(nused, 2, correct, count+1);
            nused.erase(2);
            check++;
        }
        if(nused.find(6)==nused.end()) {
            nused.insert(6);
            dfs(nused, 6, correct, count+1);
            nused.erase(6);
            check++;
        }
        if(check==0)
            return;
    }
    else if(last==4){
        int check = 0;
        if(nused.find(1)==nused.end()) {
            nused.insert(1);
            dfs(nused, 1, correct, count+1);
            nused.erase(1);
            check++;
        }
        if(nused.find(5)==nused.end()) {
            nused.insert(5);
            dfs(nused, 5, correct, count+1);
            nused.erase(5);
            check++;
        }
        if(nused.find(7)==nused.end()) {
            nused.insert(7);
            dfs(nused, 7, correct, count+1);
            nused.erase(7);
            check++;
        }
        if(check==0)
            return;
    }
    else if(last==5){
        int check = 0;
        if(nused.find(2)==nused.end()) {
            nused.insert(2);
            dfs(nused, 2, correct, count+1);
            nused.erase(2);
            check++;
        }
        if(nused.find(4)==nused.end()) {
            nused.insert(4);
            dfs(nused, 4, correct, count+1);
            nused.erase(4);
            check++;
        }
        if(nused.find(6)==nused.end()) {
            nused.insert(6);
            dfs(nused, 6, correct, count+1);
            nused.erase(6);
            check++;
        }
        if(nused.find(8)==nused.end()) {
            nused.insert(8);
            dfs(nused, 8, correct, count+1);
            nused.erase(8);
            check++;
        }
        if(check==0)
            return;
    }
    else if(last==6){
        int check = 0;
        if(nused.find(3)==nused.end()) {
            nused.insert(3);
            dfs(nused, 3, correct, count+1);
            nused.erase(3);
            check++;
        }
        if(nused.find(5)==nused.end()) {
            nused.insert(5);
            dfs(nused, 5, correct, count+1);
            nused.erase(5);
            check++;
        }
        if(nused.find(9)==nused.end()) {
            nused.insert(9);
            dfs(nused, 9, correct, count+1);
            nused.erase(9);
            check++;
        }
        if(check==0)
            return;
    }
    else if(last==7){
        int check = 0;
        if(nused.find(8)==nused.end()) {
            nused.insert(8);
            dfs(nused, 8, correct, count+1);
            nused.erase(8);
            check++;
        }
        if(nused.find(4)==nused.end()) {
            nused.insert(4);
            dfs(nused, 4, correct, count+1);
            nused.erase(4);
            check++;
        }
        if(check==0)
            return;
    }
    else if(last==8){
        int check = 0;
        if(nused.find(7)==nused.end()) {
            nused.insert(7);
            dfs(nused, 7, correct, count+1);
            nused.erase(7);
            check++;
        }
        if(nused.find(5)==nused.end()) {
            nused.insert(5);
            dfs(nused, 5, correct, count+1);
            nused.erase(5);
            check++;
        }
        if(nused.find(9)==nused.end()) {
            nused.insert(9);
            dfs(nused, 9, correct, count+1);
            nused.erase(9);
            check++;
        }
        if(check==0)
            return;
    }
    else if(last==9) {
        int check = 0;
        if(nused.find(8)==nused.end()) {
            nused.insert(8);
            dfs(nused, 8, correct, count+1);
            nused.erase(8);
            check++;
        }
        if(nused.find(6)==nused.end()) {
            nused.insert(6);
            dfs(nused, 6, correct, count+1);
            nused.erase(6);
            check++;
        }
        if(check==0)
        return;
    }

    return;
}