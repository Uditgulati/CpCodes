#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;

int main() {
	int n, h;
	scanf("%d%d", &n, &h);
	int p1[h], r1[h], w1[h], c1[h];
	for(int i = 0; i < h; i++) {
		scanf("%d%d%d%d", &p1[i], &r1[i], &w1[i], &c1[i]);
	}
	int pen;
	scanf("%d", &pen);
	int low = 0, mini = p1[0];
	for(int i = 1; i < h; i++) {
		if(p1[i] < mini)
			mini = p1[i], low = i;
	}
	printf("p b %d\n", low);
	fflush(stdout);
	while(n--) {
		printf("g\n");
		fflush(stdout);
		int a;
		scanf("%d", &a);
		if(a == 0) {
			int c, q;
			scanf("%d%d", &c, &q);
			printf("p s -1 -1\n");
		}
		else if(a == 1) {
			int c, p;
			scanf("%d%d", &c, &p);
			printf("p i -1 -1\n");
		}
		else {
			int h;
			scanf("%d", &h);
		}
		fflush(stdout);
	}
	printf("end\n");
	return 0;
}