#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
ll arr[32];
int n;
map <int, int> mp[32];
int dp(int i, ll k) {
	if(i == 0)
		return (arr[0] <= k);
	if(mp[i].count(k))
		return mp[i][k];
	int val = dp(i - 1, k) + dp(i - 1, k / arr[i]) + (arr[i] <= k);
	mp[i].insert(make_pair(k, val));
	return val;
}
int main() {
	ll k;
	scanf("%d%lld", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	printf("%d\n", dp(n - 1, k));
	return 0;
}