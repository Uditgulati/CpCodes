#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int ans = -1;
	for(int i = 1; i < n; i++) {
		int a1 = i, b1 = n - i;
		int x = a / a1, y = b / b1;
		ans = max(ans, min(x, y));
	}
	printf("%d\n", ans);
	return 0;
}