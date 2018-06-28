#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int arr[n];
	set <int> check;
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		check.insert(arr[i]);
	}
	int tot = 0;
	int prev = 0;
	int flag = 1;
	int pre[n];

	for(int i = 0; i < n; i++) {
		int curr = arr[i];
		int diff = curr - prev;
		if(flag)
			tot += diff;
		pre[i] = tot;
		flag = !flag;
		prev = curr;
	}
	int curr = m;
	int diff = curr - prev;
	if(flag)
		tot += diff;
	int ans = tot;

	for(int i = 0; i < n; i++) {
		int marked = tot - pre[i];
		if(i % 2 == 0) {
			int new1 = arr[i] - 1;
			int new2 = arr[i] + 1;
			if(!check.count(new1) && new1 > 0) {
				int tot1 = tot;
				tot1 -= marked;
				int ext = ((m - arr[i]) - marked);
				//cout << marked << " " << ext << " ";
				tot1 += ext;
				tot1--;
				ans = max(ans, tot1);
				//cout << tot1 << endl;
			}
			if(!check.count(new2) && new2 < m) {
				int tot1 = tot;
				tot1 -= marked;
				int ext = ((m - arr[i]) - marked);
				tot1 += ext;
				tot1--;
				ans = max(ans, tot1);
				//cout << tot1 << endl;
			}
		}
		else {
			int new1 = arr[i] - 1;
			int new2 = arr[i] + 1;
			if(!check.count(new1) && new1 > 0) {
				int tot1 = tot;
				tot1 -= marked;
				int ext = ((m - arr[i]) - marked);
				tot1 += ext;
				tot1++;
				ans = max(ans, tot1);
				//cout << tot1 << endl;
			}
			if(!check.count(new2) && new2 < m) {
				int tot1 = tot;
				tot1 -= marked;
				int ext = ((m - arr[i]) - marked);
				tot1 += ext;
				tot1++;
				ans = max(ans, tot1);
				//cout << tot1 << endl;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}