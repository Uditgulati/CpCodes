#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int first[siz], marked[siz];

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	memset(first, 0, sizeof first);
	memset(marked, 0, sizeof marked);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		int curr = arr[i];
		if(!marked[curr])
			first[curr] = i, marked[curr] = 1;
	}
	int num[n];
	set <int> s1;
	for(int i = n - 1; i >= 0; i--) {
		s1.insert(arr[i]);
		int len = s1.size();
		num[i] = len;
	}
	ll ans = 0;
	for(int i = 0; i < n - 1; i++) {
		int curr = arr[i];
		if(first[curr] == i) {
			ll len = num[i + 1];
			ans += len;
			//cout << i << " " << len << endl;
		}
	}
	cout << ans << endl;
	return 0;
}