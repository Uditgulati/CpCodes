#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	ll l[n], r[n];
	map <ll, int> mp;
	for(int i = 0; i < n; i++) {
		scanf("%lld%lld", &l[i], &r[i]);
		ll l1 = l[i], r1 = r[i] + 1ll;
		if(mp.count(l1))
			mp[l1]++;
		else
			mp[l1] = 1;
		if(mp.count(r1))
			mp[r1]--;
		else
			mp[r1] = -1;
	}
	ll prev = -1ll;
	map<ll, int>::iterator it;
	int tot = 0;
	ll ans[n + 1];
	memset(ans, 0, sizeof ans);
	for(it = mp.begin(); it != mp.end(); it++) {
		ll curr = it -> first;
		int freq = it -> second;
		if(prev != -1ll) {
			ll num = (curr - prev);
			ans[tot] += num;
		}
		tot += freq;
		prev = curr;
	}
	for(int i = 1; i <= n; i++)
		printf("%lld ", ans[i]);
	printf("\n");
	return 0;
}