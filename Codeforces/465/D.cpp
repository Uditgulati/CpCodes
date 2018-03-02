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

ll inv_mod(ll a, ll m) {
	ll g = __gcd(a, m);
	if(g != 1)
		return -1;
	return power(a, m - 2, m);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	ll n1 = n, m1 = m;
	int arr1[n], arr2[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr1[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr2[i]);
	ll num = 0, den = 0;
	ll tot1 = 0, tot2 = 0;
	for(int i = 0; i < n; i++) {
		if(arr1[i] == 0)
			tot1++;
		if(arr2[i] == 0)
			tot2++;
	}
	den = power(m1, tot1 + tot2, modu);
	ll var = 1;
	for(int i = 0; i < n; i++) {
		ll val1 = arr1[i];
		ll val2 = arr2[i];
		if(val1 && val2 && val1 < val2)
			break;
		if(val1 && val2 && val1 > val2) {
			ll x1 = (tot1 + tot2);
			ll p1 = power(m1, x1, modu);
			p1 = (p1 * var) % modu;
			num = (num + p1) % modu;
			break; 
		}
		if(val1 && val2)
			continue;

		if(val1 == 0 && val2 != 0) {
			ll num1 = m1 - val2;
			ll x1 = (tot1 + tot2 - 1LL);
			ll p1 = power(m1, x1, modu);
			p1 = (p1 * var) % modu;
			p1 = (p1 * num1) % modu;
			num = (num + p1) % modu;
		}
		else if(val1 != 0 && val2 == 0) {
			ll num2 = val1 - 1;
			ll x2 = (tot1 + tot2 - 1LL);
			ll p2 = power(m1, x2, modu);
			p2 = (p2 * var) % modu;
			p2 = (p2 * num2) % modu;
			num = (num + p2) % modu;
		}
		else if(val1 == 0 && val2 == 0) {
			ll ms = (m1 * m1);
			ll diff = ms - m1;
			ll count1 = diff / 2;
			
			ll p2 = power(m1, tot1 + tot2 - 2LL, modu);
			p2 = (p2 * var) % modu;
			var = (var * m1) % modu;
			p2 = (p2 * count1) % modu;
			num = (num + p2) % modu;
		}
		if(val1 == 0)
			tot1--;
		if(val2 == 0)
			tot2--;
	}
	//cout << num << " " << den << endl;
	ll den1 = inv_mod(den, modu);
	ll ans = (num * den1) % modu;
	cout << ans << endl;
	return 0;
}