#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	if(m < n - 1) {
		printf("Impossible\n");
		return 0;
	}
	ll n1 = n, m1 = m;
	ll tot = (n1 * (n1 - 1LL)) / 2LL;
	int curr = 1;
	vector <pii> ans;
	int count1 = 0;
	while(curr <= n) {
		for(int i = curr + 1; i <= n; i++)
			if(__gcd(curr, i) == 1) {
				ans.push_back(make_pair(curr, i));
				count1++;
				if(count1 == m)
					break;
			}
		if(count1 == m)
			break;
		curr++;
	}
	//cout << ans.size() << endl;
	if(ans.size() >= m) {
		printf("Possible\n");
		for(int i = 0; i < m; i++)
			cout << ans[i].first << " " << ans[i].second << endl;
	}
	else 
		printf("Impossible\n");
	return 0;
}