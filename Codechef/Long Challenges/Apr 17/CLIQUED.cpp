#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> ii;
typedef vector<int> vi;
const int siz = 1e5 + 2;
const ll lim = 1e18 + 2;
vector< ii > conn[siz];
ll dist[siz];
int marked[siz];
int n;
void dijkstra(int s)
{
	memset(marked, 0, sizeof(int) * siz);
	for(int i = 0; i < siz; i++)
		dist[i] = lim;
	set<ii > se;
	se.insert(ii(0,s));
	dist[s] = 0;
	marked[s] = 1;
	while(!se.empty())
	{	
		ii p = *se.begin();	
		se.erase(p);
		marked[p.second] = 2;
		for(int i = 0; i < conn[p.second].size(); i++) {
			if(!marked[conn[p.second][i].second]) {
				se.insert(ii(dist[p.second]+conn[p.second][i].first,conn[p.second][i].second));
				marked[conn[p.second][i].second] = 1;
				dist[conn[p.second][i].second] = dist[p.second]+conn[p.second][i].first;
			}
			else if(marked[conn[p.second][i].second]==1 && dist[conn[p.second][i].second] > dist[p.second]+conn[p.second][i].first) {
				se.erase(ii(dist[conn[p.second][i].second],conn[p.second][i].second));
				se.insert(ii(dist[p.second]+conn[p.second][i].first,conn[p.second][i].second));
				dist[conn[p.second][i].second] =  dist[p.second]+conn[p.second][i].first;
			} 
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--) {
		for(int i = 0; i < siz; i++) {
			conn[i].clear();
			//dist[i] = -1;
		}
		int k, x, m, s;
		scanf("%d%d%d%d%d", &n, &k, &x, &m, &s);
		while(m--) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			conn[u].push_back(make_pair(w, v));
			conn[v].push_back(make_pair(w, u));
		}
		if(s <= k) {
			for(int i = 1; i <= k; i++)
				if(i != s) {
					conn[i].push_back(make_pair(x, s));
					conn[s].push_back(make_pair(x, i));
				}
		}
		else {
			dijkstra(s);
			ll mini = dist[1];
			int index = 1;
			for(int i = 2; i <= k; i++)
				if(dist[i] < mini) {
					index = i;
					mini = dist[i];
				}
			for(int i = 1; i <= k; i++)
				if(i != index) {
					conn[i].push_back(make_pair(x, index));
					conn[index].push_back(make_pair(x, i));
				}
		}
		dijkstra(s);
		for(int i =1; i <= n; i++)
			printf("%lld ", dist[i]);
		printf("\n");
	}
	return 0;
}