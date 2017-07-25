#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, q;
		scanf("%d%d", &n, &q);
		int arr[n];
		vector <int> vec[siz];
		for(int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			vec[arr[i]].push_back(i);
		}
		while(q--) {
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			a--, b--, c--, d--;
			int len = b - a + 1, count = 0;
			if(a == c || a == b) {
				printf("YES\n");
				continue;
			}
			int ind1 = 0, ind2 = 0, flag = 0, pos = 0, prev_diff = 0, freq = 0, count1 = 0, count2 = 0;
			for(int i = 1; i < siz; i++) {
				int num1 = (lower_bound(vec[i].begin(), vec[i].end(), a) - vec[i].begin());
				int num2 = (upper_bound(vec[i].begin(), vec[i].end(), b) - vec[i].begin());
				int num3 = (lower_bound(vec[i].begin(), vec[i].end(), c) - vec[i].begin());
				int num4 = (upper_bound(vec[i].begin(), vec[i].end(), d) - vec[i].begin());
				int len1 = num2 - num1, len2 = num4 - num3;
				if(!len1 && !len2)
					continue;
				if(len1 - len2 > 1 || len2 - len1 > 1) {
					flag = 1;
					break;
				}
				else if(len1 - len2 == 1 || len2 - len1 == 1) {
					if(prev_diff == len2 - len1 && freq == 1)
						;
					else if(!freq)
						;
					else {
						flag = 1;
						break;
					}
					freq++;
				}
				prev_diff = len1 - len2;
				count1 += len1, count2 += len2;
				if(count1 == len && count2 == len)
					break;
			}
			if(flag)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	return 0;
}