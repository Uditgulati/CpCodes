#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	int num = a + b - c;
	int ext = n - num;
	if(a >= n || b >= n || c >= n) {
		printf("-1\n");
		return 0;
	}
	if(c > a || c > b) {
		printf("-1\n");
		return 0;
	}
	if(ext < 1 || ext > n)
		printf("-1\n");
	else
		printf("%d\n", ext);
	return 0;
}