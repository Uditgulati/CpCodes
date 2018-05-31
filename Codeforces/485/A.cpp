#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	string s[n];

	map <string, string> mp;
	set <string> check;

	mp["purple"] = "Power";
	mp["green"] = "Time";
	mp["blue"] = "Space";
	mp["orange"] = "Soul";
	mp["red"] = "Reality";
	mp["yellow"] = "Mind";
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		check.insert(s[i]);
	}

	vector <string> ans;

	map<string, string>::iterator it;
	for(it = mp.begin(); it != mp.end(); it++) {
		string s1 = it -> first;
		if(!check.count(s1))
			ans.push_back(mp[s1]);
	}

	cout << ans.size() << endl;

	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}