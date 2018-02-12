#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int m;
	scanf("%d", &m);
	int inv = 0;
	for(int i = 0; i < n; i++) {
		int curr = arr[i];
		for(int j = i + 1; j < n; j++) {
			if(arr[j] < curr)
				inv++;
		}
	}
	int flag = inv % 2;
	for(int i = 0; i < m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		int d = r - l + 1;
		int val = (d * (d - 1)) / 2;
		if(val % 2)
			flag = !flag;
		if(flag)
			printf("odd\n");
		else
			printf("even\n");
	}
	return 0;
}