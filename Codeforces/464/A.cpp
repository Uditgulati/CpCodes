#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n + 1];
	for(int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	int flag = 0;
	for(int i = 1; i <= n; i++) {
		int i1 = i;
		int ind1 = arr[arr[arr[i]]];
		if(ind1 == i1)
			flag = 1;
	}
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}