#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	if(n == 2) {
		printf("1\n");
		printf("1 1\n");
	}
	else if(n % 2) {
		vector <int> vec1, vec2;
		ll sum1 = 0, sum2 = 0;
		int flag = 0;
		vec1.push_back(n), sum1 += (ll)n;
		for(int i = n - 1; i >= 1; i -= 2) {
			if(flag) {
				vec1.push_back(i), sum1 += (ll)i;
				vec1.push_back(i - 1), sum1 += (ll)(i - 1);
			}
			else {
				vec2.push_back(i), sum2 += (ll)i;
				vec2.push_back(i - 1), sum2 += (ll)(i - 1);
			}
			flag = !flag;
		}
		ll diff = abs(sum1 - sum2);
		cout << diff << endl;
		int len = vec1.size();
		printf("%d ", len);
		for(int i = 0; i < len; i++)
			printf("%d ", vec1[i]);
		printf("\n");
	}
	else {
		vector <int> vec1, vec2;
		ll sum1 = 0, sum2 = 0;
		int flag = 0;
		vec1.push_back(1), sum1 += 1LL;
		for(int i = 2; i <= n - 2; i += 2) {
			if(flag) {
				vec1.push_back(i), sum1 += (ll)i;
				vec1.push_back(i + 1), sum1 += (ll)(i + 1);
			}
			else {
				vec2.push_back(i), sum2 += (ll)i;
				vec2.push_back(i + 1), sum2 += (ll)(i + 1);
			}
			flag = !flag;
		}
		if(flag)
			vec1.push_back(n), sum1 += (ll)n; 
		else
			vec2.push_back(n), sum2 += (ll)n;
		ll diff = abs(sum1 - sum2);
		cout << diff << endl;
		int len = vec1.size();
		printf("%d ", len);
		for(int i = 0; i < len; i++)
			printf("%d ", vec1[i]);
		printf("\n");
	}
	return 0;
}