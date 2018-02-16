#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 2;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		string s;
		cin >> s;
		int len = s.size();
		int lef[len], rig[len];
		int curr = -1, ans1 = 0, ans2 = 0;
		for(int i = 0; i < len; i++)
			lef[i] = rig[i] = -1;
		for(int i = 0; i < len; i++) {
			if(s[i] == 'A')
				curr = 1, ans1++;
			else if(s[i] == 'B')
				curr = 2, ans2++;
			else
				lef[i] = curr;
		}
		curr = -1;
		for(int i = len - 1; i >= 0; i--) {
			if(s[i] == 'A')
				curr = 1;
			else if(s[i] == 'B')
				curr = 2;
			else
				rig[i] = curr;
		}
		for(int i = 0; i < len; i++) {
			if(s[i] != '.')
				continue;
			if(lef[i] == 1 && rig[i] == 1)
				ans1++;
			else if(lef[i] == 2 && rig[i] == 2)
				ans2++;
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}