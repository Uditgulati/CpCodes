#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	for(int x = 0; x < t; x++) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		vector <int> vec1, vec2;
		for(int i = 0; i < n; i++) {
			if(i % 2)
				vec1.push_back(arr[i]);
			else
				vec2.push_back(arr[i]);
		}
		sort(vec1.begin(), vec1.end());
		sort(vec2.begin(), vec2.end());
		for(int i = 0; i < n; i++) {
			if(i % 2)
				arr[i] = vec1[i / 2];
			else
				arr[i] = vec2[i / 2];
		}
		int ans = -1;
		for(int i = 0; i < n - 1; i++)
			if(arr[i] > arr[i + 1]) {
				ans = i;
				break;
			}
		printf("Case #%d: ", x + 1);
		if(ans != -1)
			printf("%d\n", ans);
		else
			printf("OK\n");
	}
	return 0;
}