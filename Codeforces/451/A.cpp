#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int r = n % 10;
	if(r == 0)
		;
	else if(r > 5)
		n += (10 - r);
	else
		n -= r;
	printf("%d\n", n);
	return 0;
}