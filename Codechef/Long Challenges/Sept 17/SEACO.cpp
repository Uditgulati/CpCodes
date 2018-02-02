#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;
ll ini[siz], tree[4 * siz], lazy[4 * siz];
ll pre[siz];

void build(int node, int start, int end) {
	if(start == end)
		tree[node] = ini[start];
	else {
		int mid = (start + end) / 2;	
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		// Internal node will have the sum of both of its children.
		tree[node] = (tree[2 * node] + tree[2 * node + 1]) % modu;	
	}
}

void update(int node, int start, int end, int l, int r, ll val) {
	if(lazy[node]) {
		ll curr = (((end - start + 1) % modu) * lazy[node]) % modu;
		tree[node] = (tree[node] + curr) % modu;
		if(start != end) {
			lazy[2 * node] = (lazy[2 * node] + lazy[node]) % modu;
			lazy[2 * node + 1] = (lazy[2 * node + 1] + lazy[node]) % modu;
		}
		lazy[node] = 0;
	}
	if(start > end || start > r || end < l)
		return;
	if(start >= l && end <= r) {
		ll curr = (((end - start + 1) % modu) * val) % modu;
		tree[node] = (tree[node] + curr) % modu;
		if(start != end) {
			lazy[2 * node] = (lazy[2 * node] + val) % modu;
			lazy[2 * node + 1] = (lazy[2 * node + 1] + val) % modu;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	// Internal node will have the sum of both of its children.
	tree[node] = (tree[2 * node] + tree[2 * node + 1]) % modu;
}

int query(int node, int start, int end, int l, int r) {
	if(start > end || start > r || end < l)
		return 0;
	if(lazy[node]) {
		ll curr = (((end - start + 1) % modu) * lazy[node]) % modu;
		tree[node] = (tree[node] + curr) % modu;
		if(start != end) {
			lazy[2 * node] = (lazy[2 * node] + lazy[node]) % modu;
			lazy[2 * node + 1] = (lazy[2 * node + 1] + lazy[node]) % modu;
		}
		lazy[node] = 0;
	}
	if(l <= start && end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	ll s1 = query(2 * node, start, mid, l, r);
	ll s2 = query(2 * node + 1, mid + 1, end, l, r);
	return (s1 + s2) % modu;
}


int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		memset(tree, 0, sizeof tree);
		memset(lazy, 0, sizeof lazy);
		memset(pre, 0, sizeof pre);
		scanf("%d%d", &n, &m);
		ll ans[n];
		int x[m], y[m], type[m];
		for(int i = 0; i < m; i++) {
			int x1, y1, t1;
			scanf("%d%d%d", &t1, &x1, &y1);
			x[i] = x1, y[i] = y1, type[i] = t1;
		}
		for(int i = 0; i < m; i++)
			ini[i] = 1;
		build(1, 0, m - 1);
		for(int i = m - 1; i >= 0; i--) {
			int t1 = type[i];
			if(t1 == 2) {
				int x1 = x[i], y1 = y[i];
				ll freq = query(1, 0, m - 1, i, i);
				update(1, 0, m - 1, x1 - 1, y1 - 1, freq);
			}
		}
		for(int i = 0; i < m; i++) {
			if(type[i] == 1) {
				int x1 = x[i], y1 = y[i];
				ll freq = query(1, 0, m - 1, i, i);
				pre[x1 - 1] = (pre[x1 - 1] + freq) % modu;
				pre[y1] = (pre[y1] - freq + modu) % modu;
			}
		}
		ll sum = 0;
		for(int i = 0; i < n; i++) {
			sum = (sum + pre[i]) % modu;
			ans[i] = sum;
			printf("%lld ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}