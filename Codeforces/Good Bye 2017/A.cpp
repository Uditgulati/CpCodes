#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	string s;
	cin >> s;
	int len = s.size();
	int count1 = 0;
	for(int i = 0; i < len; i++) {
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			count1++;
		else if(s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9')
			count1++;
	}
	printf("%d\n", count1);
	return 0;
}