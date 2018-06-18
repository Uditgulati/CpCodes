#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	ll arr[n];
	for(int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	ll c[n];
	for(int i = 0; i < n; i++)
		scanf("%lld", &c[i]);
	ll ans[n];
	for(int i = 0; i < n; i++)
		ans[i] = c[i];
	vector < pair<ll, int> > vec;
	for(int i = 0; i < n; i++)
		vec.push_back(make_pair(arr[i], i));
	sort(vec.begin(), vec.end());
	multiset<ll> pre;
	ll tot = 0;
	for(int i = 0; i < n; i++) {
		int ind = vec[i].second;
		ll val = c[ind];
		ans[ind] += tot;
		tot += val;
		pre.insert(val);
		if(pre.size() > k) {
			tot -= *(pre.begin());
			pre.erase(pre.begin());
		}
	}
	for(int i = 0; i < n; i++)
		printf("%lld ", ans[i]);
	printf("\n");
	return 0;
}