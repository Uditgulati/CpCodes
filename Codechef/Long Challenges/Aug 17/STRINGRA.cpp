#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 4;
const ll modu = 1e9 + 7;
set <int> conn[siz];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m, flag = 0;
		for(int i = 0; i < siz; i++)
			conn[i].clear();
		scanf("%d%d", &n, &m);
		int ans[n + 1];
		for(int i = 0; i <= n; i++)
			ans[i] = -1;
		for(int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			if(x >= y || conn[x].count(y))
				flag = 1;
			conn[x].insert(y);
		}
		if(flag) {
			printf("-1\n");
			continue;
		}
		set <int>::iterator it;
		map <int, int> mp, mp1;
		int value = 1;
		for(it = conn[0].begin(); it != conn[0].end(); it++) {
			int temp = *it;
			ans[temp] = value, mp[temp] = value;
			value++;
		}
		map <int, int>::iterator it2;
		for(int i = 1; i <= n; i++) {
			for(it = conn[i].begin(); it != conn[i].end(); it++) {
				int temp = *it;
				if(ans[temp] == -1) {
					it2 = mp.begin();
					int ind = it2 -> first, val = it2 -> second;
					if(ind < temp) {
						ans[temp] = val;
						mp1[temp] = val;
					}
					else {
						flag = 1;
						break;
					}
				}
				else
					mp1[temp] = ans[temp];
			}
			if(flag)
				break;
			mp.clear();
			for(it2 = mp1.begin(); it2 != mp1.end(); it2++) {
				int ind = it2 -> first, val = it2 -> second;
				mp[ind] = val;
			}
			mp1.clear();
		}
		if(flag) {
			printf("-1\n");
			continue;
		}
		int check[n + 1], s = 0;
		for(int i = 0; i <= n; i++)
			check[i] = 0;
		for(int i = 1; i <= n; i++) {
			s += i - check[ans[i]];
			check[ans[i]] = i;
		}
		if(s != m) {
			printf("-1\n");
			continue;
		}
		for(int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}