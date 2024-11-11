//성공 - 2407120500
#include <iostream>
#include <set>

int main() {
    int wordsCount;
    std::cin >> wordsCount;

    std::string word[wordsCount];
    for(int i = 0 ; i < wordsCount ; i++) {
        std::string temp;
        std::cin >> temp;
        word[i] = temp;
    }

    int groupwordCount = 0;

    for(int i = 0 ; i < wordsCount ; i++) {
        std::set<char> alphabets;
        char before = ' ';
        
        for(int j = 0 ; j < word[i].length() ; j++) {
            if(j == 0) {
                before = word[i][j];
                alphabets.insert(word[i][j]);
            }
            else {
                if(before != word[i][j]) {
                    std::set<char>::iterator iter;
                    iter = alphabets.find(word[i][j]);

                    if (iter == alphabets.end()) { //집합에 없을때
                        before = word[i][j];
                        alphabets.insert(word[i][j]);
                    }
                    else {
                        break;
                    }
                }
            }

            if (j == word[i].length()-1) {
                groupwordCount++;
            }
        }
    }

    std::cout << groupwordCount;
}