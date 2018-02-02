#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, d;
		scanf("%d%d", &n, &d);
		ll arr[n], tot = 0;
		for(int i = 0; i < n; i++)
			scanf("%lld", &arr[i]);
		for(int i = 0; i < n; i++) {
			tot += arr[i];
		}
		ll n1 = n;
		if(tot % n1) {
			printf("-1\n");
			continue;
		}
		tot /= n1;
		ll ans = 0;
		int flag = 0;
		for(int i = 0; i < d; i++) {
			ll sum = 0, iter = 0;
			for(int j = i; j < n; j += d) {
				sum += arr[j], iter++;
			}
			ll sum1 = iter;
			if(sum % sum1 || sum / sum1 != tot) {
				flag = 1;
				break;
			}
			for(int j = i; j < n; j += d) {
				ll val = arr[j];
				if(val == tot)
					continue;
				else if(val > tot) {
					ll diff = val - tot;
					arr[j] -= diff;
					arr[j + d] += diff;
					ans += diff;
				}
				else {
					ll iter = 1, curr;
					ll diff = tot - val;
					for(int k = j + d; k < n; k += d) {
						if(arr[k] <= tot) {
							iter++;
							continue;
						}
						else if(arr[k] > tot)
							curr = min(arr[k] - tot, diff);
						arr[j] += curr, arr[k] -= curr;
						ans += (curr * iter);
						diff -= curr, iter++;
						if(!diff)
							break;
					}
				}
			}
		}
		if(flag)
			printf("-1\n");
		else {
			printf("%lld\n", ans);
		}
	}
	return 0;
}