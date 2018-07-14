#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	int flag = 0;
	set <int> s1;
	s1.insert('a');
	s1.insert('e');
	s1.insert('i');
	s1.insert('o');
	s1.insert('u');
	for(int i = 0; i < n; i++) {
		if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'n') {
			if(!s1.count(s[i + 1]) || i + 1 >= n)
				flag = 1;
		}
	}
	if(flag)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}