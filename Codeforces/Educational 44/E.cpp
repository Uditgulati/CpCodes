#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 10;
const ll modu = 1e9 + 7;

int pre[siz], tree[4 * siz];

void build(int node, int start, int end) {
	if(start == end)
		tree[node] = pre[start];       // Leaf node will have a single element.
	else {
		int mid = (start + end) / 2;	
		build(2 * node, start, mid);	// Recurse on the left child.
		build(2 * node + 1, mid + 1, end);
		tree[node] = tree[2 * node] + tree[2 * node + 1];	
	}
}

void update(int node, int start, int end, int ind, int val) {
	if(start == end)
		tree[node] = val;	//Leaf node.
	else {
		int mid = (start + end) / 2;
		if(start <= ind && ind <= mid)			//If ind is in the left child,
			update(2 * node, start, mid, ind, val);	// recurse on the left child.
		else									//If ind is in the right child,
			update(2 * node + 1, mid + 1, end, ind, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

int query(int node, int start, int end, int l, int r) {
	if(r < start || end < l)
		return 0;	// range represented by a node is completely outside the given range.
	if(l <= start && end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	int s1 = query(2 * node, start, mid, l, r);
	int s2 = query(2 * node + 1, mid + 1, end, l, r);
	return (s1 + s2);
}

int main() {
	int n, k, d;
	scanf("%d%d%d", &n, &k, &d);
	int arr[n];
	for(int i= 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);

	memset(pre, 0, sizeof pre);
	memset(tree, 0, sizeof tree);

	for(int i = 0; i < siz; i++)
		pre[i] = 0;

	int prev = 0;

	int diff1 = arr[k - 1] - arr[0];

	if(diff1 <= d)
		pre[0] = 1;

	build(1, 0, n - 1);

	for(int i = 0; i < n; i++) {
		int curr = i;
		while(arr[curr] - arr[prev] > d)
			prev++;
		int ind1 = prev;
		int ind2 = i - k + 1;

		if(ind1 > ind2)
			continue;

		int value = query(1, 0, n - 1, ind1, ind2);


		if(value) {
			pre[i + 1] = 1;
			update(1, 0, n - 1, i + 1, 1);
		}

	}

	//for(int i = 0; i <= n; i++)
	//	cout << pre[i] << " ";
	//cout << endl;

	if(pre[n])
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}