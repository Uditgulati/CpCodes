#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		string s;
		cin >> s;
		int len = s.size();
		int arr[10];
		vector <int> ans;
		for(int i = 0; i < 10; i++)
			arr[i] = 0;
		for(int i = 0; i < len; i++) {
			int val = s[i] - 48;
			arr[val]++;
		}
		for(int i = 65; i <= 90; i++) {
			int val = i;
			int d1 = val % 10;
			val /= 10;
			int d2 = val % 10;
			if(d1 == d2) {
				if(arr[d1] >= 2)
					ans.push_back(i);
			}
			else if(arr[d1] && arr[d2])
				ans.push_back(i);
		}
		int len1 = ans.size();
		for(int i = 0; i < len1; i++)
			printf("%c", ans[i]);
		printf("\n");
	}
	return 0;
}