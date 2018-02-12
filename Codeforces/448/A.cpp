#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int sum = 360, temp = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int mini = inf;
	for(int j = 0; j < n; j++) {
		temp = 0;
		for(int i = j; i < n; i++) {
			temp += arr[i];
			int diff = 360 - temp;
			int d = abs(diff - temp);
			mini = min(mini, d);
		}
	}
	printf("%d\n", mini);
	return 0;
}