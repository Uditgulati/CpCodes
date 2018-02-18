#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

vector <int> conn[100];
int marked[100];
int visited[100];
int present[100];

vector <int> temp;

void dfs(int source) {
	int len = conn[source].size();
	temp.push_back(source);
	visited[source] = 1;
	marked[source] = 1;
	for(int i = 0; i < len; i++) {
		int temp = conn[source][i];
		if(!visited[temp])
			dfs(temp);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	string s1, s2;
	cin >> s1 >> s2;
	memset(marked, 0, sizeof marked);
	memset(present, 0, sizeof present);
	vector < pair<string, string> > vec;
	for(int i = 0; i < n; i++) {
		if(s1[i] != s2[i]) {
			int u = s1[i] - 97;
			int v = s2[i] - 97;
			present[u] = 1;
			present[v] = 1;
			conn[u].push_back(v);
			conn[v].push_back(u);
		}
	}
	for(int i = 0; i < 26; i++) {
		temp.clear();
		memset(visited, 0, sizeof visited);
		if(!marked[i] && present[i])
			dfs(i);
		int len1 = temp.size();
		if(!len1)
			continue;
		for(int j = 0; j < len1 - 1; j++) {
			char a = temp[j] + 97, b = temp[j + 1] + 97;
			string x1, x2;
			x1 += a, x2 += b;
			vec.push_back(make_pair(x1, x2));
		}
	}
	int ans = vec.size();
	printf("%d\n", ans);
	for(int i = 0; i < ans; i++)
		cout << vec[i].first << " " << vec[i].second << endl;
	return 0;
}