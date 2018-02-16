#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int x, y, z, a, b, c;
		scanf("%d%d%d%d%d%d", &x, &y, &z, &a, &b, &c);
		int arr1[3] = {x, y, z};
		sort(arr1, arr1 + 3);
		x = arr1[0], y = arr1[1], z = arr1[2];
		int arr[3] = {6 * a, 3 * b, 2 * c};
		sort(arr, arr + 3);
		if(arr[0] == 6 * a) {
			printf("%d\n", (x + y + z) * a);
		}
		else if(arr[0] == 3 * b) {
			int maxi = z, ans = 0;
			int sum = x + y;
			int diff = sum - maxi;
			if(diff <= 0) {
				ans += (sum * b);
				ans += (maxi - sum) * a;
			}
			else if(diff % 2) {
				int ans1 = (maxi * b);
				ans1 += (diff / 2) * b;
				ans1 += a;
				int ans2 = (maxi - 1) * b;
				ans2 += (diff / 2) * b;
				ans2 += c;
				ans = min(ans1, ans2);
			}
			else {
				ans += (maxi * b);
				ans += (diff / 2) * b;
			}
			printf("%d\n", ans);
		}
		else if(arr[0] == 2 * c) {
			int ans = 0;
			if(arr[1] == 6 * a) {
				int mini = x;
				int tot = x + y + z;
				int ext = tot - (3 * mini);
				ans += mini * c;
				ans += a * ext;
			}
			else {
				int mini = x;
				int ext1 = y - x, ext2 = z - y;
				int ans1 = (c * mini);
				ans1 += (b * ext1);
				ans1 += (a * ext2);
				int l = min(mini, ext2);
				mini -= l, ext2 -= l;
				ext1 += (2 * l);
				int ans2 = (c * mini);
				ans2 += (b * ext1);
				ans2 += (a * ext2);
				ans = min(ans1, ans2);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}