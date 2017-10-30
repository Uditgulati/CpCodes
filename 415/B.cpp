#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
int main() {
	int n, f;
	scanf("%d%d", &n, &f);
	int arr[n], cust[n];
	for(int i = 0; i < n; i++)
		scanf("%d%d", &arr[i], &cust[i]);
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		int diff;
		if(arr[i] <= cust[i])
			diff = arr[i];
		else
			diff = cust[i];
		sum += diff;
	}
	vector <int> vec;
	for(int i = 0; i < n; i++) {
		int diff, diff1;
		if(arr[i] <= cust[i])
			diff1 = arr[i];
		else
			diff1 = cust[i];
		arr[i] *= 2;
		if(arr[i] <= cust[i])
			diff = arr[i];
		else
			diff = cust[i];
		vec.push_back(diff - diff1);
	}
	sort(vec.begin(), vec.end());
	int count1 = f;
	for(int i = n - 1; i >= 0; i--) {
		if(count1 == 0)
			break;
		if(vec[i] <= 0)
			break;
		sum += vec[i];
		count1--;
	}
	cout << sum << endl;
	return 0;
}