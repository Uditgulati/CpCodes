#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		ll pre[n], suf[n];
		ll sum1 = 0, sum2 = 0;
		for(int i = 0; i < n; i++) {
			sum1 += (ll)arr[i];
			pre[i] = sum1;
		}
		for(int i = n - 1; i >= 0; i--) {
			sum2 += (ll)arr[i];
			suf[i] = sum2;
		}
		ll ans = pre[0] + suf[0];
		int mini = 0;
		for(int i = 1; i < n; i++)
			if(pre[i] + suf[i] < ans)
				ans = pre[i] + suf[i], mini = i;
		printf("%d\n", mini + 1);
	}
	return 0;
}