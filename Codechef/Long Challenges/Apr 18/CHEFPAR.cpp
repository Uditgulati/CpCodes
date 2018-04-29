#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
int n, m, k;

ll arr1[siz], arr2[siz];

int random(int a, int b) {
	int diff = b - a + 1;
	int val = rand() % diff + a;
	return val;
}

ll eval(ll val1) {
	ll score = 0LL;
	ll temp[n], modarr[m];
	for(int i = 0; i < m; i++)
		modarr[i] = 1LL;
	for(int i = 0; i < n; i++) {
		temp[i] = arr1[i] + val1;
		for(int j = 0; j < m; j++) {
			ll prime = arr2[j];
			modarr[j] = (modarr[j] * temp[i]) % prime;
		}
	}
	for(int i = 0; i < m; i++)
		score += modarr[i];
	return score;
}
 
int main() {
	srand(time(NULL));
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++)
		scanf("%lld", &arr1[i]);
	for(int i = 0; i < m; i++)
		scanf("%lld", &arr2[i]);
	int times = 100;
	vector < pair<ll, ll> > pre, pre1;
	ll ans[n];
	ll maxi = -1LL;
	int gap = max(10, k / 100);
	for(int x = 0; x <= k; x += gap) {
		ll val1 = x;
		ll score = eval(val1);
		pre.push_back(make_pair(score, val1));
		//cout << score << endl;
	}
	int len1 = pre.size();
	sort(pre.begin(), pre.end());
	int num = 4;
	ll tot = -1LL, k1 = -1LL;
	while(num-- && pre.size() > 0) {
		pll curr = pre.back();
		pre.pop_back();
		ll maxi1 = curr.first;
		if(maxi1 > tot)
			tot = maxi1, k1 = curr.second;
		ll val2 = curr.second + 2LL;
		int num2 = 50;
		while(num2-- && val2 <= k) {
			ll score1 = eval(val2);
			if(score1 > tot)
				tot = score1, k1 = val2;
			val2 += 2LL;
		}
		ll val3 = curr.second - 2LL;
		num2 = 50;
		while(num2-- && val3 > 0) {
			ll score1 = eval(val3);
			if(score1 > tot)
				tot = score1, k1 = val3;
			val3 -= 2LL;
		}
	}
	//cout << maxi << endl;
	for(int i = 0; i < n; i++)
		printf("%lld ", arr1[i] + k1);
	printf("\n");
	return 0;
}