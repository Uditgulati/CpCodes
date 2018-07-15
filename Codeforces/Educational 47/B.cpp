#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	string ans;
	int c0 = 0, c1 = 0, c2 = 0;
	int flag = 0;
	for(int i = 0; i < n; i++) {
		int curr = s[i] - 48;
		if(curr == 0)
			c0++;
		if(curr == 1)
			c1++;
		if(curr == 2)
			c2++;
	}
	if(c2 == 0) {
		while(c0--)
			cout << "0";
		while(c1--)
			cout << "1";
		cout << endl;
		return 0;
	}
	c0 = c2 = 0;
	int ind = -1;
	for(int i = 0; i < n; i++) {
		int curr = s[i] - 48;
		if(curr == 2) {
			while(c0--)
				cout << "0";
			ind = i;
			break;
		}
		else if(curr == 0) {
			c0++;
		}
	}
	while(c1--)
		cout << "1";
	cout << "2";
	for(int i = ind + 1; i < n; i++) {
		int curr = s[i] - 48;
		if(curr != 1)
			cout << s[i];
	}
	cout << endl;
	return 0;
}