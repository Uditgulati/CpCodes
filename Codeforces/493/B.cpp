#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, b;
	scanf("%d%d", &n, &b);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int c1 = 0, c2 = 0;
	vector <int> vec;
	for(int i = 0; i < n; i++) {
		if(arr[i] % 2 == 0)
			c1++;
		else
			c2++;
		if(c1 == c2 && i > 0 && i < n - 1) {
			int diff = abs(arr[i] - arr[i + 1]);
			vec.push_back(diff);
			//cout << diff << " " << i << endl;
		}
	}
	int len = vec.size();
	sort(vec.begin(), vec.end());
	int ans = 0, tot = 0;
	for(int i = 0; i < len; i++) {
		tot += vec[i];
		if(tot <= b)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}