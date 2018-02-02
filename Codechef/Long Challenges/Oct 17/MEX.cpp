#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 2;
int arr[siz];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		memset(arr, 0, sizeof arr);
		for(int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			arr[x] = 1;
		}
		for(int i = 0; i < siz; i++) {
			if(!arr[i]) {
				if(k)
					k--;
				else {
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}