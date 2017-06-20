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
		string a[4], b[4];
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		cin >> b[0] >> b[1] >> b[2] >> b[3];
		int count = 0;
		for(int i = 0; i < 4; i++) {
			string s = a[i];
			for(int j = 0; j < 4; j++) {
				if(b[j] == s) {
					count++;
					break;
				}
			}
		}
		if(count >= 2)
			printf("similar\n");
		else
			printf("dissimilar\n");
	}
	return 0;
}