#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int u, v;
		scanf("%d%d", &u, &v);
		ll sum = u + v;
		ll tot = (sum * (sum + 1)) / 2;
		tot++;
		tot += (ll)u;
		printf("%lld\n", tot);	
	}
	return 0;
}