#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 2;
const ll mo = 1e9 + 7;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll n, b;
		scanf("%lld%lld", &n, &b);
		if(b >= n) {
			printf("0\n");
			continue;
		}
		ll val = n / 2;
		ll val2 = n - val;
		if(val % b == 0 || val2 % b == 0) {
			ll ans = (val * val2) / b;
			printf("%lld\n", ans);
			continue;
		}
		ll r1 = val % b, r2 = val2 % b;
		ll ans1 = ((val - r1) * (val2 + r1)) / b;
		ll ans2 = ((val + r2) * (val2 - r2)) / b;
		ans2 = max(ans1, ans2);
		ll ans3 = ((val + b - r1) * (val2 - b + r1)) / b;
		ll ans4 = ((val - b + r2) * (val2 + b - r2)) / b;
		ans4 = max(ans3, ans4);
		printf("%lld\n", max(ans2, ans4));
	}
	return 0;
}