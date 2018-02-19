#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		string s;
		cin >> s;
		int len = s.size();
		int ans = 0;
		for(int i = 0; i <= len - 4; i++) {
			set <int> s1;
			for(int j = i; j < i + 4; j++)
				s1.insert(s[j]);
			if(s1.size() == 4 && s1.count('c') && s1.count('h') && s1.count('e') && s1.count('f'))
				ans++;
		}
		if(!ans)
			printf("normal\n");
		else
			printf("lovely %d\n", ans);
	}	

	return 0;
}