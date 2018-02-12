#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int p[6][3] = {
		{a, b, c},
		{a, c, b},
		{b, a, c},
		{b, c, a},
		{c, b, a},
		{c, a, b}
	};
	int ans = 0;
	for(int i = 0; i < 6; i++) {
		vector <int> curr;
		curr.push_back(p[i][0]);
		curr.push_back(p[i][1]);
		curr.push_back(p[i][2]);
		int marked[1000];
		memset(marked, 0, sizeof marked);
		for(int j = 1; j < 1000; j += curr[0])
			marked[j] = 1;
		for(int j = 2; j < 1000; j += curr[1])
			marked[j] = 1;
		for(int j = 3; j < 1000; j += curr[2])
			marked[j] = 1;
		int flag = 1;
		for(int i = 1; i < 1000; i++)
			if(!marked[i])
				flag = 0;
		if(flag)
			ans = 1;
	}
	if(ans)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}