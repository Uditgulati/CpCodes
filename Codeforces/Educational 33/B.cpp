#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> vec;
	for(int i = 1; i <= 16; i++) {
		int a = pow(2, i) - 1;
		int b = pow(2, i - 1);
		vec.push_back(a * b);
		//cout << a * b << endl;
	}	
	int len = vec.size();
	int ans = -1;
	for(int i = 0; i < len; i++) {
		if(n % vec[i] == 0)
			ans = vec[i];
	}
	printf("%d\n", ans);
	return 0;
}