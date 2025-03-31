#include <iostream>
// #include <vector>
#include <set>
// #include <deque>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>
#include <map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	std::cin >> n >> m;

	std::map<int, std::set<int>> NMs;

	for(int i = 0 ; i<m ; i++) {
		int tmpa, tmpb;
		std::cin >> tmpa >> tmpb;
		if(NMs.empty() || NMs.find(tmpa)==NMs.end()) {
			std::set<int> nodes;
			nodes.insert(tmpb);
			NMs.insert(std::make_pair(tmpa, nodes));
		}
		else {
			NMs.find(tmpa)->second.insert(tmpb);
		}
	}

    return 0;
}

