#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 2;
const ll mo = 1e9 + 7;
vector < pair<int, int > > vec[siz];
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		ll ans = 0;
		for(int i = 0; i < siz; i++)
			vec[i].clear();
		for(int i = 0; i < n; i++) {
			int d, t, s;
			scanf("%d%d%d", &d, &t, &s);
			vec[d].push_back(make_pair(t, s));
		}
		map <int, int> mp;
		for(int i = 1; i <= m; i++) {
			int day = i;
			int len = vec[day].size();
			for(int j = 0; j < len; j++) {
				int time = vec[day][j].first;
				int sad = vec[day][j].second;
				//cout << sad << " " << time << endl;
				if(mp.count(sad))
					mp[sad] += time;
				else
					mp[sad] = time;
			}
			if(mp.empty())
				continue;
			map<int, int>::iterator it = mp.end();
			it--;
			int curr = it -> first, freq = it -> second;
			//cout << curr << " " << freq << endl;
			if(freq > 1)
				mp[curr]--;
			else
				mp.erase(curr);
		}
		for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
			ll a = it -> first,b =  it -> second;
			ans += a * b;
		}
		printf("%lld\n", ans);
	}
	return 0;
}