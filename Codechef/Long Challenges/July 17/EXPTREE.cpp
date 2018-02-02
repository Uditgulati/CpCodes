#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
ll power(ll x, ll y, ll modu) {
	ll ans = 1;
    x = x % modu;
    while(y) {
        if(y & 1)
			ans = (ans * x) % modu;
		y >>= 1;
        x = (x * x) % modu;  
    }
    return ans;
}
ll inv(ll a, ll modu) {
	ll m0 = modu, temp, q;
    ll x0 = 0, x1 = 1;
    if (modu == 1)
       return 0;
    while(a > 1) {
        q = a / modu;
        temp = modu;
        modu = a % modu, a = temp;
        temp = x0;
        x0 = x1 - q * x0;
        x1 = temp;
    }
    if(x1 < 0)
       x1 += m0;
    return x1;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll n;
		scanf("%lld", &n);
		if(n == 1) {
			printf("0 0\n");
			continue;
		}
		ll x = n, y = n - 1;
		ll b = 2 * (2 * n - 3);
		ll g1 = __gcd(x, b);
		x /= g1, b /= g1;
		ll g2 = __gcd(y, b);
		y /= g2, b /= g2;
		ll ans1 = ((x % mod1) * (y % mod1)) % mod1;
		ll inv1 = inv(b, mod1);
		ans1 = (ans1 * inv1) % mod1;
		ll ans2 = ((x % mod2) * (y % mod2)) % mod2;
		ll inv2 = inv(b, mod2);
		ans2 = (ans2 * inv2) % mod2;
		printf("%lld %lld\n", ans1, ans2);
	}
	return 0;
}