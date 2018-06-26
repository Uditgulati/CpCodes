#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int n1 = 2 * n;
	int arr[n1];
	for(int i = 0; i < n1; i++)
		scanf("%d", &arr[i]);
	int num = n;
	int ind = 0;
	int ans = 0;
	while(num--) {
		int curr = arr[ind];
		int pos = -1;
		for(int i = ind + 1; i < n1; i++)
			if(arr[i] == curr) {
				pos = i;
				break;
			}
		for(int i = pos; i > ind + 1; i--) {
			swap(arr[i], arr[i - 1]);
			ans++;
		}
		ind += 2;
	}
	printf("%d\n", ans);
	return 0;
}