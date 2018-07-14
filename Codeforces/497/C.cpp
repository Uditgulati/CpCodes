#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	vector <pii> vec;
	multiset <int> check;
	for(int i = 0; i < n; i++) {
		vec.push_back(make_pair(arr[i], i));
		check.insert(arr[i]);
	}
	sort(vec.begin(), vec.end());
	int count1 = 0;
	for(int i = 0; i < n; i++) {
		int ind = vec[i].second;
		int curr = vec[i].first;
		auto it = check.upper_bound(curr);
		if(it != check.end()) {
			check.erase(it);
			count1++;
		}
		else {
			check.erase(check.begin());
		}
	}
	printf("%d\n", count1);
	return 0;
}