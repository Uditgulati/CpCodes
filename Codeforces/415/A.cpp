#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += arr[i];
	int count = 0;
	while(1) {
		if(2 * sum >= n * (2 * k - 1))
			break;
		sum += k;
		n++;
		count++;
	}
	printf("%d\n", count);
	return 0;
}