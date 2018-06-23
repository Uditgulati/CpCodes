#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

ll fact(ll a) {
	ll f = 1ll;
	while(a >= 1ll) {
		f *= a;
		a -= 1ll;
	}
	return f;
}

int main() {
	ll n;
	scanf("%lld", &n);
	int arr[10];
	memset(arr, 0, sizeof arr);
	ll n1 = n;
	set <int> s1, s2;
	int flag = 0;
	while(n1 > 0) {
		ll r = n1 % 10ll;
		n1 /= 10ll;
		int r1 = r;
		arr[r1]++;
		s1.insert(r1);
		if(r1 > 0)
			s2.insert(r1);
		if(r1 == 0)
			flag = 1;
	}
	vector <ll> vec, vec1;
	for(int i = 0; i < 10; i++)
		if(arr[i])
			vec.push_back(arr[i]), vec1.push_back(1ll);
	int len = vec.size();
	ll tot = 1ll;
	for(int i = 0; i < len; i++) {
		tot *= vec[i];
	}
	ll ans = 0ll;
	while(tot--) {
		for(int i = len-1; i >= 0; i--) {
			vec1[i] += 1ll;
			if(vec1[i] > vec[i])
				vec1[i] = 1ll;
			else
				break;
		}
		ll temp = 0ll;
		ll val1 = 1ll, val2 = 1ll;
		for(int i = 0; i < len; i++) {
			ll curr = vec1[i];
			temp += curr;
			ll f1 = fact(curr);
			val2 *= f1;
		}
		val1 = fact(temp);
		ll val = val1 / val2;
		ans += val;
		if(flag) {
			vector <ll> vec2 = vec1;
			vec2[0] -= 1ll;
			temp = 0ll;
			val1 = 1ll, val2 = 1ll;
			for(int i = 0; i < len; i++) {
				ll curr = vec2[i];
				temp += curr;
				ll f1 = fact(curr);
				val2 *= f1;
			}
			val1 = fact(temp);
			val = val1 / val2;
			ans -= val;
		}
	}
	printf("%lld\n", ans);
	return 0;
}