#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;

int main() {
	int n;
	scanf("%d", &n);
	int arr1[n], arr2[n];
	for(int i = 0; i < n; i++)
		scanf("%d%d", &arr1[i], &arr2[i]);
	int prev = inf;
	int flag = 0;
	for(int i = 0; i < n; i++) {
		int maxi = max(arr1[i], arr2[i]);
		int mini = min(arr1[i], arr2[i]);
		int curr = -1;
		if(maxi <= prev)
			curr = maxi;
		else if(mini <= prev)
			curr = mini;
		else {
			flag = 1;
			break;
		}
		prev = curr;
	}
	if(flag)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}