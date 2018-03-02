#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	vector < pair<int, int> > vec;
	vec.push_back(make_pair(0, 0));
	int x1 = 0, y1 = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'U')
			y1++;
		else if(s[i] == 'R')
			x1++;
		vec.push_back(make_pair(x1, y1));
	}
	int len = vec.size();
	int ans = 0;
	for(int i = 0; i < len; i++) {
		int x1 = vec[i].first;
		int y1 = vec[i].second;
		if(x1 == y1 && i > 0 && i < len - 1) {
			int x2 = vec[i - 1].first;
			int y2 = vec[i - 1].second;
			int x3 = vec[i + 1].first;
			int y3 = vec[i + 1].second;
			int flag1 = 0, flag2 = 0;
			if(x2 > y2)
				flag1 = 1;
			if(x3 > y3)
				flag2 = 1;
			if(flag1 != flag2)
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}