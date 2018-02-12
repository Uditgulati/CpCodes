#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int g = __gcd(a, b);
	if(n % g) {
		printf("NO\n");
	}
	else {
		a /= g, b /= g, n /= g;
		if(n % a == 0) {
			printf("YES\n");
			printf("%d 0\n", n / a);
		}
		else if(n % b == 0) {
			printf("YES\n");
			printf("0 %d\n", n / b);
		}
		else {
			int lim = 10000000;
			ll n1 = n, a1 = a, b1 = b;
			int flag = 0;
			for(int i = 1; i <= lim; i++) {
				ll i1 = i;
				ll num1 = a1 * i1;
				ll num2 = n1 - num1;
				if(num2 % b1 == 0 && num2 >= 0) {
					printf("YES\n");
					cout << i1 << " " << num2 / b1 << endl;
					flag = 1;
					break;
				}
			}
			if(!flag)
				printf("NO\n");
		}
	}
	return 0;
}