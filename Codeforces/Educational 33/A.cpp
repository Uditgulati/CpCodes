#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int a = 1, b = 2, c = 3;
	int flag = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] == c) {
			flag = 1;
			break;
		}
		if(arr[i] == a) {
			swap(b, c);
		}
		else if(arr[i] == b) {
			swap(a, c);
		}
	}
	if(flag)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}