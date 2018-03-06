#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
const int inf = 1e7 + 10;

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int arr[n][m];
	vector <int> vec[n];
	int tot = 0;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++) {
			if(s[j] == '1')
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
			if(arr[i][j])
				vec[i].push_back(j), tot++;
		}
	}
	if(k >= tot) {
		printf("0\n");
		return 0;
	}
	vector <int> pre[n];
	for(int i = 0; i < n; i++) {
		int len = vec[i].size();
		if(len == 0) {
			pre[i].push_back(0);
			continue;
		}
		int arr1[len];
		for(int i1 = 0; i1 < len; i1++)
			arr1[i1] = inf;
		arr1[0] = vec[i][len - 1] - vec[i][0] + 1;
		for(int i1 = 0; i1 < len; i1++) {
			for(int j1 = i1; j1 < len; j1++) {
				int diff = vec[i][j1] - vec[i][i1] + 1;
				int rem = len - (j1 - i1 + 1);
				arr1[rem] = min(arr1[rem], diff);
			}
		}
		for(int i1 = 0; i1 < len; i1++)
			pre[i].push_back(arr1[i1]);
		pre[i].push_back(0);
	}
	int calc[n][k + 1];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= k; j++) {
			calc[i][j] = inf;
		}
	}
	int len1 = pre[0].size();
	for(int i = 0; i < min(k + 1, len1); i++) {
		calc[0][i] = pre[0][i];
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= k; j++) {
			for(int i1 = 0; i1 <= j; i1++) {
				int prev = calc[i - 1][j - i1];
				int len2 = pre[i].size();
				if(i1 >= len2)
					break;
				int curr = pre[i][i1];
				calc[i][j] = min(calc[i][j], curr + prev);
			}
		}
	}
	int ans = inf;
	for(int i = 0; i <= k; i++) {
		ans = min(ans, calc[n - 1][i]);
	}
	printf("%d\n", ans);
	return 0;
}