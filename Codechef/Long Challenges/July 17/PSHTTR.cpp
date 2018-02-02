#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll mo = 1e9 + 7;
vector < pair<int, int> > conn[siz];
int vis[siz], fir[siz];
vector <int> eu;
vector <int> tree[8 * siz], xors[8 * siz];
int ans1, d;
void euler(int s) {
	int len = conn[s].size();
	vis[s] = 1;
	for(int i = 0; i < len; i++) {
		int temp = conn[s][i].first, val = conn[s][i].second;
		if(!vis[temp]) {
			eu.push_back(val);
			fir[temp] = d, d++;
			euler(temp);
			eu.push_back(val), d++;
		}
	}
}
void build(int node, int start, int end) {
	if(start == end)
		tree[node].push_back(eu[start]), xors[node].push_back(eu[start]);
	else {
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		int len1 = tree[2 * node].size();
		int len2 = tree[2 * node + 1].size();
		int ind1 = 0, ind2 = 0;
		while(ind1 < len1 && ind2 < len2) {
			int a = tree[2 * node][ind1];
			int b = tree[2 * node + 1][ind2];
			if(a < b)
				tree[node].push_back(a), ind1++;
			else
				tree[node].push_back(b), ind2++;
		}
		if(ind1 == len1)
			for(int i = ind2; i < len2; i++)
				tree[node].push_back(tree[2 * node + 1][i]);
		else if(ind2 == len2)
			for(int i = ind1; i < len1; i++)
				tree[node].push_back(tree[2 * node][i]);
		int len = tree[node].size();
		int num = tree[node][0];
		xors[node].push_back(num);
		for(int i = 1; i < len; i++) {
			num ^= tree[node][i];
			xors[node].push_back(num);
		}
	}
}
void query(int node, int start, int end, int l, int r, int x) {
	if(r < start || end < l)
		return;
	if(l <= start  && end <= r) {
		int index2 = (upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin());
		if(index2)
			ans1 ^= xors[node][index2 - 1];
		return;
	}
	int mid = (start + end) / 2;
	query(2 * node, start, mid, l, r, x);
	query(2 * node + 1, mid + 1, end, l, r, x);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		memset(vis, 0, sizeof vis);
		memset(fir, 0, sizeof fir);
		eu.clear();
		for(int i = 0; i < siz; i++)
			conn[i].clear();
		int siz1 = 8 * siz;
		for(int i = 0; i < siz1; i++)
			tree[i].clear(), xors[i].clear();
		scanf("%d", &n);
		for(int i = 0; i < n - 1; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			conn[u].push_back(make_pair(v, w));
			conn[v].push_back(make_pair(u, w));
		}
		fir[0] = 0, euler(1);
		int len = eu.size();
		build(1, 0, len - 1);
		scanf("%d", &m);
		while(m--) {
			int u, v, k;
			scanf("%d%d%d", &u, &v, &k);
			ans1 = d = 0;
			if(u != 1)
				query(1, 0, len - 1, 0, fir[u], k);
			int ans = ans1;
			ans1 = d = 0;
			if(v != 1)
				query(1, 0, len - 1, 0, fir[v], k);
			printf("%d\n", ans ^ ans1);
		}
	}
	return 0;
}