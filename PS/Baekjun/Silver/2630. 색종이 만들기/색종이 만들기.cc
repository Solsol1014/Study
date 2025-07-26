#include <iostream>
#include <vector>
#include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>
// #include <map>

int blue = 0;
int white = 0;

void cut(std::vector<std::vector<bool>> allmap);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n;
    std::cin >> n;
    
    std::vector<std::vector<bool>> allmap;
    for(int i = 0 ; i<n ; i++) {
        std::vector<bool> tmpvec;
        for(int j = 0 ; j<n ; j++) {
            bool tmp;
            std::cin >> tmp;
            tmpvec.push_back(tmp);
        }
        allmap.push_back(tmpvec);
    }
    
    cut(allmap);
    
    std::cout << white << "\n" << blue;

    return 0;
}

void cut(std::vector<std::vector<bool>> allmap) {
    std::set<bool> check;
    for(auto itr = allmap.begin() ; itr!=allmap.end() ; itr++) {
        for(auto itr2 = itr->begin() ; itr2!=itr->end() ; itr2++) {
            check.insert(*itr2);
        }
    }
    
    int nextmapsize = allmap.size()/2;
    
    if(check.size()==1) {
        if(*(check.begin())==1)
            blue++;
        else
            white++;
    }
    else {
        std::vector<std::vector<bool>> vec1, vec2, vec3, vec4;
        for(int i = 0 ; i<nextmapsize ; i++) {
            std::vector<bool> tmpvec1, tmpvec2, tmpvec3, tmpvec4;
            for(int j = 0 ; j<nextmapsize ; j++) {
                tmpvec1.push_back(allmap[i][j]);
                tmpvec2.push_back(allmap[i][j+nextmapsize]);
                tmpvec3.push_back(allmap[i+nextmapsize][j]);
                tmpvec4.push_back(allmap[i+nextmapsize][j+nextmapsize]);
            }
            
            vec1.push_back(tmpvec1);
            vec2.push_back(tmpvec2);
            vec3.push_back(tmpvec3);
            vec4.push_back(tmpvec4);
        }
        
        cut(vec1);
        cut(vec2);
        cut(vec3);
        cut(vec4);
    }
    
    return;
}