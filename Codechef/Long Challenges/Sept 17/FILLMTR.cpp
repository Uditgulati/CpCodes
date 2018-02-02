#include <bits/stdc++.h>
using namespace std;
const int siz = 1e5 + 4;
vector <int> conn[siz], conn1[siz];
int num[siz], coloured[siz], flag = 1;

bool bfs(int source) {
	queue <int> que;
	coloured[source] = 0;
	que.push(source);
	while(!que.empty()) {
		int temp = que.front();
		que.pop();
		int len = conn[temp].size();
		for(int i = 0; i < len; i++) {
			int v = conn[temp][i];
			if(coloured[v] == -1) {
				coloured[v] = 1 - coloured[temp];
				que.push(v);
			}
			else if(coloured[v] == coloured[temp])
				return false;
		}
	}
	return true;
}
void dfs1(int source, int ind) {
	int len = conn1[source].size();
	num[source] = ind;
	for(int i = 0; i < len; i++) {
		int temp = conn1[source][i];
		if(!num[temp])
			dfs1(temp, ind);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, q;
		scanf("%d%d", &n, &q);
		for(int i = 0; i <= n + 2; i++)
			conn[i].clear(), conn1[i].clear();
		memset(num, 0, sizeof num);
		int que1[q], que2[q];
		int i1 = 0;
		int ind1, ind2, val;
		for(int i = 0; i < q; i++) {
			scanf("%d%d%d", &ind1, &ind2, &val);
			if(!val) {
				conn1[ind1].push_back(ind2);
				conn1[ind2].push_back(ind1);
			}
			else {
				que1[i1] = ind1, que2[i1] = ind2;
				i1++;
			}
		}
		int x = 1;
		for(int i = 1; i <= n; i++)
			if(!num[i]) {
				dfs1(i, x);
				x++;
			}
		for(int i = 0; i <= n; i++)
			coloured[i] = -1;
		for(int i = 0; i < i1; i++) {
			int ind1 = que1[i], ind2 = que2[i];
			int num1 = num[ind1], num2 = num[ind2];
			conn[num1].push_back(num2);
			conn[num2].push_back(num1);
		}
		for(int i = 1; i <= x; i++) {
			if(coloured[i] == -1)
				flag = bfs(i);
			if(!flag)
				break;
		}
		(flag) ? printf("yes\n") : printf("no\n");
	}
	return 0;
}