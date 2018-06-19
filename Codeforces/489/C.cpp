#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

ll power(ll x, ll y, ll modu) {
	if(!y)
		return 1LL;
	ll ans = 1LL;
	x = x % modu;
	while(y) {
		if(y & 1LL)
			ans = (ans * x) % modu;
		y >>= 1LL;
		x = (x * x) % modu;  
	}
	return ans;
}

int main() {
	ll x, k;
	scanf("%lld%lld", &x, &k);
	if(x == 0) {
		printf("0\n");
		return 0;
	}
	ll k1 = k + 1ll;
	ll val1 = power(2ll, k1, modu);
	val1 = (val1 * (x%modu)) % modu;
	val1 = (val1 - power(2ll, k, modu) + modu) % modu;
	val1 = (val1 + 1ll + modu) % modu;
	cout << val1 << endl;
	return 0;
}