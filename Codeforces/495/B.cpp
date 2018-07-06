#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ans1[n], ans2[n];
	int flag1 = 0, flag2 = 1;
	for(int i = 0; i < n; i++) {
		ans1[i] = flag1;
		ans2[i] = flag2;
		flag1 = !flag1;
		flag2 = !flag2;
	}
	int l[m], r[m];
	for(int i = 0; i < m; i++) {
		int l1, r1;
		scanf("%d%d", &l1, &r1);
		l[i] = l1, r[i] = r1;
	}
	for(int i = 0; i < n; i++)
		printf("%d", ans1[i]);
	printf("\n");
	return 0;
}