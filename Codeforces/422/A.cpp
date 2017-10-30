#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 2;
const ll modu = 1e9 + 7;
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int mini = min(a, b);
	ll ans = 1;
	for(int i = 1; i <= mini; i++)
		ans *= (ll)i;
	cout << ans << endl;
	return 0;
}