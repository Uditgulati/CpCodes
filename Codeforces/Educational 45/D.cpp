#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int flag = 0;
	int ans[n][n];
	memset(ans, 0, sizeof ans);
	if(min(a, b) !=  1) {
		printf("NO\n");
		return 0;
	}
	if(n == 2 && a == 1 && b == 1) {
		printf("NO\n");
		return 0;
	}
	if(n == 3 && a == 1 && b == 1) {
		printf("NO\n");
		return 0;
	}
	if(a == 1 && b == 1) {
		printf("YES\n");
		for(int i = 0; i < n - 1; i++)
			ans[i][i + 1] = ans[i + 1][i] = 1;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				printf("%d", ans[i][j]);
			printf("\n");
		}
		return 0;
	}
	printf("YES\n");
	int num = max(a, b);
	int ext = n - num;
	for(int i = 1; i <= ext; i++)
		ans[i][0] = ans[0][i] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a == 1)
				ans[i][j] = !ans[i][j];
			if(i == j)
				ans[i][j] = 0;
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}