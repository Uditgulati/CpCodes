#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int x = n - i;
		if(x % i == 0 && x > 0)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}