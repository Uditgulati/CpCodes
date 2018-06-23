#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	double tot = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		tot += arr[i];
	}
	sort(arr, arr + n);
	int ans = 0;
	double n1 = n;
	double val = tot / n1;
	if(val >= 4.500000) {
		printf("0\n");
		return 0;
	}
	double five = 5.00;
	for(int i = 0; i < n; i++) {
		ans++;
		double curr = arr[i];
		tot -= curr;
		tot += five;
		val = tot / n1;
		if(val >= 4.500000)
			break;
	}
	printf("%d\n", ans);
	return 0;
}