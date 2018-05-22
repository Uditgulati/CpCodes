#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int m, n;
		scanf("%d%d", &m, &n);
		ll arr1[m], arr2[m];
		ll sum1 = 0, sum2 = 0;
		for(int i = 0; i < m; i++) {
			scanf("%lld", &arr1[i]);
			sum1 = (sum1 + arr1[i]) % modu;
		}
		for(int i = 0; i < m; i++) {
			scanf("%lld", &arr2[i]);
			sum2 = (sum2 + arr2[i]) % modu;
		}
		vector <ll> fib;
		fib.push_back(1LL);
		fib.push_back(1LL);
		for(int i = 2; i < siz; i++) {
			ll curr = (fib[i - 1] + fib[i - 2]) % modu;
			fib.push_back(curr);
		}
		ll ans = 0;
		ll m1 = m;
		if(n == 1) {
			ans = (ans + sum1) % modu;
			ans = (ans * m1) % modu;
			printf("%lld\n", ans);
			continue;
		}
		if(n == 2) {
			ans = (ans + sum2) % modu;
			ans = (ans * m1) % modu;
			printf("%lld\n", ans);
			continue;
		}
		int ind1 = n - 3, ind2 = n - 2;
		ll val1 = fib[ind1], val2 = fib[ind2];
		sum1 = (sum1 * val1) % modu;
		sum2 = (sum2 * val2) % modu;
		ans = (sum1 + sum2) % modu;
		ans = (ans * m1) % modu;
		printf("%lld\n", ans);
	}
	return 0;
}