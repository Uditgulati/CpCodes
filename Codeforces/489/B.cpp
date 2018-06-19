#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

vector <int> div1, div2, div3;
vector < pair<int, int> > veca, vecb; 
int primes[siz];
 
void divisors1(int ind, int p) {
	int len = veca.size();
	if(ind == len) {
		div1.push_back(p);
		return;
	}
	for(int i = 0; i <= veca[ind].second; i++) {
		divisors1(ind + 1, p);
		p *= veca[ind].first;
	}
}


int main() {
	ll l, r, x, y;
	scanf("%lld%lld%lld%lld", &l, &r, &x, &y);
	if(y % x != 0) {
		printf("0\n");
		return 0;
	}
	ll num = y * x;
	ll a = y / x;
	ll a1 = a;
	int ans = 0;
		memset(primes, 0, sizeof(int) * siz);
	for(int i = 2; i < siz; i++)
		if(!primes[i])
			for(int j = 2 * i; j < siz; j += i)
				primes[j] = 1;
	for(int i = 2; i * i <= a; i++) {
		if(a % i == 0) {
			veca.push_back(make_pair(i, 0));
			while(a % i == 0) {
				a /= i;
				veca.back().second++;
			}
		}
	}
	if(a != 1)
		veca.push_back(make_pair(a, 1));
	divisors1(0, 1);
	int len1 = div1.size();
	for(int i = 0; i < len1; i++) {
		ll val1 = div1[i];
		ll val2 = a1 / val1;
		val1 *= x;
		val2 *= x;
		//cout << val1 << " " << val2 << endl;
		ll lcm = (val1 * val2) / (__gcd(val1, val2));
		if(lcm != y)
			continue;
		if(val1 >= l && val1 <= r && val2 >= l && val2 <= r)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}