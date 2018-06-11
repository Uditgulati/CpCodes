#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int arr[n];
	map<int, int> mp;
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if(mp.count(arr[i]))
			mp[arr[i]]++;
		else
			mp[arr[i]] = 1;
	}
	int ans = n;
	map<int, int>::iterator it = mp.begin();
	int prev = it -> first, freq = it -> second;
	it++;
	for(; it != mp.end(); it++) {
		int curr = it -> first;
		int freq1 = it -> second;
		if(curr > prev && (curr - prev) <= k) {
			ans -= freq;
		}
		prev = curr, freq = freq1;
	}
	printf("%d\n", ans);
	return 0;
}