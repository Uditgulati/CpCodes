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
		int n, k;
		scanf("%d%d", &n, &k);
		int arr[k+1];
		vector<int> vec[n];
		memset( arr, 0, sizeof(int) * (k+1) );
		for(int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			while(num--) {
				int a;
				scanf("%d", &a);
				vec[i].push_back(a);
				arr[a]++;
			}
		}
		int i;
		for(i = 1; i <= k; i++) {
			if(arr[i] == 0)
				break;
		}
		if(i <= k)
			printf("sad\n");
		else {
			int flag = 0;
			for(int j = 0; j < n; j++) {
				int s = vec[j].size();
				for(i = 0; i < s; i++) {
					if(arr[vec[j][i]] == 1)
						break;
				}
				if(i == s) {
					flag = 1;
					break;
				}
			}
			if(flag)
				printf("some\n");
			else
				printf("all\n");
		}
	}
	return 0;
}