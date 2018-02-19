#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		int maxi = -1;
		for(int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			maxi = max(maxi, arr[i]);
		}
		ll maxi1 = maxi;
		int c, d, s;
		scanf("%d%d%d", &c, &d, &s);
		double c2 = c, d1 = d, s1 = s;
		double t1 = d1 / s1;
		for(int i = 0; i < n; i++) {
			ll curr = arr[i];

		}
		ll c1 = c - 1;
		printf("%lld", maxi1 * c1);
		cout << ".00000000" << endl;
		//nhi, nhi, galat baat
		//dusron ka code nhi dekhte
		//bad manners :P
	}
	return 0;
}