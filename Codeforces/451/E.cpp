#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;


int main() {
	int n;
	vector <ll> pre;
	for(int i = 0; i < siz; i++) {
		ll i1 = i;
		ll val = i1 * i1;
		pre.push_back(val);
	}
	scanf("%d", &n);
	ll arr[n];
	for(int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	ll arr1[n], arr2[n];	//arr1 - for sq, arr2 - for not sq
	for(int i = 0; i < n; i++) {
		ll val = arr[i];
		ll sq = sqrt(val);
		if(sq * sq == val) {
			arr1[i] = 0;
			if(val == 0)
				arr2[i] = 2;
			else
				arr2[i] = 1;
		}
		else {
			arr2[i] = 0;
			int ind = upper_bound(pre.begin(), pre.end(), val) - pre.begin();
			ll val1 = pre[ind];
			ll val2 = pre[ind - 1];
			ll diff = min(abs(val - val1), abs(val - val2));
			arr1[i] = diff;
		}
	}
	vector < pair<ll, int> > ini, rem, ini1, rem1;
	for(int i = 0; i < n / 2; i++)
		ini.push_back(make_pair(arr1[i] - arr2[i], i));
	for(int i = n / 2; i < n; i++)
		rem.push_back(make_pair(arr2[i] - arr1[i], i));
	sort(ini.begin(), ini.end());
	sort(rem.begin(), rem.end());
	int len = n / 2;
	while(ini.size() > 0 && rem.size() > 0) {
		pair <ll, int> p1, p2;
		p1 = ini.back(), p2 = rem.back();
		ll sum = p1.first + p2.first;
		if(sum > 0) {
			ini1.push_back(p2), rem1.push_back(p1);
			ini.pop_back(), rem.pop_back();
		}
		else {
			break;
		}
	}
	int len1 = ini.size(), len2 = ini1.size();
	ll ans = 0;
	for(int i = 0; i < len1; i++) {
		int ind1 = ini[i].second;
		int ind2 = rem[i].second;
		ans += arr1[ind1] + arr2[ind2];
	}
	for(int i = 0; i < len2; i++) {
		int ind1 = ini1[i].second;
		int ind2 = rem1[i].second;
		ans += arr1[ind1] + arr2[ind2];
	}
	cout << ans << endl;
	return 0;
}