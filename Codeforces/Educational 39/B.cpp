#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	ll n, m;
	scanf("%lld%lld", &n, &m);
	while(n > 0 && m > 0) {
		if(n >= (2LL * m))
			n = (n % (2LL * m));
		else if(m >= (2LL * n))
			m = (m % (2LL * n));
		else
			break;
	}
	cout << n << " " << m << endl;
	return 0;
}