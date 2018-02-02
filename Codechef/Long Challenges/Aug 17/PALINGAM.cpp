#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;
map <int, int> mp1, mp2;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		string s1, s2;
		cin >> s1 >> s2;
		mp1.clear();
		mp2.clear();
		int len = s1.size();
		for(int i = 0; i < len; i++) {
			int val = s1[i];
			if(mp1.count(val))
				mp1[val]++;
			else
				mp1[val] = 1;
		}
		for(int i = 0; i < len; i++) {
			int val = s2[i];
			if(mp2.count(val))
				mp2[val]++;
			else
				mp2[val] = 1;
		}
		map <int, int>::iterator it;
		int count1 = 0, count2 = 0, flag = 0;
		for(it = mp1.begin(); it != mp1.end(); it++) {
			int val = it -> first, freq = it -> second;
			if(!mp2.count(val) && freq > 1)
				count1++;
			else if(!mp2.count(val))
				count2++;
		}
		for(it = mp2.begin(); it != mp2.end(); it++) {
			int val = it -> first, freq = it -> second;
			if(!mp1.count(val))
				flag = 1;
		}
		if(count1)
			printf("A\n");
		else if(count2 && !flag)
			printf("A\n");
		else
			printf("B\n");
	}
	return 0;
}