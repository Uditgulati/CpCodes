#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		string s;
		cin >> s;
		int x, y;
		scanf("%d%d", &x, &y);
		int len = s.size();
		int count1 = 0, count2 = 0;
		for(int i = 0; i < len; i++) {
			if(s[i] == 'a')
				count1++;
			else
				count2++;
		}
		int count11 = count1, count22 = count2;
		int num1 = ceil((float)count1 / x), num2 = ceil((float)count2 / y);
		
		if(num1 > num2) {
			int least = num1 - 1;
			int arr[least];
			memset(arr, 0, sizeof arr);
			for(int i = 0; i < least; i++) {
				if(!count2)
					break;
				count2--;
				arr[i] = 1;
			}
			int pos = 0;
			while(count2 && y - 1) {
				int ext = min(count2, y - 1);
				arr[pos] += ext;
				count2 -= ext, pos++;
			}
			for(int i = 0; i < least; i++) {
				int ti = x;
				while(ti--)
					printf("a");
				if(arr[i]) {
					while(arr[i]--)
						printf("b");
				}
				else
					printf("*");
			}
			int fi;
			if(count11 % x)
				fi = count11 % x;
			else
				fi = x;
			while(fi--)
				printf("a");
		}
		else if(num1 < num2) {
			int least = num2 - 1;
			int arr[least];
			memset(arr, 0, sizeof arr);
			for(int i = 0; i < least; i++) {
				if(!count1)
					break;
				count1--;
				arr[i] = 1;
			}
			int pos = 0;
			while(count1 && x - 1) {
				int ext = min(count1, x - 1);
				arr[pos] += ext;
				count1 -= ext, pos++;
			}
			for(int i = 0; i < least; i++) {
				int ti = y;
				while(ti--)
					printf("b");
				if(arr[i]) {
					while(arr[i]--)
						printf("a");
				}
				else
					printf("*");
			}
			int fi;
			if(count22 % y)
				fi = count22 % y;
			else
				fi = y;
			while(fi--)
				printf("b");
		}
		else {
			while(num1--) {
				int ti = min(count1, x);
				count1 -= ti;
				while(ti--)
					printf("a");
				ti = min(count2, y);
				count2 -= ti;
				while(ti--)
					printf("b");
			}
		}
		printf("\n");
	}
	return 0;
}