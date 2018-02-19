#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 10;
const ll modu = 1e9 + 7;
const int LIM = (1 << 6);
const ll MX = 17;

vector < pair<ll, ll> > vec;
ll pre[siz], pre1[siz];

int main() {
	int n;
	scanf("%d", &n);
	ll arr[n];
	memset(pre, 0, sizeof pre);
	for(int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	int q;
	ll lim = pow(2, 17);
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		x %= lim;
		vec.push_back(make_pair(x, y));
	}
	int sq = sqrt(q);
	int num = min(sq, LIM);
	sq = ceil((float) q / num);
	vector <ll> store[num + 1];
	for(int i = 0; i < n; i++)
		store[0].push_back(arr[i]);
	int ind1 = 0, ind2 = sq - 1;
	for(int i = 0; i < num; i++) {
		for(int j = ind1; j <= ind2; j++) {
			if(j >= q)
				break;
			ll x1 = vec[j].first, y1 = vec[j].second;
			pre[x1] -= y1;
		}
		for(int j = 0; j < siz; j++)
			pre1[j] = pre[j];
		for(int j = 0; j < MX; j++) {
			ll lim1 = (1LL << MX);
			for(int mask = 0; mask < lim1; mask++) {
				ll mask1 = mask, j1 = j;
				if(!(mask1 & (1LL << j1)))
					pre1[mask1] += pre1[mask1 ^ (1LL << j1)];
			}
		}
		for(int j = 0; j < n; j++)
			store[i + 1].push_back(pre1[j] + arr[j]);
		ind1 += sq, ind2 += sq;
	}
	int ans[q], ans1[q];
	int marked[n], pos[n];
	for(int i = 0; i < n; i++)
		pos[i] = -1;
	memset(marked, 0, sizeof marked);
	int i1 = 0, i2 = sq - 1;
	for(int i = 1; i < num + 1; i++) {
		
		for(int j = 0; j < n; j++) {
			if(!marked[j] && store[i][j] <= 0) {
				marked[j] = true;
				ll ini = store[i - 1][j];
				int ind = i1;
				for(int k = i1; k <= i2; k++) {
					if(k >= q)
						break;
					ll j1 = j;
					ll mask1 = vec[k].first, y1 = vec[k].second;
					if((mask1 & j1) == j1)
						ini -= y1;
					if(ini <= 0)
						break;
					ind++;
				}
				pos[j] = ind;
				//cout << j << " " << ind << endl;
			}
		}
		i1 += sq, i2 += sq;
	}
	for(int i = 0; i < q; i++)
		ans[i] = n, ans1[i] = 0;
	for(int i = 0; i < n; i++) {
		int p = pos[i];
		if(p == -1)
			continue;
		ans1[p]++;
	}
	int var = 0;
	for(int i = 0; i < q; i++) {
		var += ans1[i];
		printf("%d\n", ans[i] - var);
	}
	return 0;
}