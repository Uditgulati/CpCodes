#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int a;
		scanf("%d", &a);
		int x1 = 0, y1 = 0;
		int a1 = 500, b1 = 500;
		int lim = a / 3;
		lim += 2;
		while(1) {
			printf("%d %d\n", x1+a1, y1+b1);
			fflush(stdout);
			if(x1 == lim)
				x1 = 0;
			else
				x1++;
			int i1, j1;
			scanf("%d%d", &i1, &j1);
			if(!i1 && !j1)
				break;
		}
	}
	return 0;
}