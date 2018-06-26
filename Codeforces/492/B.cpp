#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		arr[i] -= i;
		if(arr[i] < 0)
			arr[i] = 0;
	}
	int ans = inf, index = -1;
	for(int i = 0; i < n; i++) {
		int curr = i;
		int q = arr[i] / n;
		if(arr[i] % n)
			q++;
		int tot = curr + (q * n);
		if(tot < ans)
			index = i, ans = tot;
		//cout << tot << " ";
	}
	//cout << endl;
	printf("%d\n", index + 1);
	return 0;
}