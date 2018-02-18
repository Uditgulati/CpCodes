#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	ll arr[n];
	for(int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	int s, f;
	scanf("%d%d", &s, &f);
	ll pre[n], post[n];
	ll sum1 = 0, sum2 = 0;
	for(int i = 0; i < n; i++) {
		sum1 += arr[i];
		pre[i] = sum1;
	}
	for(int i = n - 1; i >= 0; i--) {
		sum2 += arr[i];
		post[i] = sum2;
	}
	ll ans = -1, maxi = -1;
	for(int i = 0; i < n; i++) {
		int curr = i + 1;
		ll temp = 0;
		int ind = n - curr + 1;
		int ind1 = (ind + (s - 1)) % n;
		int ind2 = (ind + (f - 2)) % n;
		if(ind1 <= ind2) {
			temp += pre[ind2];
			if(ind1)
				temp -= pre[ind1 - 1];
		}
		else {
			temp += pre[ind2];
			temp += post[ind1];
		}
		if(temp > maxi)
			maxi = temp, ans = curr;
	}
	cout << ans << endl;
	return 0;
}