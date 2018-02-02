#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e3 + 2;
const ll modu = 1e9 + 7;
int qual[siz][siz];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		memset(qual, 0, sizeof qual);
		scanf("%d%d", &n, &m);
		int arr[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		int off[m], maxs[m];
		for(int i = 0; i < m; i++)
			scanf("%d%d", &off[i], &maxs[i]);
		for(int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for(int j = 0; j < m; j++)
				qual[i][j] = s[j] - 48;
		}
		int count1 = 0, count2 = 0;
		int num[m];
		memset(num, 0, sizeof num);
		ll tot = 0;
		for(int i = 0; i < n; i++) {
			int maxi = 0, ind;
			for(int j = 0; j < m; j++) {
				if(num[j] < maxs[j] && off[j] >= arr[i] && off[j] > maxi && qual[i][j])
					maxi = off[j], ind = j;
			}
			if(maxi) {
				tot += (ll)maxi;
				num[ind]++;
				count1++;
			}
		}
		for(int i = 0; i < m; i++)
			if(!num[i])
				count2++;
		printf("%d %lld %d\n", count1, tot, count2);
	}
	return 0;
}