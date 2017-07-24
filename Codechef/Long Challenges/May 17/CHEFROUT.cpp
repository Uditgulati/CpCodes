#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--) {
		string s;
		cin >> s;
		int n = s.size();
		int c = 0, e = 0, sl = 0;
		int flag = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] == 'C') {
				c++;
				if(e || sl) {
					flag = 1;
					break;
				}
			}
			else if(s[i] == 'E') {
				e++;
				if(sl) {
					flag = 1;
					break;
				}
			}
			else if(s[i] == 'S') {
				sl++;
			}
		}
		if(flag)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}