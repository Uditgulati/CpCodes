#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 2;
const ll modu = 1e9  +7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, p;
		scanf("%d%d", &n, &p);
		if(p < 3) {
			printf("impossible\n");
			continue;
		}
		int num = n / p;
		string s;
		s += 'a';
		for(int i = 0; i < p - 2; i++)
			s += 'b';
		s += 'a';
		while(num--)
			cout << s;
		cout << endl;
	}
	return 0;
}