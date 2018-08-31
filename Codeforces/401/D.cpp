#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	string arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	for(int i = n - 1; i > 0; i--) {
		int len1 = arr[i - 1].size();
		int len2 = arr[i].size();
		int flag = 0;
		string ne = "#";
		for(int j = 1; j < len2; j++) {
			if(arr[i - 1][j] > arr[i][j])
				break;
			if(arr[i - 1][j] < arr[i][j]) {
				flag = 1;
				break;
			}
			ne += arr[i - 1][j];
		}
		if(!flag)
			arr[i - 1] = ne;
	}
	for(int i = 0; i < n; i++)
		cout << arr[i] << endl;
	return 0;
}