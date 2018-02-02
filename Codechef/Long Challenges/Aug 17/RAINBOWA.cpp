#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		vector < pair<int, int> > vec;
		int count = 1;
		for(int i = 0; i < n - 1; i++) {
			if(arr[i] == arr[i + 1])
				count++;
			else {
				vec.push_back(make_pair(count, arr[i]));
				count = 1;
			}
		}
		vec.push_back(make_pair(count, arr[n - 1]));
		int len = vec.size();
		//for(int i = 0; i < len; i++)
		//	cout << vec[i].first << " " << vec[i].second << endl;
		if(len != 13) {
			printf("no\n");
			continue;
		}
		int flag = 0;
		int count1[8];
		for(int i = 0; i < 7; i++) {
			int freq = vec[i].first, val = vec[i].second;
			//cout << val << " " << freq << endl;
			if(val != i + 1) {
				flag = 1;
				break;
			}
			count1[i + 1] = freq;
		}
		if(flag) {
			printf("no\n");
			continue;
		}
		int ind = 6;
		for(int i = 7; i < len; i++) {
			int freq = vec[i].first, val = vec[i].second;
			//cout << val << " " << freq << endl;
			if(val != ind || freq != count1[ind]) {
				flag = 1;
				break;
			}
			ind--;
		}
		if(flag)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}