#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int arr1[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr1[i]);
	int arr2[m];
	for(int i = 0; i < m; i++)
		scanf("%d", &arr2[i]);
	int ans = 0;
	vector <int> vec;
	for(int i = m - 1; i >= 0; i --)
		vec.push_back(arr2[i]);
	for(int i = 0; i < n; i++) {
		int curr = arr1[i];
		if(vec.empty())
			continue;
		if(vec.back() < curr)
			continue;
		vec.pop_back();
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}