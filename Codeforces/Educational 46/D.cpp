#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 998244353;

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
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	ll ans = 0ll;
	ll pre[n];
	memset(pre, 0, sizeof pre);
	ll so_far = 0ll;
	for(int i = 0; i < n; i++) {
		if(i)
			so_far = (so_far + pre[i - 1]) % modu;
		int ind = i + arr[i];
		if(arr[i] <= 0) {
			continue;
		}
		else if(ind < n) {
			ll tot = (so_far + 1ll) % modu;
			pre[ind] = (pre[ind] + tot) % modu;
			//cout << tot << " " << i << " " << ind << endl;
			for(int j = ind + 1; j < n; j++) {
				ll up = j - i - 1;
				ll down = j - ind;
				down = inv_mod(down, modu);
				tot = (tot * up) % modu;
				tot = (tot * down) % modu;
				pre[j] = (pre[j] + tot) % modu;
				//cout << tot << " " << i << " " << j << endl;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		ans = (ans + pre[i]) % modu;
		//cout << pre[i] << " ";
	}
	//cout << endl;
	cout << ans << endl;
	return 0;
}