#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool func(int &p, int &q) {
	return (p > q);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		ll sum1 = 0, sum2 = 0, num = 0;
		vector <int> vec;
		for(int i = 0; i < n; i++) {
			if(arr[i] >= 0)
				sum1 += (ll)arr[i], num++;
			else
				sum2 += (ll)arr[i], vec.push_back(arr[i]);
		}
		sort(vec.begin(), vec.end(), func);
		int len = vec.size();
		ll ans = num * sum1 + sum2;
		for(int i = 0; i < len; i++) {
			sum1 += (ll)vec[i];
			num++;
			sum2 -= (ll)vec[i];
			if(sum1 * num + sum2 >= ans)
				ans = sum1 * num + sum2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}