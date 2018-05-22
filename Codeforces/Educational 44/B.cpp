#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int arr[n][m];
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++) 
			arr[i][j] = s[j] - 48;
	}

	int ans = 0;

	int sum[m];
	for(int i = 0; i < m; i++)
		sum[i] = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			sum[j] += arr[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		int flag = 1;
		for(int j = 0; j < m; j++) {
			int diff = sum[j] - arr[i][j];
			if(diff == 0)
				flag = 0;
		}
		if(flag)
			ans = 1;
	}

	if(ans)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}