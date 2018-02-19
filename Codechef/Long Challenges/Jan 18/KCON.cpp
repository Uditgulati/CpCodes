#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
const ll inf = 1e18 + 10;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int arr[n];
		ll sum = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			sum += (ll)arr[i];
		}
		ll maxi1 = -inf, maxi2 = -inf;
		ll temp1 = 0, temp2 = 0;
		for(int i = 0; i < n; i++) {
			temp1 += (ll)arr[i];
			maxi1 = max(maxi1, temp1);
		}
		for(int i = n - 1; i >= 0; i--) {
			temp2 += (ll)arr[i];
			maxi2 = max(maxi2, temp2);
		}
		int num = k - 2, flag1 = 0;
		ll m1 = 0, m2 = 0, m3 = -inf;
		for(int i = 0; i < n; i++) {
			m2 += (ll)arr[i];
			if(arr[i] >= 0)
				flag1 = 1;
			if(m2 > m1)
				m1 = m2;
			if(m2 < 0)
				m2 = 0;
			m3 = max(m3, (ll)arr[i]);
		}
		if(!flag1)
			m1 = m3;
		if(k == 1) {
			printf("%lld\n", m1);
			continue;
		}
		if(k == 2) {
			ll ans = max(m1, maxi1 + maxi2);
			ans = max(ans, maxi1);
			ans = max(ans, maxi2);
			printf("%lld\n", ans);
			continue;
		}
		ll k1 = k, num1 = num;
		ll sum1 = sum * num1;
		if(maxi1 > 0)
			sum1 += maxi1;
		if(maxi2 > 0)
			sum1 += maxi2;
		sum1 = max(sum1, maxi1 + maxi2);
		printf("%lld\n", max(m1, sum1));
	}
	return 0;
}