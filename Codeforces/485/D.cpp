#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

const int inf = 1e9 + 10;

vector <int> graph[siz];

priority_queue<int, std::vector<int>, std::greater<int> > ans[siz];

vector <int> sources[101];

void inline dijkstra(int n, int index) {
	queue <int> q1;  // set to process edges
	int dist[n + 1];
	for(int i = 0; i < n + 1; i++)
		dist[i] = inf;

	int visited[n + 1];
	memset(visited, 0, sizeof visited);
	
	int len1 = sources[index].size();
	for(int i = 0; i < len1; i++) {
		q1.push(sources[index][i]);
		dist[sources[index][i]] = 0;
		visited[sources[index][i]] = 1;
	}

	while(!q1.empty()) {
		int curr = q1.front();
		q1.pop();
		int dist1 = dist[curr];
		visited[curr] = 1;
		int len2 = graph[curr].size();
		for(int i = 0; i < len2; i++) {
			int temp = graph[curr][i];
			if(!visited[temp]) {
				q1.push(temp);
				dist[temp] = dist1 + 1;
				visited[temp] = 1;
			}
		}
	}


	for(int i = 1; i <= n; i++) {
		//cout << dist[i] << " ";
		ans[i - 1].push(dist[i]);
	}
	//cout << endl;
}


int main() {
	int n, m, k, s;
	scanf("%d%d%d%d", &n, &m, &k, &s);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i = 0; i < n; i++) {
		int curr = arr[i];
		sources[curr].push_back(i + 1);
	}

	for(int i = 1; i <= k; i++) {
		int value = i;
		dijkstra(n, value);
	}


	for(int i = 0; i < n; i++) {
		int tot = 0;
		int s1 = s;
		while(s1--) {
			tot += ans[i].top();
			ans[i].pop();
		}
		printf("%d ", tot);
	}
	printf("\n");
	return 0;
}