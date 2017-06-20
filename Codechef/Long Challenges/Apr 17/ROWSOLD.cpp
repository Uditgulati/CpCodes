#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--) {
		string s;
		cin >> s;
		int i;
		for(i = s.size() - 1; i >= 0; i--)
			if(s[i]=='0')
				break;
		i--;
		ll one = 0, count = 0, ans = 0, num = 0;
		for(; i >= 0; i--) {
			count++;
			if(s[i] == '1') {
				ans += (count-one);
				if(s[i+1] == '0')
					num++;
				ans += num;
				one++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}