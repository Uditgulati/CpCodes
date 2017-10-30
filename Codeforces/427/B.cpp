#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;
int main() {
	ll k;
	string n;
	cin >> k >> n;
	int len = n.size();
	vector <int> vec;
	for(int i = 0; i < len; i++)
		vec.push_back(n[i] - 48);
	sort(vec.begin(), vec.end());
	int sum = 0;
	for(int i = 0; i < len; i++)
		sum += vec[i];
	if(sum >= k)
		printf("0\n");
	else {
		ll count = 0;
		for(int i = 0; i < len; i++) {
			count++;
			int dig = vec[i];
			sum += (9 - dig);
			if(sum >= k)
				break;
		}
		cout << count << endl;
	}
	return 0;
}