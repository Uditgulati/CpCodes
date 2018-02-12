#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 1000;
const ll modu = 1e9 + 7;
int min_factor[siz];

ll fact[siz], ifact[siz];

inline ll power(ll x, ll y, ll modu) {
	ll ans = 1;
    x = x % modu;
    while(y) {
        if(y & 1LL)
			ans = (ans * x) % modu;
		y >>= 1LL;
        x = (x * x) % modu;  
    }
    return ans;
}

ll inv_mod(ll a, ll m) {
	return power(a, m - 2LL, m);
}

inline ll ncr(ll n, ll r) {
	ll x = fact[n], y = ifact[r], z = ifact[n - r];
	x = (x * y) % modu;
	x = (x * z) % modu;
	return x;
}

int main() {
	int q;
	scanf("%d", &q);
	memset(min_factor, 0, sizeof(int) * siz);
	for(int i = 2; i < siz; i++)
		if(!min_factor[i]) { 
			for(int j = i; j < siz; j += i)
				if(!min_factor[j])
					min_factor[j] = i;
	}
	ll p = 1;
	fact[0] = 1, ifact[0] = 1;
	for(int i = 1; i < siz; i++) {
		ll val = i;
		p = (p * val) % modu;
		ll p1 = inv_mod(p, modu);
		fact[i] = p, ifact[i] = p1;
	}
	while(q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		int val = x;
		int prev = -1, count1 = 1;
		vector <int> exp;
		while(val != 1) {
			int r = min_factor[val];
			if(r == prev)
				count1++;
			else if(prev != -1) {
				exp.push_back(count1);
				count1 = 1;
			}
			val /= r;
			prev = r;
		}
		if(x != 1)
			exp.push_back(count1);
		int len1 = exp.size();
		ll ans = 1, r = y;
		for(int i = 0; i < len1; i++) {
			ll n = exp[i];
			ll curr = ncr(n + r - 1, r - 1);
			ans = (ans * curr) % modu;
		}
		ll ans1 = power(2LL, r - 1, modu);
		ans = (ans * ans1) % modu;
		cout << ans << endl;
	}
	return 0;
}