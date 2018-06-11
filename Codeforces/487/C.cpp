#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int n = 50, m = 50;
	cout << n << " " << m << endl;
	char ans[n][m];
	a--, b--;
	for(int i = 0; i < 25; i++)
		for(int j = 0; j < m; j++)
			ans[i][j] = 'A';
	for(int i = 25; i < 50; i++)
		for(int j = 0; j < m; j++)
			ans[i][j] = 'B';
	int ind1 = 0, ind2 = 0;
	int tot1 = b + c;
	while(tot1--) {
		if(b) {
			ans[ind1][ind2] = 'B';
			b--;
		}
		else {
			ans[ind1][ind2] = 'C';
			c--;
		}
		ind2 += 2;
		if(ind2 >= 50)
			ind2 = 0, ind1 += 2;
	}

	ind1 = 26, ind2 = 0;
	tot1 = a + d;
	while(tot1--) {
		if(a) {
			ans[ind1][ind2] = 'A';
			a--;
		}
		else {
			ans[ind1][ind2] = 'D';
			d--;
		}
		ind2 += 2;
		if(ind2 >= 50)
			ind2 = 0, ind1 += 2;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cout << ans[i][j];
		cout << endl;
	}
	return 0;
}