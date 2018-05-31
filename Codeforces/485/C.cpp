#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

const ll inf = 1e18 + 10;

int main() {
	int n;
	scanf("%d", &n);
	ll arr1[n];
	ll arr2[n];
	for(int i = 0; i < n; i++)
		scanf("%lld", &arr1[i]);
	for(int i = 0; i < n; i++)
		scanf("%lld", &arr2[i]);

	ll ans1[n], ans2[n];

	for(int i = 0; i < n; i++)
		ans1[i] = ans2[i] = -1;

	for(int i = 0; i < n; i++) {
		ll curr = arr1[i];
		ll mini = inf;
		for(int j = 0; j < i; j++) {
			if(arr1[j] < arr1[i] && arr2[j] < mini)
				mini = arr2[j];
		}
		ans1[i] = arr2[i] + mini;
	}

	for(int i = 0; i < n; i++) {
		ll curr = arr1[i];
		ll mini = inf;
		for(int j = 0; j < i; j++) {
			if(arr1[j] < arr1[i] && ans1[j] < mini)
				mini = ans1[j];
		}
		ans2[i] = arr2[i] + mini;
	}

	ll ans = inf;

	for(int i = 0; i < n; i++)
		ans = min(ans, ans2[i]);

	if(ans == inf)
		cout << "-1" << endl;
	else
		cout << ans << endl;
	return 0;
}