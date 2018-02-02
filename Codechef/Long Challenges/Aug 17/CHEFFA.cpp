#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 100;
const ll modu = 1e9 + 7;
ll pre[siz][200][200];

ll calc(int vec[], int ind, int len) {
	ll val = 0;
	if(ind >= len - 1)
		return 1;
	int p1 = vec[ind], p2 = vec[ind + 1];
	int mini = min(vec[ind], vec[ind + 1]);
	if(pre[ind][p1][p2]) {
		val = (val + pre[ind][p1][p2]) % modu;
		return val;
	}
	int vec1[siz];
	for(int i = 0; i < siz; i++)
		vec1[i] = vec[i];
	for(int i = 0; i <= mini; i++) {
		ll val1 = calc(vec1, ind + 1, len);
		val = (val + val1) % modu;
		vec1[ind] -= 1, vec1[ind + 1] -= 1;
		vec1[ind + 2] += 1;
		len = max(len, ind + 3);
	}
	pre[ind][p1][p2] = val;
	return val;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int num[siz];
		memset(num, 0, sizeof num);
		memset(pre, 0, sizeof pre);
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &num[i]);
		}
		ll ans1 = calc(num, 0, n);
		printf("%lld\n", ans1);
	}
	return 0;
}