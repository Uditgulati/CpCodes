#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

ll inline power(ll x, ll y) {
	if(!y)
		return 1LL;
	ll ans = 1LL;
	x %= modu;
	while(y) {
		if(y & 1LL)
			ans = (ans * x) % modu;
		y >>= 1LL;
		x = (x * x) % modu;  
	}
	return ans;
}

int main() {
	ll n, k, a, b;
	scanf("%lld%lld%lld%lld", &n, &k, &a, &b);
	n--;
	ll arr[n + 1];
	ll val2 = a, val1 = (b * k) % modu;
	for(int i = 0; i < n + 1; i++)
		arr[i] = 1LL;
	ll ans = 0LL, temp1 = 1LL, temp2 = 1LL;
	ll temp3 = 1LL;
	for(int i = 0; i < n + 1; i++) {
		ll i1 = i;
		//cout << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << endl;
		arr[i] = (arr[i] * temp1) % modu;
		arr[n - i] = (arr[n - i] * temp2) % modu;
		temp1 = (temp1 * val1) % modu;
		temp2 = (temp2 * val2) % modu;
		arr[i] = (arr[i] * temp3) % modu;
		//cout << arr[i] << endl;
		ll inv1 = power(i1 + 1LL, modu - 2LL);	//mod inv of (i1 + 1LL)
		arr[i] = (arr[i] * inv1) % modu;
		//cout << arr[i] << endl;
		temp3 = (temp3 * (n - i1)) % modu;
		temp3 = (temp3 * inv1) % modu;
		temp3 = (temp3 * (n + i1 + 1LL)) % modu;
		temp3 = (temp3 * inv1) % modu;
	}
	for(int i = 0; i < n + 1; i++) {
		ans += arr[i];
		if(ans > modu)
			ans -= modu;
	}
	ans = (ans * k) % modu;
	printf("%lld\n", ans);
	return 0;
}