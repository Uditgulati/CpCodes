#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int ans[n];
		if(n % 2) {
			int len = n - 3;
			int num = 2;
			for(int i = 0; i < len; i += 2) {
				ans[i] = num;
				num += 2;
			}
			num = 1;
			for(int i = 1; i < len; i += 2) {
				ans[i] = num;
				num += 2;
			}
			ans[n - 1] = n - 2;
			ans[n - 2] = n;
			ans[n - 3] = n - 1;
		}
		else {
			int num = 2;
			for(int i = 0; i < n; i += 2) {
				ans[i] = num;
				num += 2;
			}
			num = 1;
			for(int i = 1; i < n; i += 2) {
				ans[i] = num;
				num += 2;
			}
		}
		for(int i = 0; i < n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}