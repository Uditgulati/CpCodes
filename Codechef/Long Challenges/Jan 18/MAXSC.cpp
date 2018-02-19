#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector <int> vec[n];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				int x;
				scanf("%d", &x);
				vec[i].push_back(x);
			}
			sort(vec[i].begin(), vec[i].end());
		}
		ll ans = 0;
		int prev = inf, flag = 0;
		for(int i = n - 1; i >= 0; i--) {
			int ind = lower_bound(vec[i].begin(), vec[i].end(), prev) - vec[i].begin();
			ind--;
			if(ind < 0) {
				flag = 1;
				break;
			}
			prev = vec[i][ind];
			ans += (ll)prev;
		}
		if(!flag)
			printf("%lld\n", ans);
		else
			printf("-1\n");
	}
	return 0;
}