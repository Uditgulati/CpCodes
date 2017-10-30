#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 5e6 + 2;
const ll modu = 1e9 + 7;
int min_factor[siz];
ll func[siz];
int main() {
	ll t;
	int l, r;
	cin >> t >> l >> r;
	memset(min_factor, 0, sizeof(int) * siz); 
	for(int i = 2; i < siz; i++)
		if(!min_factor[i]) { 
			for(int j = i; j < siz; j += i)	
				if(!min_factor[j])		
					min_factor[j] = i;
	}
	for(int i = 2; i < siz; i++) {
		ll value = i;
		int val = i;
		if(min_factor[val] == val) {
			ll a1 = val, a2 = val - 1;
			if(a1 % 2 == 0) 
				a1 /= 2;
			else
				a2 /= 2;
			ll calc = (a1 * a2) % modu;
			func[val] = calc;
			continue;
		}
		ll len = (ll)min_factor[val];
		ll num = value / len;
		ll calc = (func[len] * num) % modu;
		calc = (calc + func[num]) % modu;
		func[val] = calc;
	}
	int lim = r - l + 1;
	ll val2 = 1;
	ll ans = 0;
	for(int i = 0; i < lim; i++) {
		ll n = l + i;
		ll val1 = func[n];
		ll val = (val1 * val2) % modu;
		ans = (ans + val) % modu;
		val2 = (val2 * t) % modu;
	}
	cout << ans << endl;
	return 0;
}