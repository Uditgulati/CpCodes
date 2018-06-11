#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	string s;
	cin >> s;
	int len = s.size();
	int flag = 0;
	for(int i = 1; i < len - 1; i++) {
		set <int> check;
		if(s[i] != '.')
			check.insert(s[i]);
		if(s[i- 1] != '.')
			check.insert(s[i - 1]);
		if(s[i + 1] != '.')
			check.insert(s[i + 1]);
		if(check.size() == 3)
			flag = 1;
	}
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}