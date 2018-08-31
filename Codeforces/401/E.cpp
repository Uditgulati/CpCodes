#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

vector <ll> vec1, vec2, vec3;

int bs(int n, ll x) {
	int l = 0;
	int h = n; // Not n - 1
	while(l < h) {
		int mid = (l + h) / 2;
		if(x < vec2[mid])
			l = mid + 1;
		else
			h = mid;
	}
	return l;
}

int main() {
	int n;
	scanf("%d", &n);
	map <ll, ll> mp1, mp2;
	for(int i = 0; i < n; i++) {
		ll a, b, h;
		scanf("%lld%lld%lld", &a, &b, &h);
		if(mp1.count(b))
			mp1[b] = min(mp1[b], a);
		else
			mp1[b] = a;
		if(mp2.count(b))
			mp2[b] += h;
		else
			mp2[b] = h;
	}
	n = mp1.size();
	vec1.resize(n), vec2.resize(n), vec3.resize(n);
	int ind = n - 1;
	for(auto it = mp1.begin(); it != mp1.end(); it++) {
		vec2[ind] = it -> first;
		vec1[ind] = it -> second;
		ind--;
	}
	ind = n - 1;
	for(auto it = mp2.begin(); it != mp2.end(); it++) {
		vec3[ind] = it -> second;
		ind--;
	}

	multiset <ll> check;
	vector <ll> pre[2 * n];
	ll ans = -1;
	for(int i = 0; i < n; i++) {
		int len1 = pre[i].size();
		for(int j = 0; j < len1; j++) {
			ll temp = pre[i][j];
			if(temp >= 0)
				check.insert(temp);
			else
				check.erase(check.find(-temp));
		}
		ll a1 = vec1[i], b1 = vec2[i], h1 = vec3[i];
		//cout << vec1[i] << " " << vec2[i] << " " << vec3[i] << endl;
		int ind1 = i + 1;
		int ind2 = bs(n, a1);
		ll curr = h1;
		//cout << "ini: " << curr << endl;
		if(!check.empty()) {
			ll temp = *(check.rbegin());
			curr += temp;
		}
		ans = max(ans, curr);
		//cout << curr << endl;
		if(ind2 - ind1 < 1)
			continue;
		pre[ind1].push_back(curr);
		pre[ind2].push_back(-curr);
	}
	printf("%lld\n", ans);
	return 0;
}