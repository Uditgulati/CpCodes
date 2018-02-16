#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;

int main() {
	string s;
	while(cin >> s) {
		int len = 20;
		int a = 0, b = 0, ans = -1, val, c1 = 0, c2 = 0;
		for(int i = 0; i < 10; i++) {
			if(i % 2)
				b += s[i] - 48, c2++;
			else
				a += s[i] - 48, c1++;
			int a1 = 5 - c1, b1 = 5 - c2;
			if(a > b + b1) {
				ans = 1, val = i + 1;
				break;
			}
			else if(b > a + a1) {
				ans = 2, val = i + 1;
				break;
			}
		}
		if(ans == -1) {
			for(int i = 10, it = 0; i < 20; i += 2, it++) {
				int x = s[i] - 48, y = s[i + 1] - 48;
				if(x > y) {
					ans = 1, val = 12 + 2*it;
					break;
				}
				else if(y > x) {
					ans = 2, val = 12 + 2*it;
					break;
				}
			}
		}
		if(ans == 1)
			printf("TEAM-A %d\n", val);
		else if(ans == 2)
			printf("TEAM-B %d\n", val);
		else
			printf("TIE\n");
	}
	return 0;
}