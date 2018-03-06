#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	string s, ans;
	cin >> s;
	int len = s.size();
	string s1 = "abcdefghijklmnopqrstuvwxyz";
	if(len < 26) {
		printf("-1\n");
		return 0;
	}
	int flag = 0;
	int temp = 97;	//ASCII for 'a'
	for(int i = 0; i < len; i++) {
		int curr = s[i];
		if(curr <= temp && temp < 123) {
			ans += (char)(temp);
			temp++;
		}
		else
			ans += s[i];
	}
	if(temp == 123)
		cout << ans << endl;
	else
		printf("-1\n");
	return 0;
}