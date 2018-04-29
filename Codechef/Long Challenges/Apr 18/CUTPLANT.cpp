#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;

int arr1[siz], tree1[4 * siz];
int arr2[siz], tree2[4 * siz];
int tree3[4 * siz]; 	//min of arr1

void build1(int node, int start, int end) {
	if(start == end)
		tree1[node] = arr1[start];       // Leaf node will have a single element.
	else {
		int mid = (start + end) / 2;	
		build1(2 * node, start, mid);	// Recurse on the left child.
		build1(2 * node + 1, mid + 1, end);
		tree1[node] = max(tree1[2 * node], tree1[2 * node + 1]);	
	}
}

void build2(int node, int start, int end) {
	if(start == end)
		tree2[node] = arr2[start];       // Leaf node will have a single element.
	else {
		int mid = (start + end) / 2;	
		build2(2 * node, start, mid);	// Recurse on the left child.
		build2(2 * node + 1, mid + 1, end);
		tree2[node] = max(tree2[2 * node], tree2[2 * node + 1]);	
	}
}

void build3(int node, int start, int end) {
	if(start == end)
		tree3[node] = arr1[start];       // Leaf node will have a single element.
	else {
		int mid = (start + end) / 2;	
		build3(2 * node, start, mid);	// Recurse on the left child.
		build3(2 * node + 1, mid + 1, end);
		tree3[node] = min(tree3[2 * node], tree3[2 * node + 1]);	
	}
}

int query1(int node, int start, int end, int l, int r) {
	if(r < start || end < l)
		return -1;
	if(l <= start && end <= r)
		return tree1[node];
	int mid = (start + end) / 2;
	int s1 = query1(2 * node, start, mid, l, r);
	int s2 = query1(2 * node + 1, mid + 1, end, l, r);
	return max(s1, s2);
}

int query2(int node, int start, int end, int l, int r) {
	if(r < start || end < l)
		return -1;
	if(l <= start && end <= r)
		return tree2[node];
	int mid = (start + end) / 2;
	int s1 = query2(2 * node, start, mid, l, r);
	int s2 = query2(2 * node + 1, mid + 1, end, l, r);
	return max(s1, s2);
}

int query3(int node, int start, int end, int l, int r) {
	if(r < start || end < l)
		return inf;
	if(l <= start && end <= r)
		return tree3[node];
	int mid = (start + end) / 2;
	int s1 = query3(2 * node, start, mid, l, r);
	int s2 = query3(2 * node + 1, mid + 1, end, l, r);
	return min(s1, s2);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &arr1[i]);
		for(int i = 0; i < n; i++)
			scanf("%d", &arr2[i]);
		build1(1, 0, n - 1);
		build2(1, 0, n - 1);
		build3(1, 0, n - 1);
		int flag = 0;
		for(int i = 0; i < n; i++)
			if(arr2[i] > arr1[i]) {
				flag = 1;
				break;
			}
		if(flag) {
			printf("-1\n");
			continue;
		}
		map <int, vector<int> > mp1;
		for(int i = 0; i < n; i++) {
			int curr = arr2[i];
			mp1[curr].push_back(i);
		}
		map <int, vector<int> >::iterator it;
		int ans = 0;
		while(mp1.size() > 0) {
			it = mp1.end();
			it--;
			vector <int> vec = it -> second;
			int curr = it -> first;
			int len = vec.size();
			int l1 = vec[0], r1 = vec[0], prev = -1;
			for(int i = 0; i < len; i++) {
				r1 = vec[i], prev = vec[i - 1];
				int val = query2(1, 0, n - 1, l1, r1);
				int val1 = query3(1, 0, n - 1, l1, r1);
				//cout << "val: " << val << " " << val1 << endl;
				if(val != curr || val1 < curr) {
					int val2 = query1(1, 0, n - 1, l1, prev);
					if(val2 > curr)
						ans++;
					l1 = r1 = vec[i];
				}
				
			}
			int val2 = query1(1, 0, n - 1, l1, r1);
			//cout << "val2: " << val2 << endl;
			if(val2 > curr)
				ans++;
			mp1.erase(it);
		}
		printf("%d\n", ans);
	}
	return 0;
}