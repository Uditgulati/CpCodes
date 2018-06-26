#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	while(n >= 100) {
		n -= 100;
		ans++;
	}
	while(n >= 20) {
		n -= 20;
		ans++;
	}
	while(n >= 10) {
		n -= 10;
		ans++;
	}
	while(n >= 5) {
		n -= 5;
		ans++;
	}
	while(n >= 1) {
		n -= 1;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}