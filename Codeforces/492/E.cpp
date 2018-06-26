#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

pair<ll, ll> arr[siz];
int pre[siz];

bool func(int n) {
	int ans[n];
	for(int i = 0; i < n; i++)
		ans[i] = 1;
	ll vx, vy;
	ll val = 0ll;
	ll lim = 2e12;
	for(int i = 0; i < n; i++) {
		ll x1 = arr[i].first, y1 = arr[i].second;
		if(i == 0)
			vx = x1, vy = y1;
		else {
			ll cos = (vx * x1) + (vy * y1);
			if(cos >= 0ll) {
				ans[pre[i]] = -1;
				x1 = -x1, y1 = -y1;
			}
			vx += x1, vy += y1;
		}
	}
	val = (vx*vx) + (vy*vy);
	if(val <= lim) {
		for(int i = 0; i < n; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return true;
	}
	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		arr[i] = make_pair(x, y);
		pre[i] = i;
	}

	int num = 800;
	while(num--) {
		if(func(n))
			return 0;
		for(int i = 0; i < n; i++) {
			int ind = rand() % n;
			swap(arr[i], arr[ind]);
			swap(pre[i], pre[ind]);
		}
		
	}
	return 0;
}