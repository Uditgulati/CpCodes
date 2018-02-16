#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
int arr[siz], pre[siz];

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int pxor = 0;
	for(int i = 0; i < n; i++) {
		pxor ^= arr[i];
		pre[i] = pxor;
	}
	int sq = sqrt(n);
	int num = ceil((float) n / sq);
	map <int, int> store[num + 1];
	int mask[num + 1];
	vector <int> vec[num + 1];
	memset(mask, 0, sizeof mask);
	int ind1 = 0, ind2 = sq - 1;
	for(int i = 0; i < num; i++) {
		for(int j = ind1; j <= ind2; j++) {
			if(j >= n)
				break;
			int val = pre[j];
			vec[i].push_back(val);
			if(store[i].count(val))
				store[i][val]++;
			else 
				store[i][val] = 1;
		}
		ind1 += sq, ind2 += sq;
	}
	while(q--) {
		int type;
		scanf("%d", &type);
		if(type == 1) {
			int i, x;
			scanf("%d%d", &i, &x);
			int prev = arr[i - 1];
			int curr = x ^ prev;
			arr[i - 1] = x;
			int pos = (i - 1) / sq;
			for(int j = pos + 1; j < num; j++)
				mask[j] ^= curr;
			vector <int> vec1;
			int len = vec[pos].size(), r = (i - 1) % sq;
			for(int j = 0; j < len; j++) {
				int temp = vec[pos][j] ^ mask[pos];
				if(j >= r)
					temp ^= curr;
				vec1.push_back(temp);
			}
			store[pos].clear();
			for(int j = 0; j < len; j++) {
				vec[pos][j] = vec1[j];
				int val = vec1[j];
				if(store[pos].count(val))
					store[pos][val]++;
				else 
					store[pos][val] = 1;
			}
			mask[pos] = 0;
		}
		else {
			int i, k;
			scanf("%d%d", &i, &k);
			int pos = (i - 1) / sq, ans = 0, r = (i - 1) % sq;
			for(int j = 0; j < pos; j++) {
				int temp = k ^ mask[j];
				int freq = 0;
				if(store[j].count(temp))
					freq = store[j][temp];
				ans += freq;
			}
			for(int j = 0; j <= r; j++) {
				int curr = vec[pos][j] ^ mask[pos];
				if(curr == k)
					ans++;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}