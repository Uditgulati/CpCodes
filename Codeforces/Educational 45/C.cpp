#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;


int main() {
	int n;
	scanf("%d", &n);
	string s[n];
	for(int i = 0; i < n; i++)
		cin >> s[i];
	int valid[n], valid1[n];
	map<int, vector<int> > mp;
	for(int i = 0; i < n; i++) {
		string curr = s[i];
		int len = curr.size();
		int value = inf;
		int count1 = 0;
		for(int j = 0; j < len; j++) {
			if(curr[j] == '(') {
				count1++;
			}
			else if(curr[j] == ')') {
				count1--;
			}
			value = min(value, count1);
		}
		vector <int> temp;
		valid[i] = value;
		valid1[i] = count1;
		if(!mp.count(count1))
			mp[count1] = temp;
		mp[count1].push_back(valid[i]);
	}
	map<int, vector<int> >::iterator it;
	for(it = mp.begin(); it != mp.end(); it++)
		sort((it->second).begin(), (it->second).end());
	ll ans = 0;	
	for(int i = 0; i < n; i++) {
		int mini = valid[i];
		int value = valid1[i];
		int val1 = -value;
		if(mini < 0)
			continue;
		if(!mp.count(val1))
			continue;
		int num = mp[val1].size();
		int tot = lower_bound(mp[val1].begin(), mp[val1].end(), val1) - mp[val1].begin();
		ans += (ll)(num - tot);
		//cout << num << " " << tot << endl;
	}
	cout << ans << endl;
	return 0;
}