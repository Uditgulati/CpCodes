#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modu = 1e9 + 7;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int p, q, r, a;
		scanf("%d%d%d", &p, &q, &r);
		vector <int> x, y, z;
		for(int i = 0; i < p; i++) {
			scanf("%d", &a);
			x.push_back(a);
		}
		for(int i = 0; i < q; i++) {
			scanf("%d", &a);
			y.push_back(a);
		}
		for(int i = 0; i < r; i++) {
			scanf("%d", &a);
			z.push_back(a);
		}
		sort(x.begin(), x.end());
		sort(z.begin(), z.end());
		vector <ll> xpre, zpre;
		ll sum = 0;
		for(int i = 0; i < p; i++) {
			ll x1 = x[i];
			sum = (sum + x1) % modu;
			xpre.push_back(sum);
		}
		sum = 0;
		for(int i = 0; i < r; i++) {
			ll z1 = z[i];
			sum = (sum + z1) % modu;
			zpre.push_back(sum);
		}
		ll ans1 = 0;
		for(int i = 0; i < q; i++) {
			if(y[i] < x[0] || y[i] < z[0])
				continue;
			int index1 = (upper_bound(x.begin(), x.end(), y[i]) - x.begin());
			int index2 = (upper_bound(z.begin(), z.end(), y[i]) - z.begin());
			index1--, index2--;
			ll sum1 = xpre[index1], sum2 = zpre[index2];
			ll n1 = index1 + 1, m1 = index2 + 1, y1 = y[i];
			ll val1 = (m1 * y1) % modu;
			ll val2 = (n1 * y1) % modu;
			ll ans = (val1 * sum1) % modu;
			ans = (ans + (val2 * sum2) % modu) % modu;
			ans = (ans + (sum1 * sum2) % modu) % modu;
			ans = (ans + (val1 * val2) % modu) % modu;
			ans1 = (ans1 + ans) % modu;
		}
		printf("%lld\n", ans1);
	}	
	return 0;
}