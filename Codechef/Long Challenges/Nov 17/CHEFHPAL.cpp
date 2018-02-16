#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 2;
const ll modu = 1e9  +7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		if(k == 1) {
			printf("%d ", n);
			for(int i = 0; i < n; i++)
				cout << "a";
			printf("\n");
			continue;
		}
		if(k == 2) {
			if(n == 1)
				printf("1 a\n");
			else if(n == 2)
				printf("1 ab\n");
			else if(n == 3)
				printf("2 aab\n");
			else if(n == 4)
				printf("2 aabb\n");
			else if(n == 5)
				printf("3 aaabb\n");
			else if(n == 6)
				printf("3 aaabbb\n");
			else if(n == 7)
				printf("3 aaababb\n");
			else if(n == 8)
				printf("3 aaababbb\n");
			else {
				printf("4 ");
				string s = "bbabaa";
				int num = n / 6;
				for(int i = 0; i < num; i++)
					cout << s;
				int len = n % 6;
				for(int i = 0; i < len; i++)
					cout << s[i];
				printf("\n");
			}
			continue;
		}
		string s = "abc";
		int num = n / 3, r = n % 3;
		printf("1 ");
		while(num--)
			cout << s;
		if(r == 1)
			cout << "a";
		else if(r == 2)
			cout << "ab";
		printf("\n");
	}
	return 0;
}