#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e4 + 10;
const ll modu = 1e9 + 7;

int arr[siz];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int a, b, c, d;
		memset(arr, 0, sizeof arr);
		scanf("%d%d%d%d", &a, &b, &c, &d);
		arr[a]++;
		arr[b]++;
		arr[c]++;
		arr[d]++;
		int flag1 = 0, flag2 = 0, c1 = 0, c2 = 0;
		for(int i = 0; i < siz; i++) {
			if(arr[i] && arr[i] != 2) {
				flag1 = 1;
			}
			if(arr[i] == 2)
				c1++;
			if(arr[i] && arr[i] != 4) {
				flag2 = 1;
			}
			if(arr[i] == 4)
				c2++;
		}
		if(!flag1 && c1 == 2)
			printf("YES\n");
		else if(!flag2 && c2 == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}