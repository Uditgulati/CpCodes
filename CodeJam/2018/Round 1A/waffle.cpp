#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	for(int x = 0; x < t; x++) {
		int r, c, h, v;
		scanf("%d%d%d%d", &r, &c, &h, &v);
		int flag = 0;
		int arr[r][c];
		vector <int> vec[r];
		int sum1 = 0;
		for(int i = 0; i < r; i++) {
			string s;
			cin >> s;
			for(int j = 0; j < c; j++) {
				if(s[j] == '.') {
					arr[i][j] = 0;
				}
				else {
					sum1++;
					arr[i][j] = 1;
				}
			}
		}
		int num = (h + 1) * (v + 1);
		if(sum1 % num)
			flag = 1;
		int count1 = sum1 / num;
		int tot = 0;
		vector <int> pos;
		set <int> s1;
		int ref = count1 * (v + 1);
		for(int i = 0; i < r; i++) {
			int temp = 0;
			for(int j = 0; j < c; j++)
				temp += arr[i][j];
			tot += temp;
			if(tot == ref) {
				pos.push_back(i);
				s1.insert(i);
				tot = 0;
			}
			else if(tot > ref) {
				flag = 1;
				break;
			}
		}
		int len1 = pos.size();
		int cakes[len1];
		memset(cakes, 0, sizeof cakes);
		for(int j = 0; j < c; j++) {
			//memset(cakes, 0, sizeof cakes);
			int temp = 0;
			int ind = 0;
			for(int i = 0; i < r; i++) {
				temp += arr[i][j];
				if(s1.count(i)) {
					cakes[ind++] += temp;
					temp = 0;
				}
			}
			for(int i = 0; i < len1; i++)
				if(cakes[i] > count1) {
					flag = 1;
					break;
				}
			int flag1 = 0;
			for(int i = 0; i < len1; i++)
				if(cakes[i] != count1)
					flag1 = 1;
			if(!flag1)
				memset(cakes, 0, sizeof cakes);
		}
		printf("Case #%d: ", x + 1);
		if(!flag)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}