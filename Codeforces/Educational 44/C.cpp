#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, k, l;
	scanf("%d%d%d", &n, &k, &l);
	int m = n * k;

	int arr[m];
	for(int i = 0; i < m; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + m);

	int ind1 = 0, ind2 = 0;
	int val1 = arr[0], val2 = arr[0] + l;
	for(int i = 0; i < m; i++) {
		if(arr[i] <= val2)
			ind2 = i;
		else
			break;
	}

	int num = n;
	int curr1 = ind1;
	int curr2 = ind2 - n + 1;

	ll ans = 0;

	if(curr2 < 0) {
		printf("0\n");
		return 0;
	}
	while(num--) {
		int index1 = curr1, index2 = curr2;
		int value = arr[min(index1, index2)];
		ans += (ll)value;

		curr1 += k, curr2++;
	}
	printf("%lld\n", ans);
	return 0;
}