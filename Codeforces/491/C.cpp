#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

bool check(ll n, ll k) {
	ll temp = n;
	ll tot = 0ll;
	while(n > 0ll) {
		ll curr = min(n, k);
		n -= curr;
		ll curr1 = n / 10ll;
		n -= curr1;
		tot += curr;
	}
	ll t2 = temp / 2ll;
	if(temp % 2ll)
		t2 += 1ll;
	if(tot >= t2)
		return true;
	else
		return false;
}

ll lower_bound(ll n) {
	ll l = 1ll;
	ll h = n; // Not n - 1
	while(l < h) {
		ll mid = (l + h) / 2ll;
		if(check(n, mid))
			h = mid;
		else
			l = mid + 1ll;
	}
	return l;
}

int main() {
	ll n;
	scanf("%lld", &n);
	ll ans = lower_bound(n);
	cout << ans << endl;
	return 0;
}