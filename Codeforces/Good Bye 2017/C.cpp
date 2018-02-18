#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, r;
	scanf("%d%d", &n, &r);
	double arr[n], ans[n];
	for(int i = 0; i < n; i++) {
		scanf("%lf", &arr[i]);
	}
	for(int i = 0; i < n; i++) {
		double curr = arr[i];
		double maxi = r;
		for(int j = 0; j < i; j++) {
			double diff = abs(arr[i] - arr[j]);
			double h = 2.000000 * r;
			double temp = (h * h) - (diff * diff);
			temp = sqrt(temp);
			double y1 = ans[j] + temp;
			maxi = max(maxi, y1);
		}
		ans[i] = maxi;
	}
	for(int i = 0; i < n; i++)
		printf("%.10lf ", ans[i]);
	printf("\n");
	return 0;
}