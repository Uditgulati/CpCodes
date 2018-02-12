#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

map <int, vector< pair<int, int> > > mp;

bool check(int a, int b, int c) {
	if(a + b > c && b + c > a && a + c > b)
		return true;
	else
		return false;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			int x = (i ^ j);
			mp[x].push_back(make_pair(i, j));
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		int val = i;
		int len = mp[val].size();
		for(int j = 0; j < len; j++) {
			int a1 = mp[val][j].first;
			int b1 = mp[val][j].second;
			if(check(a1, b1, val) && val >= a1 && val >= b1)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}