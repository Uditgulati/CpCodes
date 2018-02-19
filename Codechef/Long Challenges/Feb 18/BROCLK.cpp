#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

struct frac {
	ll x, y;
};

frac mul(frac a, frac b) {
	a.x = (a.x * b.x) % modu;
	a.y = (a.y * b.y) % modu;
	return a;
}
frac md(frac a, ll modu) {
	a.x %= modu;
	a.y %= modu;
	return a;
}
frac sum(frac a, frac b) {
	ll p = (a.y * b.y) % modu;
	ll a1 = (a.x * b.y) % modu;
	ll a2 = (b.x * a.y) % modu;
	ll a3 = (a1 + a2) % modu;
	frac c = {a3, p};
	return c;
}

ll power(ll x, ll y, ll modu) {
	if(!y)
		return 1LL;
	ll ans = 1LL;
	x = x % modu;
	while(y) {
		if(y & 1LL)
			ans = (ans * x) % modu;
		y >>= 1LL;
		x = (x * x) % modu;  
	}
	return ans;
}

ll inv_mod(ll a, ll m) {
	ll g = __gcd(a, m);
	if(g != 1)
		return -1;
	return power(a, m - 2, m);
}

void multiply(frac F[2][2], frac M[2][2], ll modu) {
    frac x =  sum(mul(F[0][0], M[0][0]), mul(F[0][1], M[1][0]));
    frac y =  sum(mul(F[0][0], M[0][1]), mul(F[0][1], M[1][1]));
    frac z =  sum(mul(F[1][0], M[0][0]), mul(F[1][1], M[1][0]));
    frac w =  sum(mul(F[1][0], M[0][1]), mul(F[1][1], M[1][1]));
    F[0][0] = md(x, modu);
    F[0][1] = md(y, modu);
    F[1][0] = md(z, modu);
    F[1][1] = md(w, modu);
}
void power1(frac F[2][2], ll n, ll modu, frac cos1) {
    if(n == 0 || n == 1)
        return;
    frac a = {2LL * cos1.x, cos1.y};
    frac b = {-1LL, 1LL};
    frac c = {1LL, 1LL};
    frac d = {0LL, 1LL};
    frac M[2][2] = {{a, b}, {c, d}};
    power1(F, n / 2LL, modu, cos1);
    multiply(F, F, modu);
    if(n % 2)
        multiply(F, M, modu);
}
pair <frac, frac> expo(ll n, ll modu, frac cos1) {
    frac a = {2LL * cos1.x, cos1.y};
    frac b = {-1LL, 1LL};
    frac c = {1LL, 1LL};
    frac d = {0LL, 1LL};
    frac F[2][2] = {{a, b}, {c, d}};
    power1(F, n, modu, cos1);
    pair <frac, frac> val = make_pair(F[0][0], F[0][1]);
    return val;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll l, d, t1;
		scanf("%lld%lld%lld", &l, &d, &t1);
		ll t2 = t1;
		ll p = sqrt((l * l) - (d * d));
		ll sin1 = p, sin2 = l;
		ll cos1 = d, cos2 = l;
		ll a1 = cos1 % modu, a2 = cos2 % modu;
		ll b1 = ((2LL * cos1 * cos1) - (cos2 * cos2)) % modu, b2 = (cos2 * cos2) % modu;
		ll c1, c2;
		if(t1 == 1)
			c1 = a1, c2 = a2;
		else if(t1 == 2)
			c1 = b1, c2 = b2;
		else {
			frac cos3 = {cos1, cos2};
			pair <frac, frac> e = expo(t1 - 2, modu, cos3);
			frac e1 = e.first, e2 = e.second;
			c1 = (e1.x * b1) % modu;
			c2 = (e1.y * b2) % modu;
			ll d1 = (e2.x * a1) % modu;
			ll d2 = (e2.y * a2) % modu;
			frac x = sum({c1, c2}, {d1, d2});
			c1 = x.x;
			c2 = x.y;
		}
		//cout << b1 << " " << b2 << endl;
		//you should be coding right now
		//instead of stalking :P
		ll g = __gcd(c1, c2);
		c1 /= g;
		c2 /= g;
		ll ans1 = (l * c1) % modu;
		ans1 = (ans1 + modu) % modu;
		c2 = (c2 + modu) % modu;
		ll ans2 = inv_mod(c2, modu);
		printf("%lld\n", (ans1 * ans2) % modu);
	}
	return 0;
}