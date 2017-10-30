#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int b[k];
	for(int i = 0; i < k; i++)
		scanf("%d", &b[i]);
	sort(b, b + k);
	int flag = 0;
	for(int i = 0; i < k - 1; i++)
		if(b[i] != b[i + 1]) {
			flag = 1;
			break;
		}
	if(flag) {
		printf("Yes\n");
		return 0;
	}
	for(int i = 0; i < n; i++)
		if(arr[i] == 0)
			arr[i] = b[0];
	flag = 0;
	for(int i = 0; i < n; i++)
		if(arr[i + 1] <= arr[i]) {
			flag = 1;
			break;
		}
	if(flag) {
		printf("Yes\n");
	}
	else
		printf("No\n");
	return 0;
}