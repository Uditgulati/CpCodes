#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		string s;
		cin >> s;
		int len = s.size();
		int n, c1 = 0, c2 = 0;
		scanf("%d", &n);
		ll ans = 0;
		int arr[len];
		string s1;
		int lim = min(n, 1000);
		for(int i = 0; i < lim; i++)
			s1 += s;
		int len1 = s1.size();
		ll temp = 0;
		for(int i = 0; i < len; i++) {
			if(s[i] == 'a')
				c1++;
			else
				c2++;
			if(c1 - c2 > 0)
				temp++;
		}
		int pre1 = 0, pre2 = 0;
		for(int i = 0; i < len1; i++) {
			if(s1[i] == 'a')
				pre1++;
			else
				pre2++;
			if(pre1 - pre2 > 0)
				ans++;
		}
		ll n1 = n, len2 = len, lim1 = lim;
		ll val1 = n1 * len2;
		ll val2 = lim1 * len2;
		ll diff = val1 - val2;
		if(diff > 0 && c1 - c2 > 0)
			ans += diff;
		else if(diff > 0 && c1 - c2 == 0)
			ans = (n1 * temp);
		printf("%lld\n", ans);
	}
	return 0;
}