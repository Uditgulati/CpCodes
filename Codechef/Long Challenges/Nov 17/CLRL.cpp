#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 2;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, r;
		scanf("%d%d", &n, &r);
		int arr[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		if(n == 1) {
			printf("YES\n");
			continue;
		}
		int prev = arr[0], flag = 0, dir = 1;
		int up = inf, down = -1;
		if(prev < r)
			dir = 1, down = prev;
		else if(prev > r)
			dir = 2, up = prev;
		else
			flag = 1;
		for(int i = 1; i < n; i++) {
			int val = arr[i];
			if(val > up || val < down) {
				flag = 1;
				break;
			}
			if(val == r && i < n - 1) {
				flag = 1;
				break;
			}
			if(dir == 1 && val < prev) {
				flag = 1;
				break;
			}
			else if(dir == 2 && val > prev) {
				flag = 1;
				break;
			}
			prev = val;
			if(prev < r)
				dir = 1, down = max(down, prev);
			else if(prev > r)
				dir = 2, up = min(up, prev);

		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}