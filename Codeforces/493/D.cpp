#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int pre[13] = {1, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341};

int main() {
	int n;
	scanf("%d", &n);
	if(n < 13) {
		cout << pre[n] << endl;
		return 0;
	}
	ll n1 = n;
	ll ans = pre[12];
	ans += (n1 - 12ll) * 49ll;
	cout << ans << endl;
	return 0;
}