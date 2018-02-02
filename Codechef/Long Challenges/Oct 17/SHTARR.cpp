#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 10;
const int siz1 = 1e4 + 10;
const ll modu = 1e9 + 7;

int tree[4 * siz], arr[siz];
vector <int> seg[siz1];

void build(int node, int start, int end) {
	if(start == end)
		tree[node] = arr[start];
	else {
		int mid = (start + end) / 2;	
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		tree[node] = max(tree[2 * node], tree[2 * node + 1]);	
	}
}
int query(int node, int start, int end, int l, int r) {
	if(r < start || end < l)
		return 0;
	if(l <= start && end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	int s1 = query(2 * node, start, mid, l, r);
	int s2 = query(2 * node + 1, mid + 1, end, l, r);
	return max(s1, s2);
}
void update(int node, int start, int end, int ind, int val) {
	if(start == end)
		tree[node] += val;
	else {
		int mid = (start + end) / 2;
		if(start <= ind &&  ind <= mid)
			update(2 * node, start, mid, ind, val);
		else
			update(2 * node + 1, mid + 1, end, ind, val);
		tree[node] = max(tree[2 * node], tree[2 * node + 1]);
	}
}

int binary(int i, int n, int x) {
	int l = i, r = n;
	while(l < r) {
		int mid = (l + r) / 2;
		int val = query(1, 0, n - 1, i, mid);
		if(x <= val)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, q;
		memset(tree, 0, sizeof tree);
		scanf("%d%d", &n, &q);
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		build(1, 0, n - 1);
		int sq = sqrt(n);
		int num = ceil((float) n / sq);
		int ind1 = 0, ind2 = sq - 1;
		for(int i = 0; i < num; i++) {
			seg[i].clear();
			int maxi = -1;
			for(int j = ind1; j <= ind2; j++) {
				if(j >= n)
					break;
				if(arr[j] > maxi)
					maxi = arr[j], seg[i].push_back(arr[j]);
			}
			ind1 += sq, ind2 += sq;
		}
		while(q--) {
			string s;
			cin >> s;
			if(s == "+") {
				int ind, x;
				scanf("%d%d", &ind, &x);
				arr[ind - 1] += x;
				update(1, 0, n - 1, ind - 1, x);
				int maxi = -1;
				int pos = (ind - 1) / sq;
				seg[pos].clear();
				ind1 = pos * sq;
				ind2 = ind1 + sq - 1;
				for(int j = ind1; j <= ind2; j++) {
					if(j >= n)
						break;
					if(arr[j] > maxi)
						maxi = arr[j], seg[pos].push_back(arr[j]);
				}
			}
			else {
				int ind, l, r;
				scanf("%d%d%d", &ind, &l, &r);
				int l1 = binary(ind - 1, n, l);
				int r1 = binary(ind - 1, n, r);
				if(l1 == n) {
					printf("0\n");
					continue;
				}
				if(r1 == n)
					r1--;
				int ans1 = 0, ans2 = 0, ans3 = 0;
				int pos1 = l1 / sq, pos2 = r1 / sq;
				ind1 = pos1 * sq;
				ind2 = ind1 + sq - 1;
				int maxi = -1;
				for(int i = ind - 1; i <= ind2; i++) {
					if(i >= n)
						break;
					if(arr[i] >= l && arr[i] > maxi)
						ans1++;
					if(arr[i] >= r)
						break;
					maxi = max(maxi, arr[i]);
				}
				for(int i = pos1 + 1; i < pos2; i++) {
					int high = upper_bound(seg[i].begin(), seg[i].end(), maxi) - seg[i].begin();
					int len3 = seg[i].size();
					ans3 += (len3 - high);
					maxi = max(maxi, seg[i][len3 - 1]);
				}
				ind1 = pos2 * sq;
				ind2 = ind1 + sq - 1;
				for(int i = ind1; i <= ind2; i++) {
					if(pos1 == pos2 || i >= n)
						break;
					if(arr[i] >= l && arr[i] > maxi)
						ans2++;
					if(arr[i] >= r)
						break;
					maxi = max(maxi, arr[i]);
				}
				printf("%d\n", ans1 + ans2 + ans3);
			}
		}		
	}
	return 0;
}