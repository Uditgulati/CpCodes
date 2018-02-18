#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

vector <int> vec;
vector <ll> vec1;
vector <double> vec2;

double check(int ind, ll val) {
	ll pre = vec1[ind];
	ll num = (ind + 2);
	pre += val;
	double avg = (double) pre / num;
	return avg;
}

int bin(int low, int high, ll val) {
	int l = low;
	int h = high; // Not n - 1
	while(l < h) {
		int mid = (l + h) / 2;
		int mid1 = mid + 1;
		if(check(mid, val) < check(mid + 1, val))
			h = mid;
		else
			l = mid + 1;
	}
	return l;
}

int main() {
	int n;
	scanf("%d", &n);
	double ans = -1;
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		int type;
		scanf("%d", &type);
		if(type == 1) {
			int x;
			scanf("%d", &x);
			ll x1 = x;
			ll len = vec1.size();
			if(len == 0) {
				ans = 0;
				vec.push_back(x);
				ll x1 = x;
				sum += x1;
				vec1.push_back(sum);
				continue;
			}
			ll l1 = (vec1[0] + x1);
			ll r1 = (vec1[len - 1] + x1);
			double low = (double) l1 / 2LL;
			ll len2 = len + 1LL;
			double high = (double) r1 / len2;
			int ind = bin(0, (int)len - 1, x1);
			double temp = check(ind, x1);
			double x2 = x;
			ans = max(x2 - temp, ans);
			vec.push_back(x);
			sum += x1;
			vec1.push_back(sum);
			ll len1 = vec.size();
			double avg = (double) sum / len1;
			vec2.push_back(avg);
		}
		else {
			if(vec.size() == 1)
				ans = 0;
			printf("%.10f\n", ans);
		}
	}
	return 0;
}