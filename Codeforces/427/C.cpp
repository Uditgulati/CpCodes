#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e2 + 2;
const ll modu = 1e9 + 7;
int arr[siz][siz][12];
int pre[siz][siz][12];
int main() {
	int n, q, c;
	scanf("%d%d%d", &n, &q, &c);
	for(int i = 0; i < siz; i++)
		for(int j = 0; j < siz; j++)
			for(int k = 0; k < 12; k++)
				arr[i][j][k] = 0, pre[i][j][k] = 0;
	for(int i = 0; i < n; i++) {
		int x, y, s;
		scanf("%d%d%d", &x, &y, &s);
		arr[x][y][s]++;
	}
	for(int i = 0; i < siz; i++) {
		for(int j = 0; j < siz; j++) {
			for(int k = 0; k < 12; k++) {
				pre[i][j][k] = arr[i][j][k];
				if(i)
					pre[i][j][k] += pre[i - 1][j][k];
			}
		}
	}
	for(int i = 0; i < siz; i++) {
		for(int j = 0; j < siz; j++) {
			for(int k = 0; k < 12; k++) {
				if(j)
					pre[i][j][k] += pre[i][j - 1][k];
			}
		}
	}
	while(q--) {
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
		for(int i = 0; i <= c; i++) {
			int curr = pre[x1 - 1][y2][i];
			int num = (i + t) % (c + 1);
			val1 += (num * curr);
		}
		for(int i = 0; i <= c; i++) {
			int curr = pre[x2][y1 - 1][i];
			int num = (i + t) % (c + 1);
			val2 += (num * curr);
		}
		for(int i = 0; i <= c; i++) {
			int curr = pre[x2][y2][i];
			int num = (i + t) % (c + 1);
			val3 += (num * curr);
		}
		for(int i = 0; i <= c; i++) {
			int curr = pre[x1 - 1][y1 - 1][i];
			int num = (i + t) % (c + 1);
			val4 += (num * curr);
		}
		int ans = val3 - val1 - val2 + val4;
		//cout << val1 << val2 << val3 << val4 << endl; 
		printf("%d\n", ans);
	}
	return 0;
}