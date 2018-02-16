#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int arr[n][m], arr1[n][m], arr2[n][m];
		int c1 = 0, c2 = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				if((i + j) % 2)
					arr1[i][j] = 1, arr2[i][j] = 0;
				else
					arr1[i][j] = 0, arr2[i][j] = 1;
			}
		for(int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for(int j = 0; j < m; j++) {
				if(s[j] == 'R')
					arr[i][j] = 1;
				else
					arr[i][j] = 0;
				if(arr[i][j] != arr1[i][j]) {
					if(arr[i][j] == 1)
						c1 += 5;
					else
						c1 += 3;
				}
				if(arr[i][j] != arr2[i][j]) {
					if(arr[i][j] == 1)
						c2 += 5;
					else
						c2 += 3;
				}
			}
		}
		printf("%d\n", min(c1, c2));
	}
	return 0;
}