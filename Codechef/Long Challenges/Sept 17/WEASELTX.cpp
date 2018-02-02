#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int siz = 2e6 + 2;
const int lim = 20;
vector <int> conn[siz];
ll arr[siz], pre[siz], ans1[siz];
int depth[siz], visited[siz];

void dfs(int source, int l) {
	int len = conn[source].size();
	visited[source] = 1, depth[source] = l;
	for(int i = 0; i < len; i++) {
		int temp = conn[source][i];
		if(!visited[temp]) {
			dfs(temp, l + 1);
		}
	}
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	memset(visited, 0, sizeof visited);
	memset(pre, 0, sizeof pre);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		conn[u].push_back(v);
		conn[v].push_back(u);
	}
	dfs(0, 0);
	for(int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	for(int i = 0; i < n; i++) {
		ll val = arr[i];
		int ind = depth[i];
		pre[ind] ^= val;
	}
	int maxd = 0;
	for(int i = 0; i < n; i++)
		maxd = max(maxd, depth[i]);
	for(int i = 0; i < siz; i++)
		ans1[i] = pre[i];
	for(int i = 0; i < lim; i++) {
		int lim1 = (1 << lim);
		for(int mask = 0; mask < lim1; mask++) {
			if(mask & (1 << i))
				ans1[mask] ^= ans1[mask ^ (1 << i)];
		}
	}
	while(q--) {
		ll val, ans = arr[0];
		scanf("%lld", &val);
		ll diff = val - 1;
		ll val1 = 1;
		vector <int> vec;
		int times = lim;
		while(times--) {
			ll r = diff % 2;
			if(r == 1)
				vec.push_back(0);
			else
				vec.push_back(1);
			diff /= 2;
		}
		int final = 0;
		for(int i = lim - 1; i >= 0; i--) {
			final *= 2;
			final += vec[i];
			//cout << final << endl;
		}
		//cout << final << endl;
		printf("%lld\n", ans1[final]);
	}
	return 0;
}