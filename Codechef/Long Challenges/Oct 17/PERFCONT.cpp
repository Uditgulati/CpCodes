#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, p;
		scanf("%d%d", &n, &p);
		int c1 = 0, c2 = 0;
		int lim1 = p / 2, lim2 = p / 10;
		for(int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if(x >= lim1)
				c1++;
			if(x <= lim2)
				c2++;
		}
		if(c1 == 1 && c2 == 2)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}