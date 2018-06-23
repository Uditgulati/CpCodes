#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size();
	if(n == 1) {
		printf("0\n");
		return 0;
	}
	int val1 = -1, val2 = -1;
	int val3 = -1, val4 = -1;
	int arr1[n], arr2[n];

	for(int i = 0; i < n; i++) {
		if(s1[i] == '0')
			arr1[i] = 0;
		else if(s1[i] == 'X')
			arr1[i] = 1;
		if(s2[i] == '0')
			arr2[i] = 0;
		else if(s2[i] == 'X')
			arr2[i] = 1;
	}
	if(arr1[0] == 0 && arr2[0] == 0)
		val1 = val2 = val3 = val4 = 0;
	else if(arr1[0] == 0 && arr2[0] == 1)
		val2 = val4 = 0;
	else if(arr1[0] == 1 && arr2[0] == 0)
		val3 = val4 = 0;
	else if(arr1[0] == 1 && arr2[0] == 1)
		val4 = 0;
	for(int i = 1; i < n; i++) {
		int t1 = val1, t2 = val2;
		int t3 = val3, t4 = val4;
		val1 = val2 = val3 = val4 = -1;
		if(arr1[i] == 0 && arr2[i] == 0) {
			if(t1 != -1)
				val4 = max(val4, t1 + 1);
			if(t2 != -1)
				val4 = max(val4, t2 + 1);
			if(t3 != -1)
				val4 = max(val4, t3 + 1);
			if(t1 != -1)
				val3 = max(val3, t1 + 1);
			if(t1 != -1)
				val2 = max(val2, t1 + 1);
			int temp = max(t1, t2);
			temp = max(temp, t3);
			temp = max(temp, t4);
			val1 = max(val1, temp);
		}
		else if(arr1[i] == 0 && arr2[i] == 1) {
			if(t1 != -1)
				val4 = max(val4, t1 + 1);
			int temp = max(t1, t2);
			temp = max(temp, t3);
			temp = max(temp, t4);
			val2 = max(val2, temp);
		}
		else if(arr1[i] == 1 && arr2[i] == 0) {
			if(t1 != -1)
				val4 = max(val4, t1 + 1);
			int temp = max(t1, t2);
			temp = max(temp, t3);
			temp = max(temp, t4);
			val3 = max(val3, temp);
		}
		else {
			int temp = max(t1, t2);
			temp = max(temp, t3);
			temp = max(temp, t4);
			val4 = max(val4, temp);
		}
	}
	int ans1 = max(val1, val2);
	int ans2 = max(val3, val4);
	int ans = max(ans1, ans2);
	if(ans == -1)
		ans = 0;
	printf("%d\n", ans);
	return 0;
}