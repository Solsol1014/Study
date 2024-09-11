//성공 - 2407120558
#include <iostream>
#include <set>

int main() {
    std::set<int> ns;

    for(int i = 1 ; i < 10001 ; i++) {
        ns.insert(i);
    }

    std::set<int>::iterator iter;
    for(iter = ns.begin() ; iter != ns.end() ; iter++) {
        int temp = *iter;
        int repeat = temp;
        while(repeat<=10000) {
            int quotient = repeat/10;
            int remainder = repeat - quotient*10;
            int nonself = repeat + remainder;
            repeat = quotient;

            while(quotient != 0) {
                quotient = repeat/10;
                remainder = repeat - quotient*10;
                nonself += remainder;
                repeat = quotient;
            }

            //std::cout << nonself << std::endl;
            repeat = nonself;
            std::set<int>::iterator findIter = ns.find(nonself);

            if(findIter != ns.end()) {
                ns.erase(findIter);
            }
        }
    }

    for(iter = ns.begin() ; iter != ns.end() ; iter++) {
        std::cout << *iter << std::endl;
    }
}