#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	ll n, k;
	scanf("%lld%lld", &n, &k);
	ll arr[k];
	for(int i = 0; i < k; i++)
		scanf("%lld", &arr[i]);
	ll ans1 = -1, ans2 = -1, num = -1;
	for(int i = 0; i < k; i++) {
		ll curr = arr[i];
		ll r = n % curr;
		ll q = n / curr;
		ll temp = (q * curr);
		if(temp > num)
			num = temp, ans1 = (i + 1), ans2 = q;
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}