#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int arr[n][m], ans[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	int pre[n];
	for(int i = 0; i < n; i++)
		pre[i] = -1;

	for(int j = 0; j < m; j++) {
		int ind1 = 0;
		while(ind1 < n) {
			int ind2 = ind1 + 1;
			while(ind2 < n && arr[ind2][j] >= arr[ind2 - 1][j])
				ind2++;
			for(int i = ind1; i < ind2; i++) {
				ans[i][j] = ind2 - 1;
				pre[i] = max(pre[i], ans[i][j]);
			}
			ind1 = ind2;
		}
	}
	int k;
	scanf("%d", &k);
	while(k--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		int val = pre[l];
		//cout << val << endl;
		if(val >= r)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}