#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m, x, k;
		scanf("%d%d%d%d", &n, &m, &x, &k);
		string s;
		cin >> s;
		int len = s.size();
		int c1 = 0, c2 = 0;
		for(int i = 0; i < len; i++) {
			if(s[i] == 'E')
				c1++;
			else
				c2++;
		}
		int sum = n;
		if(x * m < n) {
			printf("no\n");
			continue;
		}
		for(int i = 0; i < m; i++) {
			if(i % 2) {
				int num = min(x, c1);
				c1 -= num;
				sum -= num;
			}
			else {
				int num = min(x, c2);
				c2 -= num;
				sum -= num;
			}
		}
		if(sum > 0)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}