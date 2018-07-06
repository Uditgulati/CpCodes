#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, d;
	scanf("%d%d", &n, &d);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	set <int> ans;
	
	for(int i = 0; i < n; i++) {
		int curr = arr[i];
		int val1 = arr[i] - d;
		if(i == 0 || val1 - arr[i - 1] >= d) {
			ans.insert(val1);
			//cout << i << endl;
		}
		int val2 = arr[i] + d;
		if(i == n - 1 || arr[i + 1] - val2 >= d) {
			ans.insert(val2);
			//cout << i << "second" << endl;	
		}
	}
	int len = ans.size();
	printf("%d\n", len);
	return 0;
}