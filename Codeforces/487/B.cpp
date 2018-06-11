#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main()
{
	int n, p;
	string s;
	scanf("%d%d", &n, &p);
	cin >> s;
	string a = s;
	if(p == n) {
		cout<<"No";
		return 0;
	}
	int flag = 0;
	for(int i = 0; i < (n-p); i++) {
		if(i + p >= n)
			break;
		if((s[i] == s[i+p] && s[i]=='.') || s[i] != s[i+p]) {
			flag = 1;
			if(s[i] == s[i+p])
				s[i]='1', s[i+p]='0';
			else if(s[i+p]=='.') {
				if(s[i]=='1')
					s[i+p]='0';
				else
					s[i+p]='1';
			}
			else if(s[i]=='.') {
				if(s[i+p]=='1')
					s[i]= '0';
				else
					s[i]= '1';
			}
		}
	}
	if(flag) {
		for(int i = 0; i < n; i++)
			if(s[i]=='.')
				s[i]='0';
		cout << s << endl;
	}
	else
		cout << "No" << endl;;
	return 0;
}