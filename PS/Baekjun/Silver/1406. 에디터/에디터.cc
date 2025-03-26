#include <iostream>
//#include <vector>
// #include <set>
#include <deque>
// #include <algorithm>
// #include <cstdio>
#include <string>
#include <list>
#include <iterator>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    std::string str;
    int n;
    std::deque<char> command;
    std::deque<char> Pqueue;

    std::cin >> str;
    std::cin >> n;
    for (int i = 0 ; i<n ; i++) {
        char tmp;
        std::cin >> tmp;
        command.push_back(tmp);

        if(tmp=='P') {
            char tmp2;
            std::cin >> tmp2;
            Pqueue.push_back(tmp2);
        }
    }

    std::list<char> strlist;
    for (int i = 0 ; i<str.size() ; i++) {
        strlist.push_back(str[i]);
    }

    std::list<char>::iterator cursor = strlist.end();
    char cmd;

    for (int i = 0 ; i<n ; i++) {
        cmd = *(command.begin());
        command.pop_front();

        if (cmd=='L') {
            if(cursor!=strlist.begin())
                cursor--;
        }
        else if (cmd=='D') {
            if(cursor!=strlist.end())
                cursor++;
        }
        else if (cmd=='B') {
            if(cursor!=strlist.begin()) {
                std::list<char>::iterator tmp = cursor;
                cursor--;
                strlist.erase(cursor);
                cursor = tmp;
            }
        }
        else if (cmd=='P') {
            char pcmd = *(Pqueue.begin());
            Pqueue.pop_front();
            strlist.insert(cursor, pcmd);
        }
    }

    for(auto itr = strlist.begin() ; itr!=strlist.end() ; itr++) {
        std::cout << *itr;
    }

    return 0;
}