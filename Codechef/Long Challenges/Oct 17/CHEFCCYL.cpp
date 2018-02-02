#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, q;
		scanf("%d%d", &n, &q);
		vector<int> cycles[n];
		int tot[n];
		for(int i = 0; i < n; i++) {
			int l;
			scanf("%d", &l);
			tot[i] = 0;
			while(l--) {
				int w;
				scanf("%d", &w);
				cycles[i].push_back(w);
				tot[i] += w;
 			}
		}
		int lef[n], rig[n], weight[n];
		for(int i = 0; i < n; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			weight[i] = w;
			rig[i] = u - 1;
			int ind;
			if(i == n - 1)
				ind = 0;
			else
				ind = i + 1;
			lef[ind] = v - 1;
		}
		vector <int> lefd[n], rigd[n];
		for(int i = 0; i < n; i++) {
			int v1 = lef[i], v2 = rig[i];
			int len = cycles[i].size();
			int dist = 0;
			int times = len;
			while(times--)
				lefd[i].push_back(0), rigd[i].push_back(0);
			for(int j = 0; j < len; j++) {
				int ind = (j + v1) % len;
				lefd[i][ind] = min(dist, tot[i] - dist);
				dist += cycles[i][ind];
 			}
 			dist = 0;
			for(int j = 0; j < len; j++) {
				int ind = (j + v2) % len;
				rigd[i][ind] = min(dist, tot[i] - dist);
				dist += cycles[i][ind];
 			}
		}
		int pre[n];
		int sum = 0;
		for(int i = 0; i < n; i++) {
			sum += weight[i];
			pre[i] = sum;
		}
		int all = pre[n - 1], lastd = 0;
		int cdist[n], cpre[n];
		for(int i = 0; i < n; i++) {
			int v1 = lef[i];
			int cd = rigd[i][v1];
			cdist[i] = cd;
			lastd += cd;
			cpre[i] = lastd;
		}
		while(q--) {
			int c1, c2, u, v;
			scanf("%d%d%d%d", &u, &c1, &v, &c2);
			u--, v--;
			c1--, c2--;
			if(c1 > c2)
				swap(&c1, &c2), swap(&u, &v);
			int dist1 = lefd[c1][u];
			int dist2 = rigd[c1][u];
			int dist3 = rigd[c2][v];
			int dist4 = lefd[c2][v];
			int l1 = pre[c2 - 1];
			if(c1)
				l1 -= pre[c1 - 1];
			int l2 = all - l1;
			int ed1 = cpre[c2 - 1] - cpre[c1];
			int ed2 = lastd - ed1 - cdist[c1] - cdist[c2];
			//cout << ed1 << " " << ed2 << endl;
			int d1 = dist1 + l2 + dist3 + ed2;
			int d2 = dist2 + l1 + dist4 + ed1;
			//cout << dist1 << " " << l2 << " " << dist3 << endl;
			//cout << dist2 << " " << l1 << " " << dist4 << endl;
			printf("%d\n", min(d1, d2));
		}
	}
	return 0;
}