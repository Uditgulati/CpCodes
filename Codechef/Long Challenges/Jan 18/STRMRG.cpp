#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 5e3 + 10;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;

int n, m;
int pre[siz][siz][2];
string x, y;

int calc(int i, int j, int p, int k) {
	int val = inf, flag = 0;
	if(p >= 0 && pre[i][j][p] >= 0)
		return pre[i][j][p];
	int i1 = i, j1 = j;
	while(y[j] == k) {
		if(j >= m)
			break;
		j += 1;
	}
	while(x[i] == k) {
		if(i >= n)
			break;
		i += 1;
	}
	if(m > j) {
		flag = 1;
		val = min(val, calc(i, j + 1, 1, y[j]) + 1);
	}
	if(n > i) {
		flag = 1;
		val = min(val, calc(i + 1, j, 0, x[i]) + 1);
	}
	if(!flag)
		val = 0;
	if(p >= 0)
		pre[i1][j1][p] = val;
	return val;
}

void solve() {
	for(int i = 0; i < siz; i++)
		for(int j = 0; j < siz; j++)
			pre[i][j][0] = pre[i][j][1] = -1;
	scanf("%d%d", &n, &m);
	cin >> x >> y;
	int ans = calc(0, 0, -1, -1);
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		solve();
	}
	return 0;
}