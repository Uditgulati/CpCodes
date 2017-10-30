#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int b[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	int a1, a2, b1, b2;
	int count = 0;
	int freq1[n + 1], freq2[n + 1], freq3[n + 1];
	memset(freq1, 0, sizeof(int) * (n + 1));
	memset(freq2, 0, sizeof(int) * (n + 1));
	memset(freq3, 0, sizeof(int) * (n + 1));
	for(int i = 0; i < n; i++) {
		freq1[a[i]]++;
		freq2[b[i]]++;
	}
	int ans[n];
	for(int i = 0; i < n; i++) {
		if(a[i] != b[i]) {
			if(!count)
				a1 = a[i], b1 = b[i];
			else
				a2 = a[i], b2 = b[i];
			count++;
			ans[i] = 0;
		}
		else
			ans[i] = a[i];
		if(ans[i])
			freq3[ans[i]]++;
	}
	if(count == 0) {
		int m, m1;
		for(int i = 1; i <= n; i++) {
			if(!freq3[i])
				m = i;
			if(freq3[i] == 2)
				m1 = i;
		}
		int flag = 0;
		for(int i = 0; i < n; i++) {
			if(freq3[ans[i]] == 2 && !flag)
				flag = 1, printf("%d ", m);
			else if(ans[i])
				printf("%d ", ans[i]);
			else
				printf("%d ", m);
		}
		printf("\n");
	}
	else if(count == 1) {
		int m;
		for(int i = 1; i <= n; i++)
			if(!freq3[i])
				m = i;
		for(int i = 0; i < n; i++) {
			if(ans[i])
				printf("%d ", ans[i]);
			else
				printf("%d ", m);
		}
		printf("\n");
	}
	else {
		int m1, m2;
		//cout << a1 << a2 << b1 << b2 << endl;
		if(!freq3[a1] && !freq3[b2] && a1 != b2)
			m1 = a1, m2 = b2;
		else if(!freq3[a2] && !freq3[b1] && a2 != b1)
			m1 = b1, m2 = a2;
		int flag = 0;
		for(int i = 0; i < n; i++) {
			if(ans[i])
				printf("%d ", ans[i]);
			else if(flag == 0) {
				printf("%d ", m1);
				flag = 1;
			}
			else
				printf("%d ", m2);
		}
		printf("\n");
	}
	return 0;
}