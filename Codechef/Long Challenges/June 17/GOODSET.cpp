#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int a = 500;
		while(n--) {
			printf("%d ", a);
			a--;
		}
		printf("\n");
	}
	return 0;
}