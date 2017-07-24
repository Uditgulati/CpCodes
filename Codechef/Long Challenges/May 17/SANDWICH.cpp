#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 1;
const ll inf = 1e9 + 1;
vector <ll> rem;
vector< pair<ll, ll> > vec;
ll fact(ll a, ll modu) {
	ll f = 1;
	for(int i = 1; i <= a; i++)
		f = (f * i) % modu;
	return f;
}
ll power(ll x, ll y, ll modu) {
	ll ans = 1;
    x = x % modu;
    while(y) {
        if(y & 1)
			ans = (ans * x) % modu;
		y >>= 1;
        x = (x * x) % modu;  
    }
    return ans;
}
ll inv(ll a, ll modu) {
	ll m0 = modu, temp, q;
    ll x0 = 0, x1 = 1;
    if (modu == 1)
       return 0;
    while(a > 1) {
        q = a / modu;
        temp = modu;
        modu = a % modu, a = temp;
        temp = x0;
        x0 = x1 - q * x0;
        x1 = temp;
    }
    if(x1 < 0)
       x1 += m0;
    return x1;
}
ll func(ll n, ll r, ll modu) {
	if(r > n)
		return 0;
	ll diff = n - r;
	ll low = min(r, diff);
	ll high = max(r, diff);
	ll ans = 1;
	for(ll i = n; i > high; i--)
		ans = (ans * i) % modu;
	ans = (ans * inv(fact(low, modu), modu)) % modu;
	return ans;
}
ll lucas(ll n, ll r, ll modu) {
	if(r == 0)
		return 1;
	ll ni = n % modu, ri = r % modu;
	return (lucas(n / modu, r / modu, modu) * func(ni, ri, modu)) % modu;
}
ll calc(void) {
	ll prod = 1;
	ll len = vec.size();
    for(int i = 0; i < len; i++)
        prod *= power(vec[i].first, vec[i].second, inf);
    ll res = 0;
    for(int i = 0; i < len; i++) {
        ll pp = prod / power(vec[i].first, vec[i].second, inf);
        res += rem[i] * inv(pp, power(vec[i].first, vec[i].second, inf)) * pp;
    }
    return res % prod;
}
ll E(ll n, ll m) {
	ll ans = 0;
	while(n) {
		n /= m;
		ans += n;
	}
	return ans;
}
ll func2(ll n, ll m, ll num) {
	ll modu = pow(m, num);
	ll arr[(int)modu + 1];
	memset(arr, 0, sizeof(int) * (int)(modu + 1));
	ll i = 2;
	arr[0] = arr[1] = 1;
	while(i <= modu) {
		if(i % m)
			arr[i] = (arr[i - 1] * i) % modu;
		else
			arr[i] = arr[i - 1];
		i++;
	}
	ll val1 = power(arr[modu], n / modu, modu);
	ll val2 = arr[n % modu];
	ll ans = (val1 * val2) % modu;
	return ans;
}
ll func1(ll n, ll m, ll num) {
	ll modu = pow(m, num);
	ll ans = 1, i = 1;
	while(i <= n) {
		ans = (ans * func2(n / i, m, num)) % modu;
		i *= m;
	}
	return ans;
}
ll andrew(ll n, ll r, ll m, ll num) {
	ll modu = pow(m, num);
	ll exp = E(n, m) - E(r, m) - E(n - r, m);
	ll val1 = func1(n, m, num);
	ll val2 = func1(r, m, num);
	ll val3 = func1(n - r, m, num);
	ll val4 = power(m, exp, modu);
	ll ans1 = (val1 * val4) % modu;
	ll ans2 = (inv(val2, modu) * inv(val3, modu)) % modu;
	ll ans = (ans1 * ans2) % modu;
	return ans;
}
int main() {
	int t;
	ll mini[siz];
	memset(mini, 0, sizeof(ll) * siz);
	for(int i = 2; i < siz; i++) {
		if(!mini[i])
			for(int j = i; j < siz; j += i)
				if(!mini[j])
					mini[j] = i;
	}
	scanf("%d", &t);
	while(t--) {
		ll n, k, m;
		scanf("%lld%lld%lld", &n, &k, &m);
		vec.clear();
		rem.clear();
		ll a = mini[m];
		vec.push_back(make_pair(a, 1));
		m /= a;
		while(m != 1) {
			a = mini[m];
			pair<ll, ll> last = vec.back();
			if(a == last.first)
				vec[vec.size() - 1].second++;
			else
				vec.push_back(make_pair(a, 1));
			m /= a;
		}
		ll ans1 = n / k, ans2;
		if(n % k)
			ans1++;
		else {
			printf("%lld 1\n", ans1);
			continue;
		}
		ll n1 = (k - n % k) + ans1 - 1;
		ll r = ans1 - 1;
		int len = vec.size();
		//cout << "Len: " << len << endl;
		//cout << "Factors: ";
		//for(int i = 0; i < len; i++)
		//	cout << vec[i] << " ";
		//cout << endl;
		//cout << "Remainders: ";
		for(int i = 0; i < len; i++) {
			ll a;
			if(vec[i].second == 1)
				a = lucas(n1, r, vec[i].first);
			else
				a = andrew(n1, r, vec[i].first, vec[i].second);
			rem.push_back(a);
			//cout << a << " ";
		}
		//cout << endl;
		ans2 = calc();
		printf("%lld %lld\n", ans1, ans2);
	}
}