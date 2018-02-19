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
		map <int, vector <int> > mp1;
		string s1 = s;
		int n = s.size();
		for(int i = 0; i < n; i++) {
			mp1[s[i]].push_back(i);
		}
		map <int, vector <int> >::iterator it;
		int num = 0, pos1 = 0, pos2 = n - 1;
		int ans[n];
		for(it = mp1.begin(); it != mp1.end(); it++) {
			int val = it -> first;
			vector <int> vec1 = it -> second;
			int len1 = vec1.size();
			if(len1 % 2)
				num++;
			int iter = len1 / 2, ind = 0;
			while(iter--) {
				ans[pos1++] = vec1[ind++] + 1;
				ans[pos2--] = vec1[ind++] + 1;
			}
			if(len1 % 2)
				ans[n / 2] = vec1[ind] + 1;
		}
		if((n % 2 && num > 1) || (n % 2 == 0 && num > 0)) {
			printf("-1\n");
			continue;
		}
		//code dekhta hai maadarjaat!!!
		for(int i = 0; i < n; i++)
			printf("%d ", ans[i]);
		printf("\n");
		//haha.. just kidding :P
	}
	return 0;
}