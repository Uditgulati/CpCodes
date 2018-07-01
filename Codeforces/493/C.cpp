#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
const ll inf = 1e18 + 10;

int main() {
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	vector <int> vec;
	int prev = -1;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++) {
		int curr = s[i] - 48;
		if(curr != prev)
			vec.push_back(curr);
		prev = curr;
	}
	int tot = 0;
	int len = vec.size();
	for(int i = 0; i < len; i++) {
		if(vec[i] == 0)
			tot++;
	}
	ll x1 = x, y1 = y;
	ll ans = inf;
	for(int i = 0; i < tot; i++) {
		ll val1 = i;
		ll val2 = tot - i;
		ll val = (val1 * x1) + (val2 * y1);
		ans = min(ans, val);
	}
	if(tot == 0)
		ans = 0;
	cout << ans << endl;
	return 0;
}