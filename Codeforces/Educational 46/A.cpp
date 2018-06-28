#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	string arr1[n], arr2[n];
	map<string, int> mp;
	for(int i = 0; i < n; i++) {
		cin >> arr1[i];
		if(mp.count(arr1[i]))
			mp[arr1[i]]++;
		else
			mp[arr1[i]] = 1;
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr2[i];
		string curr = arr2[i];
		if(mp.count(curr)) {
			mp[curr]--;
			if(mp[curr] == 0)
				mp.erase(curr);
		}
		else
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}