#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;
const int val = 1e5;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			if(i < 42949)
				printf("%d ", val);
			else
				printf("1 ");
		}
		printf("\n");
	}
	return 0;
}