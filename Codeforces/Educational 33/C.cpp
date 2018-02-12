#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;
vector <int> conn[siz];
int group[siz], arr[siz];
int visited[siz];
int ans;

void dfs(int source, int pos) {
	int len = conn[source].size();
	visited[source] = 1;
	group[source] = pos;
	ans = min(ans, arr[source]);
	for(int i = 0; i < len; i++) {
		int temp = conn[source][i];
		if(!visited[temp]) {
			dfs(temp, pos);
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i <= n; i++)
		group[i] = -1;
	memset(visited, 0, sizeof visited);
	for(int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	while(m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		conn[u].push_back(v);
		conn[v].push_back(u);
	}
	int pos = 1;
	ll ans1 = 0;
	for(int i = 1; i <= n; i++) {
		ans = inf;
		int node = i;
		if(!visited[node]) {
			dfs(node, pos++);
			ans1 += (ll)ans;
		}
	}
	cout << ans1 << endl;
	return 0;
}