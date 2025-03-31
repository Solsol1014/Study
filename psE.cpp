#include <iostream>
#include <vector>
// #include <set>
// #include <deque>
#include <algorithm>
// #include <cstdio>
// #include <string>
// #include <list>
// #include <iterator>

bool cmp(int a, int b) {
	return a>b;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;

	std::vector<int> votes;
	std::vector<int> vote1loc;
	int count1 = 0;

	for(int i = 0 ; i<n ; i++) {
		int tmp;
		std::cin >> tmp;
		votes.push_back(tmp);
		if(tmp==1) {
			count1++;
			vote1loc.push_back(i);
		}
	}

	if(n%2==0 && count1>=n/2) {
		std::cout << 0;
		return 0;
	}
	else if(n%2==1 && count1>=(n/2)+1) {
		std::cout << 0;
		return 0;
	}

	std::vector<int> betw1;
	for(auto itr = vote1loc.begin() ; itr!=vote1loc.end() ; itr++) {
		if(itr==vote1loc.begin()) {
			betw1.push_back(*itr);
		}
		else {
			betw1.push_back(*itr - *(itr-1) - 1);
		}
	}
	if(*(vote1loc.end()-1)!=n-1) {
		betw1.push_back(n-1-*(vote1loc.end()-1));
	}

	std::sort(betw1.begin(), betw1.end(), cmp);

	int sum = 0;
	int count = 0;

	for(auto itr = betw1.begin() ; itr<betw1.end() ; itr++) {
		sum += *itr;
		count++;
		if((n-sum)%2==0) {
			if((n-sum)/2<=count1) {
				std::cout << count;
				return 0;
			}
		}
		else {
			if((n-sum)/2<count1) {
				std::cout << count;
				return 0;
			}
		}
	}

    return 0;
}

