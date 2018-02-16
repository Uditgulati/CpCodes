#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 10;
const ll modu = 1e9 + 7;
ll ans[siz];
int pre[2 * siz], sum = 0;

int main() {
	int t;
	scanf("%d", &t);
	pre[0] = 0;
	for(int i = 1; i < 2 * siz; i++) {
		int val = i, a = 0, b = 0;
		while(val) {
			int r = val % 10;
			val /= 10;
			if(r % 2)
				a += r;
			else
				b += r;
		}
		int d = abs(a - b);
		sum += d;
		pre[i] = sum;
	}
	ans[1] = 2;
	//cout << pre[100000] << " " << pre[1000000] << endl;
	for(int i = 2; i <= siz; i++) {
		int low = i + 1, up = 2*i - 1;
		ll val = pre[up] - pre[low - 1];
		val *= 2;
		ll val1 = pre[up + 1] - pre[up];
		ans[i] = val + val1 + ans[i - 1];
	}
	while(t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}