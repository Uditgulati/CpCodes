#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e3 + 2;
const ll mo = 1e9 + 7;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		string s;
		cin >> s;
		int ans = 0;
		int len = s.size();
		vector <int> vec;
		for(int i = 0; i < len; i++) {
			if(s[i] == '<')
				vec.push_back(1);
			else if(s[i] == '>')
				vec.push_back(2);
		}
		len = vec.size();
		int count = 0;
		for(int i = 0; i < len - 1; i++) {
			if(vec[i] != vec[i + 1]) {
				ans = max(ans, count + 1);
				//cout << count + 1 << endl;
				count = -1;
			}
			count++;
		}
		if(!vec.empty())
			ans = max(ans, count + 1);
		//cout << count + 1 << endl;
		printf("%d\n", ans + 1);
	}
	return 0;
}