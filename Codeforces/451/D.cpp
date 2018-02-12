#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 10;
const ll modu = 1e9 + 7;
const int lim = 1e6 + 10;
int freq[siz], marked[siz];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int arr[n];
	k--;
	memset(marked, 0, sizeof marked);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		freq[arr[i]] = 1;
	}
	int ans = 0;
	sort(arr, arr + n);
	int ind = upper_bound(arr, arr + n, m) - arr;
	int ini = ind;
	int count1 = max(0, ini - k);
	for(int i = ind - 1; i >= 0; i--) {
		if(count1 <= 0)
			break;
		count1--;
		marked[arr[i]] = 1;
		ans++;
	}
	int count2 = min(k, ini);
	//cout << count2 <<endl;
	for(int i = m + 1; i <= lim; i++) {
		int point = i, prev = i - m;
		if(freq[point])
			count2++;
		if(freq[prev] && !marked[prev])
			count2--;
		if(count2 > k) {
			marked[point] = 1;
			ans++, count2--;
		}
	}
	printf("%d\n", ans);
	return 0;
}