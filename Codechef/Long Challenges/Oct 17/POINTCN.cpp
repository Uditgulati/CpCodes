#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18 + 10;
const int MX = 1010;
int C[MX][MX], H[MX][MX];
int ans[15][MX][MX], ans1[MX][MX];
unsigned long long s[2];

unsigned long long xorshift128plus() {
	unsigned long long x = s[0];
	const unsigned long long y = s[1];
	x ^= x << 23;
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
	return s[0] = y;
}

bool func(pair <int, int> p, pair<int, int> q) {
	return (p.first > q.first);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, Cmax, Hmax;
		scanf("%d%d%d", &n, &Cmax, &Hmax);
		for(int i = 0; i < n; i++) {
			C[i][i] = 0;
			scanf("%llu%llu", &s[0], &s[1]);
			for (int j = i + 1; j < n; j++)
				C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
		}
		for(int i = 0; i < n; i++) {
			scanf("%llu%llu", &s[0], &s[1]);
			for (int j = 0; j < n; j++)
				H[i][j] = xorshift128plus() % (Hmax + 1);
		}
		int flag1 = 0;
		memset(ans1, 0, sizeof ans1);
		int ind1 = -1;
		ll mini1 = inf;
		for(int i = 0; i < n; i++) {
			ll cost = 0;
			for(int j = 0; j < n; j++)
				if(i != j)
					cost += (ll)(C[i][j] + H[j][1]);
			cost += (ll)H[i][n - 1];
			if(cost < mini1)
				mini1 = cost, ind1 = i;
		}
		for(int i = 0; i < n; i++)
			if(i != ind1)
				ans1[i][ind1] = ans1[ind1][i] = 1;
		memset(ans, 0, sizeof ans);
		int deg[n], num = 0, ext[n], p1 = -1;
		vector <ll> least;
		ll l1 = mini1;
		for(int u = 0; u < 10; u++) {
			num = 0;
			ll inc = u + 12;
			ll val1 = 0;
			for(int i = 0; i < n; i++) {
				vector <int> vec1;
				for(int j = 0; j < n; j++)
					if(i != j)
						vec1.push_back(C[i][j]);
				sort(vec1.begin(), vec1.end());
				ll cost = vec1[0], mini = inf, cost1 = vec1[0], cost2 = vec1[0];
				int ind = -1;
				for(int j = 2; j < n; j++) {
					ll hub = H[i][j];
					cost += (ll)vec1[j - 1];
					ll j2 = sqrt(j), j3 = j;
					ll temp = vec1[j - 1] * j2;
					cost1 += temp;
					cost2 = vec1[j -1] * j3;
					ll tot = hub + (inc * cost) / 4;
					if(!u)
						tot = hub + j2 * cost;
					if(u == 1)
						tot = hub + cost1;
					if(u == 9)
						tot = hub + cost2;
					ll j1 = j;
					tot /= j1;
					ll e = vec1[j - 1];
					if(tot < mini)
						mini = tot, ind = j, ext[i] = e;
				}
				deg[i] = ind;
				num += ind;
			}
			int pos = -1, diff = -1;
			if(num % 2) {
				for(int i = 0; i < n; i++) {
					int d = deg[i];
					int curr = H[i][d] + ext[i] - H[i][d - 1];
					if(curr > diff)
						diff = curr, pos = i;
				}
				deg[pos]--;
			}
			int c = 0;
			for(int i = 0; i < n; i++) {
				if(c == num / 2)
					break;
				int node = -1, maxi = -1;
				for(int j = 0; j < n; j++)
					if(deg[j] > maxi && deg[j])
						node = j, maxi = deg[j];
				vector < pair<int, int> > edges;
				for(int j = 0; j < n; j++)
					if(j != node)
						edges.push_back(make_pair(C[node][j], j));
				sort(edges.begin(), edges.end());
				int d = deg[node];
				int j1 = 0, count1 = 0;
				while(1) {
					int node1 = edges[j1++].second;
					if(!deg[node1])
						continue;
					deg[node1]--, count1++, c++;
					ans[u][node][node1] = ans[u][node1][node] = 1;
					if(count1 == d)
						break;
				}
				deg[node] = 0;
			}
			for(int i = 0; i < n; i++) {
				int count2 = 0;
				for(int j = 0; j < n; j++)
					count2 += ans[u][i][j];
				for(int j = i; j < n; j++)
					if(ans[u][i][j])
						val1 += (ll)C[i][j];
				val1 += (ll)H[i][count2];
			}
			least.push_back(val1);
			//cout << val1 << endl;
			if(val1 < l1)
				l1 = val1, p1 = u, flag1 = 1;
		}
		if(!flag1) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++)
					printf("%d", ans1[i][j]);
				printf("\n");
			}
			continue;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				printf("%d", ans[p1][i][j]);
			printf("\n");
		}
	}
	return 0;
}