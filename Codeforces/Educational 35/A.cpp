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
	int mini = inf;
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		mini = min(mini, arr[i]);
	}
	vector <int> vec;
	int ans = n;
	for(int i = 0; i < n; i++)
		if(arr[i] == mini)
			vec.push_back(i);
	int len = vec.size();
	for(int i = 0; i < len - 1; i++)
		ans = min(ans, vec[i + 1] - vec[i]);
	printf("%d\n", ans);
	return 0;
}