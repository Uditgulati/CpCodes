#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int count1 = 0, count2 = 0;
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for(int i = 0; i < n; i++) {
		if(arr[i] == 1)
			count1++;
		else
			count2++;
	}
	int mini = min(count1, count2);
	int ans = mini;
	count1 -= mini, count2 -= mini;
	int ext = count1 / 3;
	ans += ext;
	printf("%d\n", ans);
	return 0;
}