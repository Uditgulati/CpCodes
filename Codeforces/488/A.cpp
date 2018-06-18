#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int arr1[n], arr2[m];
	set <int> s1;
	for(int i = 0; i < n; i++)
		scanf("%d", &arr1[i]);
	for(int j = 0; j < m; j++) {
		scanf("%d", &arr2[j]);
		s1.insert(arr2[j]);
	}
	for(int i = 0; i < n; i++) {
		if(s1.count(arr1[i]))
			printf("%d ", arr1[i]);
	}
	printf("\n");
	return 0;
}