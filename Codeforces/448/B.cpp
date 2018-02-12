#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;

int main() {
	int n, x, k;
	scanf("%d%d%d", &n, &x, &k);
	ll n1 = n, x1 = x, k1 = k;
	ll arr[n];
	for(int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	sort(arr, arr + n);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ll curr = arr[i];
		ll r = curr % x1;
		ll ini = curr - r;
		if(!r)
			ini -= x1;
		ll fir = ini + (k1 * x1);
		ll last = fir + x1;
		if(!k1)
			fir = arr[i];
		int ind1 = lower_bound(arr, arr + n, fir) - arr;
		int ind2 = lower_bound(arr, arr + n, last) - arr;
		int diff = ind2 - ind1;
		ans += (ll)diff;
	}
	cout << ans << endl;
	return 0;
}