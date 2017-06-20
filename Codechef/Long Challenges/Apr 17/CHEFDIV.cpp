#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 1;
int primes[siz];
vector< ll > vec;
vector< ll > factors[siz];

int main()
{
	memset(primes, 0, sizeof(int) * siz);
	ll a, b;
	scanf("%lld%lld", &a, &b);
	ll ans = 0;
	ll range = b-a;
	primes[0] = primes[1] = 1;
	for(int i = 2; i < siz; i++)
		if(!primes[i])
			for(int j = 2 * i; j < siz; j += i)
				primes[j] = 1;
	for(int i = 2; i < siz; i++)
		if(!primes[i])
			vec.push_back(i);

	int len = vec.size();
	for(int i = 0; i < len; i++) {
		ll p = vec[i];
		ll r = a % p;
		ll start = 0;
		if(r)
			start = p - r;
		for(ll n1 = start; n1 <= range; n1 += p) {
			factors[n1].push_back(p);
		}
	}

	for(ll n1 = 0; n1 <= range; n1++) {
		ll n = n1 + a;
		len = factors[n1].size();
		vector< int > expo;
		for(int i = 0; i < len; i++) {
			int count = 0;
			ll p = factors[n1][i];
			while(n % p == 0) {
				count++;
				n /= p;
			}
			expo.push_back(count);
		}
		if(n != 1)
			expo.push_back(1);
		len = expo.size();
		//cout << "Expo: ";
		//for(int i = 0; i < len; i++)
		//	printf("%d ", expo[i]);
		//cout << endl;
		int sum = 0;
		for(int i = 0; i < len; i++)
			sum += expo[i];
		for(int i = 0; i < len; i++)
			expo[i]++;
		ll mul;
		//cout << "SUM: " << sum << endl;
		while(sum--) {
			int maxi = expo[0], index = 0;
			for(int i = 1; i < len; i++) {
				if(expo[i] > maxi)
					maxi = expo[i], index = i;
				//cout << "Maxi: " << maxi << " Index: " << index << endl;
			}
			mul = 1;
			for(int i = 0; i < len; i++)
				mul *= (ll)expo[i];
			ans += mul;
			expo[index]--;
		}
		//cout << "MUL: " << ans << endl;
	}
	printf("%lld\n", ans);
	return 0;
}