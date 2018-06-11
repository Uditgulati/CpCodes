#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	ll n, m, a, b;
	cin >> n >> m >> a >> b;
	ll q = n / m, r = n % m;

	ll c1 = (a * (m - r));
	ll c2 = (b * r);
	cout << min(c1, c2) << endl;
	return 0;
}