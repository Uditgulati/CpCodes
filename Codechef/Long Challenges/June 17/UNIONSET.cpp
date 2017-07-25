#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		vector <int> vec[n];
		for(int i = 0; i < n; i++) {
			int len;
			scanf("%d", &len);
			while(len--) {
				int a;
				scanf("%d", &a);
				vec[i].push_back(a);
			}
		}
		int arr[n][k + 1], count = 0;
		for(int i = 0; i < n; i++)
			memset(&arr[i][0], 0, sizeof(int) * (k + 1));
		for(int i = 0; i < n; i++) {
			int len = vec[i].size();
			for(int j = 0; j < len; j++)
				arr[i][vec[i][j]] = 1;
			for(int i1 = 0; i1 < i; i1++) {
				int j;
				for(j = 1; j <= k; j++)
					if(!arr[i][j] && !arr[i1][j])
						break;
				if(j == k + 1)
					count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}