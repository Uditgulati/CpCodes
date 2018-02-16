#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int siz = 1e5 + 10;
const int siz1 = 1e3 + 10;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;
const double inf1 = 1e9 + 10;
int n, g, b, maxd;
int allt = 0;
int arr[siz1], k1[siz1], l1[siz1];
int marked[siz1], visited[siz1];
vector <pii> conn[siz1];
vector <int> conn1[siz1];
vector <int> vec1[siz1], vec2[siz1];	//vec1 for gifts req by subtree i
										//vec2 for gifts at node i.

bool func(int p, int q) {
	return (p > q);
}

void transfer(int source, int dest, vector <int> vec) {
	int len1 = vec.size();
	int count1 = len1;
	int flag = 0, times = 0;
	while(count1) {
		vector <int> temp;
		if(flag)
			printf("1 %d\n", source);
		int sum = 0;
		sort(vec.begin(), vec.end());
		while(sum <= b && count1) {
			int curr = vec.back();
			int cost = arr[curr - 1];
			if(sum + cost > b)
				break;
			vec.pop_back();
			count1--;
			sum += cost;
			temp.push_back(curr);
			printf("2 %d\n", curr);
		}
		sort(vec.begin(), vec.end(), func);
		while(sum <= b && count1) {
			int curr = vec.back();
			int cost = arr[curr - 1];
			if(sum + cost > b)
				break;
			vec.pop_back();
			count1--;
			sum += cost;
			temp.push_back(curr);
			printf("2 %d\n", curr);
		}
		printf("1 %d\n", dest);
		int len2 = temp.size();
		if(allt == n + 1 && !count1 && dest == 0)
			break;
		for(int i = 0; i < len2; i++)
			printf("3 %d\n", temp[i]);
		flag = 1;
		times++;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int x, y;
		scanf("%d%d%d%d%d", &n, &g, &b, &x, &y);
		for(int i = 0; i < siz1; i++) {
			conn[i].clear(), conn1[i].clear();
			vec1[i].clear(), vec2[i].clear();
		}
		for(int i = 0; i < g; i++)
			scanf("%d", &arr[i]);
		int x1[n], y1[n];
		for(int i = 0; i < n; i++)
			scanf("%d%d%d%d", &x1[i], &y1[i], &k1[i], &l1[i]);
		for(int i = 0; i < n; i++) {
			int dist1 = pow(x1[i] - x, 2) + pow(y - y1[i], 2);
			dist1 = sqrt(dist1);
			conn[i + 1].push_back(make_pair(dist1, 0));
			conn[0].push_back(make_pair(dist1, i + 1));
			for(int j = 0; j < n; j++) {
				int dist = pow(x1[i] - x1[j], 2) + pow(y1[i] - y1[j], 2);
				dist = sqrt(dist);
				conn[i + 1].push_back(make_pair(dist, j + 1));
				conn[j + 1].push_back(make_pair(dist, i + 1));
			}
		}
		vector <pii> pre1[10][10];
		vector <int> pre2[10][10];
		for(int i = 0; i < n; i++) {
			int x2 = x1[i] / 1000, y2 = y1[i] / 1000;
			if(x2 == 10)
				x2--;
			if(y2 == 10)
				y2--;
			pre1[x2][y2].push_back(make_pair(x1[i], y1[i]));
			pre2[x2][y2].push_back(i);
		}
		allt = 1;
		memset(marked, 0, sizeof marked);
		for(int i1 = 0; i1 < 10; i1++) {
			for(int j1 = 0; j1 < 10; j1++) {
				vector <int> req, ret, req1, ret1;
				int dist2 = inf, mini = -1;
				int len = pre1[i1][j1].size();
				for(int i = 0; i < len; i++) {
					int ind = pre2[i1][j1][i];
					int x3 = pre1[i1][j1][i].first;
					int y3 = pre1[i1][j1][i].second;
					req.push_back(l1[ind]);
					ret.push_back(k1[ind]);
					int tdist = pow(x3 - x, 2) + pow(y3 - y, 2);
					if(tdist < dist2)
						dist2 = tdist, mini = ind;
				}
				int len2 = req.size();
				int len3 = ret.size();
				multiset <int> s1, s2;
				for(int i = 0; i < len3; i++)
					s1.insert(ret[i]);
				for(int i = 0; i < len2; i++) {
					if(s1.count(req[i]))
						s1.erase(s1.find(req[i]));
					else
						req1.push_back(req[i]);
				}
				multiset <int>::iterator it;
				for(it = s1.begin(); it != s1.end(); it++)
					ret1.push_back(*it);
				int len4 = req1.size();
				for(int i = 0; i < len4; i++)
					s2.insert(req1[i]);
				transfer(0, mini + 1, req1);
				for(int i = 0; i < len; i++) {
					int ind = pre2[i1][j1][i];
					int x3 = pre1[i1][j1][i].first;
					int y3 = pre1[i1][j1][i].second;
					if(ind == mini)
						continue;
					vector <int> v1, v2;
					v1.push_back(l1[ind]);
					v2.push_back(k1[ind]);
					if(s2.count(l1[ind])) {
						marked[ind] = 1;
						transfer(mini + 1, ind + 1, v1), s2.erase(s2.find(l1[ind]));
					}
					else
						printf("1 %d\n", ind + 1);
					allt++;
					transfer(ind + 1, mini + 1, v2), s2.insert(k1[ind]);
				}
				for(int i = 0; i < len; i++) {
					int ind = pre2[i1][j1][i];
					int x3 = pre1[i1][j1][i].first;
					int y3 = pre1[i1][j1][i].second;
					if(ind == mini)
						continue;
					vector <int> v1, v2;
					v1.push_back(l1[ind]);
					v2.push_back(k1[ind]);
					if(!marked[ind]) {
						transfer(mini + 1, ind + 1, v1);
						printf("1 %d\n", mini + 1);
					}
				}
				allt++;
				transfer(mini + 1, 0, ret1);
			}
		}
		printf("0\n");
	}
	return 0;
}