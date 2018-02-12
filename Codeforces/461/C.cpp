#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	ll n, k;
	scanf("%lld%lld", &n, &k);
	if(k == 1) {
		printf("Yes\n");
		return 0;
	}
	if(n % 2 == 0 && k > 1) {
		printf("No\n");
		return 0;
	}
	ll n1 = n + 1;
	if(k > 500) {
		printf("No\n");
		return 0;
	}
	int flag = 0;
	for(int i = 1; i <= k; i++) {
		ll i1 = i;
		if(n1 % i1)
			flag = 1;
	}
	if(flag)
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}