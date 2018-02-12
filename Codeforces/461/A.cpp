#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	if(y == 0) {
		printf("No\n");
		return 0;
	}
	int c1 = y - 1;
	x -= c1;
	if(y == 1 && x > 0) {
		printf("No\n");
		return 0;
	}
	if(x >= 0 && x % 2 == 0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}