#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	for(int x = 0; x < t; x++) {
		int d;
		scanf("%d", &d);
		string s;
		cin >> s;
		int len = s.size();
		int ans = 0;
		while(1) {
			int ind = -1;
			int tot = 0, count1 = 0;
			for(int i = 0; i < len; i++) {
				if(s[i] == 'C')
					count1++;
				else
					tot += pow(2, count1);
			}
			for(int i = 0; i < len - 1; i++) {
				if(s[i] == 'C' && s[i + 1] == 'S')
					ind = i;
			}
			if(tot <= d || ind == -1)
				break;
			ans++;
			char temp = s[ind];
			s[ind] = s[ind + 1];
			s[ind + 1] = temp;
			//cout << s << endl;
		}
		int tot = 0, count1 = 0;
		for(int i = 0; i < len; i++) {
			if(s[i] == 'C')
				count1++;
			else
				tot += pow(2, count1);
		}
		printf("Case #%d: ", x + 1);
		if(tot <= d)
			printf("%d\n", ans);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}