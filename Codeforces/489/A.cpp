#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	set <int> s1;
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if(arr[i] != 0)
			s1.insert(arr[i]);
	}
	cout << s1.size() << endl;
	return 0;
}