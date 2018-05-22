#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int len = n / 2;
	int arr[len];
	for(int i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + len);
	int ans1 = 0, ans2 = 0;
	for(int i = 0; i < len; i++) {
		int pos = 2 * i + 1;
		int diff = abs(pos - arr[i]);
		ans1 += diff;
	}
	for(int i = 0; i < len; i++) {
		int pos = (2 * i) + 2;
		int diff = abs(pos - arr[i]);
		ans2 += diff;
	}
	printf("%d\n", min(ans1, ans2));
	return 0;
}