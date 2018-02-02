#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;

ll mod(ll a) {
	return (a < 0 ? -a : a);
}
int mod(int a) {
	return (a < 0 ? -a : a);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector <ll> vec[n], calc[n];
		ll pos[n], neg[n];
		memset(pos, 0, sizeof pos);
		for(int i = 0; i < n; i++)
			neg[i] = -inf;
		for(int i = 0; i < n; i++) {
			ll m, x;
			scanf("%lld", &m);
			while(m--) {
				scanf("%lld", &x);
				vec[i].push_back(x);
			}
		}
		if(n == 1) {
			printf("0\n");
			continue;
		}
		ll m1 = 0, m2 = inf;
		int len1 = vec[0].size();
		for(int i = 0; i < len1; i++) {
			m1 = max(m1, vec[0][i]);
			m2 = min(m2, vec[0][i]);
		}
		len1 = vec[1].size();
		for(int i = 0; i < len1; i++)
			calc[1].push_back(0);
		for(int i = 0; i < len1; i++) {
			int ind = (i + len1 - 1) % len1;
			calc[1][ind] = max(mod(m1 - vec[1][i]), mod(m2 - vec[1][i]));
		}
		for(int i = 2; i < n; i++) {
			ll i1 = i;
			int len2 = vec[i - 1].size();
			for(int j = 0; j < len2; j++) {
				ll val1 = calc[i - 1][j] + (i1 * vec[i - 1][j]);
				ll val2 = calc[i - 1][j] - (i1 * vec[i - 1][j]);
				//cout << "v2 " << val2 << endl;
				pos[i - 1] = max(pos[i - 1], val1);
				neg[i - 1] = max(neg[i - 1], val2);
			}
			//cout << "p: " << pos[i - 1] << " " << neg[i - 1] << endl;
			int len = vec[i].size();
			for(int j = 0; j < len; j++) {
				calc[i].push_back(0);
			}
			for(int j = 0; j < len; j++) {
				int ind = (j + len - 1) % len;
				calc[i][ind] = max(pos[i - 1] - (i1 * vec[i][j]), neg[i - 1] + (i1 * vec[i][j]));
			}
		}
		int len0 = calc[n - 1].size();
		ll ans = -1;
		for(int i = 0; i < len0; i++) {
			//cout << calc[n - 1][i] << " ";
			ans = max(ans, calc[n - 1][i]);
		}
		//cout << endl;
		printf("%lld\n", ans);
	}
	return 0;
}