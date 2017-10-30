#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;
int main() {
	int s, v1, v2, t1, t2, t;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int ans1, ans2;
	int val1 = s * v1, val2 = s * v2;
	val1 += 2 * t1, val2 += 2 * t2;
	if(val1 < val2)
		printf("First\n");
	else if(val2 < val1)
		printf("Second\n");
	else
		printf("Friendship\n");
	return 0;
}