#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	long double val1 = 0, val2 = 0;
	ll n1 = n;
	long double n2 = n;
	while(m--) {
		ll x, d;
		scanf("%lld%lld", &x, &d);
		val1 += (long double) (x * n1);
		long double d1 = d;
		if(d >= 0) {
			val2 += (d1 * (n2 * (n2 - 1.00) / 2.00));
		}
		else {
			if(n % 2 == 0) {
				ll lim = n1 / 2LL;
				ll num = (lim * lim);
				long double avg = (long double) num;
				val2 += (d1 * avg);
			}
			else {
				ll lim = n1 / 2LL;
				ll num = (lim * (lim + 1LL));
				long double avg = (long double) num;
				val2 += (d1 * avg);
			}
		}
	}

	cout << setprecision(10) << (val1 + val2) / n2 << endl;
	return 0;
}