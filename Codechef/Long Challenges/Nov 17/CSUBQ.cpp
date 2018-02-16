#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 5e5 + 10;
int n;

ll tree1[4 * siz], tree2[4 * siz], tree3[4 * siz], tree4[4 * siz];

void update1(int p, ll value) {
	for(tree1[p += n] = value; p > 1; p >>= 1) 
		tree1[p>>1] = tree1[p] + tree1[p^1];
}
void update2(int p, ll value) {
	for(tree2[p += n] = value; p > 1; p >>= 1) 
		tree2[p>>1] = tree2[p] + tree2[p^1];
}
void update3(int p, ll value) {
	for(tree3[p += n] = value; p > 1; p >>= 1) 
		tree3[p>>1] = tree3[p] + tree3[p^1];
}
void update4(int p, ll value) {
	for(tree4[p += n] = value; p > 1; p >>= 1) 
		tree4[p>>1] = tree4[p] + tree4[p^1];
}
ll query1(int l, int r) {  // sum on interval [l, r)
	ll res = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1) 
			res += tree1[l++];
		if(r&1) 
			res += tree1[--r];
	}
	return res;
}
ll query2(int l, int r) {  // sum on interval [l, r)
	ll res = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1) 
			res += tree2[l++];
		if(r&1) 
			res += tree2[--r];
	}
	return res;
}
ll query3(int l, int r) {  // sum on interval [l, r)
	ll res = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1) 
			res += tree3[l++];
		if(r&1) 
			res += tree3[--r];
	}
	return res;
}
ll query4(int l, int r) {  // sum on interval [l, r)
	ll res = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1) 
			res += tree4[l++];
		if(r&1) 
			res += tree4[--r];
	}
	return res;
}

int main() {
	int q, l, r;
	scanf("%d%d%d%d", &n, &q, &l, &r);
	set <int> s1, s2;
	int arr[n];
	memset(arr, 0, sizeof arr);
	memset(tree1, 0, sizeof tree1);
	memset(tree2, 0, sizeof tree2);
	memset(tree3, 0, sizeof tree3);
	memset(tree4, 0, sizeof tree4);
	while(q--) {
		int t;
		scanf("%d", &t);
		if(t == 1) {
			int x, y, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
			scanf("%d%d", &x, &y);
			x--;
			int prev = arr[x];
			arr[x] = y;
			if(prev > r && y > r)
				continue;
			else if(prev >= l && prev <= r && y >= l && y <= r)
				continue;
			if(prev >= l)
				s1.erase(x), flag1 = 1;
			if(prev > r)
				s2.erase(x), flag2 = 1;

			if(y > r) {
				s2.insert(x), flag4 = 1;
				set<int>::iterator it = s2.find(x);
				if(it == s2.begin()) {
					ll len1 = x + 1;
					ll len2 = n - x;
					update3(x, len1 * len2);
					update4(x, len1);
				}
				else {
					it--;
					ll len1 = x - *it;
					ll len2 = n - x;
					update3(x, len1 * len2);
					update4(x, len1);
				}
			}
			if(y >= l) {
				s1.insert(x), flag3 = 1;
				set<int>::iterator it = s1.find(x);
				if(it == s1.begin()) {
					ll len1 = x + 1;
					ll len2 = n - x;
					update1(x, len1 * len2);
					update2(x, len1);
				}
				else {
					it--;
					ll len1 = x - *it;
					ll len2 = n - x;
					update1(x, len1 * len2);
					update2(x, len1);
				}
				if(prev > r && !(y > r))
					update3(x, 0), update4(x, 0);
			}
			if(y < l) {
				if(prev >= l) {
					update1(x, 0), update2(x, 0);
					update3(x, 0), update4(x, 0);
				}
				else if(prev > r)
					update3(x, 0), update4(x, 0);
			}
			set<int>::iterator it1 = s1.end(), it2 = s2.end();
			if(s2.size() > 0)
				it2--;
			if(s1.size() > 0)
				it1--;
			int last1 = *it1, last2 = *it2;
			if(last2 != x && s2.size() > 0 && flag2 != flag4) {
				set<int>::iterator it = s2.upper_bound(x);
				int pos = *it;
				if(it == s2.end())
					;
				else if(it == s2.begin()) {
					ll len1 = pos + 1;
					ll len2 = n - pos;
					update3(pos, len1 * len2);
					update4(pos, len1);
				}
				else {
					it--;
					ll len1 = pos - *it;
					ll len2 = n - pos;
					update3(pos, len1 * len2);
					update4(pos, len1);
				}
			}
			if(last1 != x && s1.size() > 0 && flag1 != flag3) {
				set<int>::iterator it = s1.upper_bound(x);
				int pos = *it;
				if(it == s1.end())
					;
				else if(it == s1.begin()) {
					ll len1 = pos + 1;
					ll len2 = n - pos;
					update1(pos, len1 * len2);
					update2(pos, len1);
				}
				else {
					it--;
					ll len1 = pos - *it;
					ll len2 = n - pos;
					update1(pos, len1 * len2);
					update2(pos, len1);
				}
			}
		}
		else {
			int l1, r1;
			scanf("%d%d", &l1, &r1);
			l1--, r1--;
			ll val1 = query1(l1, r1 + 1);
			ll num1 = query2(l1, r1 + 1);
			ll num2 = query4(l1, r1 + 1);
			if(val1) {
				set<int>::iterator it = s1.lower_bound(l1);
				ll wid = query2(*it, *it + 1);
				ll diff = wid - (*it - l1) - 1;
				num1 -= diff;
				diff *= (n - *it);
				val1 -= diff;
			}
			ll val2 = query3(l1, r1 + 1);
			if(val2) {
				set<int>::iterator it = s2.lower_bound(l1);
				ll wid = query4(*it, *it + 1);
				ll diff = wid - (*it - l1) - 1;
				num2 -= diff;
				diff *= (n - *it);
				val2 -= diff;
			}
			ll rem = n - r1 - 1;
			printf("%lld\n", val1 - val2 + (num2 - num1) * rem);
		}
	}
	return 0;
}