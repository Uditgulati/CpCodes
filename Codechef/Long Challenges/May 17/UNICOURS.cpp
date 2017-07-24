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
		int maxi = -1;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			maxi = max(maxi, a);
		}
		printf("%d\n", (n - maxi));
	}
	return 0;
}