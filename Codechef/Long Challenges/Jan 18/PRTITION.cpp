#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int x, n;
		scanf("%d%d", &x, &n);
		int ans[n + 1];
		memset(ans, 0, sizeof ans);
		ans[x] = 2;
		vector <int> vec;
		ll sum = 0;
		for(int i = 1; i <= n; i++)
			if(i != x)
				vec.push_back(i), sum += (ll)i;
		if((sum % 2) || (n < 4)) {
			printf("impossible\n");
			continue;
		}
		int len = vec.size();
		vector <int> s1, s2;
		s1.push_back(vec[len - 1]);
		int flag = 0;
		vec.pop_back();
		while(!vec.empty()) {
			int curr = vec.back();
			if(flag)
				s1.push_back(curr);
			else
				s2.push_back(curr);
			vec.pop_back();
			if(vec.empty())
				break;
			int curr1 = vec.back();
			if(flag)
				s1.push_back(curr1);
			else
				s2.push_back(curr1);
			vec.pop_back();
			flag = !flag;
		}
		ll sum1 = 0, sum2 = 0;
		set <int> store1, store2;
		int len1 = s1.size();
		for(int i = 0; i < len1; i++)
			sum1 += (ll)s1[i], store1.insert(s1[i]);
		int len2 = s2.size();
		for(int i = 0; i < len2; i++)
			sum2 += (ll)s2[i], store2.insert(s2[i]);
		ll diff = sum1 - sum2;
		diff /= 2LL;
		int d = diff;
		if(d > 0) {
			if(store1.count(d))
				store1.erase(d), store2.insert(d);
			else {
				for(int i = 0; i < len1; i++) {
					int c = s1[i];
					c -= d;
					if(store2.count(c)) {
						store1.erase(s1[i]), store2.insert(s1[i]);
						store2.erase(c), store1.insert(c);
						break;
					}
				}
			}
		}
		else if(d < 0) {
			if(store2.count(-d))
				store2.erase(-d), store1.insert(-d);
			else {
				for(int i = 0; i < len1; i++) {
					int c = s1[i];
					c -= d;
					if(store2.count(c)) {
						store1.erase(s1[i]), store2.insert(s1[i]);
						store2.erase(c), store1.insert(c);
						break;
					}
				}
			}
		}
		ll f1 = 0, f2 = 0;
		set <int>::iterator it;
		for(it = store1.begin(); it != store1.end(); it++)
			f1 += (ll)(*it);
		for(it = store2.begin(); it != store2.end(); it++)
			f2 += (ll)(*it);
		if(f1 != f2) {
			printf("impossible\n");
			continue;
		}
		for(it = store1.begin(); it != store1.end(); it++) {
			int val = *it;
			ans[val] = 1;
		}
		for(int i = 1; i <= n; i++)
			printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}