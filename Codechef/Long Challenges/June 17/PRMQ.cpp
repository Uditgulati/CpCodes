#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 2;
int factor[siz];
vector <int> primes[siz];
vector <int> tree[2 * siz];
void build(int node, int start, int end) {
	if(start == end) {
		int len = primes[start].size();
		for(int i = 0; i < len; i++)
			tree[node].push_back(primes[start][i]);
	}
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
	}
}
int query(int node, int start, int end, int l, int r, int x, int y) {
	if(r < start || end < l)
		return 0;
	if(l <= start  && end <= r) {
		int index1 = (lower_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin());
		int index2 = (upper_bound(tree[node].begin(), tree[node].end(), y) - tree[node].begin());
		int tot = index2 - index1;
		return tot;
	}
	int mid = (start + end) / 2;
	int q1 = query(2 * node, start, mid, l, r, x, y);
	int q2 = query(2 * node + 1, mid + 1, end, l, r, x, y);
	return (q1 + q2);
}
int main() {
	memset(factor, 0, sizeof(int) * siz);
	factor[1] = 1;
	for(int i = 2; i < siz; i++)
		if(!factor[i])
			for(int j = i; j < siz; j += i)
				if(!factor[j])
					factor[j] = i;
	int n, q;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for(int i = 0; i < n; i++) {
		int val = arr[i];
		while(val != 1) {
			int p = factor[val];
			val /= p;
			primes[i].push_back(p);
		}
	}
	build(1, 0, n - 1);
	scanf("%d", &q);
	while(q--) {
		int l, r, x, y;
		scanf("%d%d%d%d", &l, &r, &x, &y);
		int ans = query(1, 0, n - 1, l - 1, r - 1, x, y);
		printf("%d\n", ans);
	}
	return 0;
}