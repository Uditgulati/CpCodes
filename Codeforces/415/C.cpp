#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const ll modu = 1e9 + 7;
int main() {
	int n;
	scanf("%d", &n);
	ll arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	ll pow[n];
	ll pro = 1;
	for(int i = 0; i < n; i++) {
		pow[i] = pro;
		pro = (pro * 2) % modu;
	}
	ll ans = 0;
	for(int i = n - 1; i >= 0; i--) {
		ll curr = (pow[i] * arr[i]) % modu;
		curr = (curr - arr[i]) % modu;
		if(curr < 0)
			curr += modu;
		ans = (ans + curr) % modu;
	}
	for(int  i = 0 ; i < n; i++) {
		ll curr = (pow[n - i - 1] * arr[i]) % modu;
		curr = (curr - arr[i]) % modu;
		if(curr < 0)
			curr += modu;
		ans = (ans - curr) % modu;
		if(ans < 0)
			ans += modu;
	}
	cout << ans << endl;
	return 0;
}