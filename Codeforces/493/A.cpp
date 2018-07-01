#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int lim = pow(2, n);
	for(int i = 1; i <= lim - 2; i++) {
		vector <int> vec;
		int num = i;
		int t = n;
		while(t--) {
			int r = num % 2;
			vec.push_back(r);
			num /= 2;
		}
		int val1 = 0, val2 = 0;
		int k = 0;
		for(int j = 0; j < n; j++) {
			if(vec[j])
				val1 += arr[j], k++;
			else
				val2 += arr[j];
		}
		if(val1 != val2) {
			printf("%d\n", k);
			for(int j = 0; j < n; j++)
				if(vec[j])
					printf("%d ", j + 1);
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}