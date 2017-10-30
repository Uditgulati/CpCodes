#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 2;
const ll modu = 1e9 + 7;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	string s, t;
	cin >> s >> t;
	int len1 = s.size();
	int len2 = t.size();
	int lim = len2 - len1 + 1;
	int ans, curr, ind, flag = 0;
	for(int i = 0; i < lim; i++) {
		curr = 0;
		for(int j = 0; j < len1; j++)
			if(t[i + j] != s[j])
				curr++;
		if(flag) {
			if(curr < ans) {
				ans = curr;
				ind = i;
			}
		}
		else {
			ans = curr;
			ind = i;
			flag = 1;
		}
	}
	printf("%d\n", ans);
	//cout << ind << endl;
	for(int i = 0; i < len1; i++) {
		if(s[i] != t[i + ind])
			printf("%d ", i + 1);
	}
	cout << endl;
	return 0;
}