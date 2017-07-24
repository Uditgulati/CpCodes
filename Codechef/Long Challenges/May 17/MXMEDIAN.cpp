#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int siz = 2 * n;
		int arr[siz];
		for(int i = 0; i < siz; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + siz);
		int x = (n + 1) / 2;
		int ans = arr[n + x - 1];
		printf("%d\n", ans);
		for(int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
			printf("%d ", arr[n + i]);
		}
		printf("\n");
	}
	return 0;
}