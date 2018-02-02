#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
using namespace std;
typedef long long ll;
const int siz = 1e2 + 10;
int arr[siz][siz];
int n;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int count1 = 0;
		string s;
		for(int i = 0; i < n; i++) {
			cin >> s;
			for(int j = 0; j < n; j++) {
				arr[i][j] = s[j] - 48;
				if(arr[i][j])
					count1++;
			}
		}
		if(count1 <= 100) {
			printf("0\n");
			continue;
		}
		vector < pair< int, pair<pii,pii> > > vec1, vec10;
		int c, d, l, r;
		for(int j = 0; j < n; j++) {
			int count3 = 0;
			for(int i = 0; i < n; i++) {
				if(arr[i][j])
					count3++;
				else if(count3) {
					int l = i - count3, r = i - 1;
					if(count3 > 1)
						vec10.push_back(mp(count3, mp(mp(0, j + 1), mp(l + 1, r + 1))));
					count3 = 0;
				}
			}
			if(count3) {
				int l = n - count3, r = n - 1;
				if(count3 > 1)
					vec10.push_back(mp(count3, mp(mp(0, j + 1), mp(l + 1, r + 1))));
				count3 = 0;
			}
		}
		int len2 = vec10.size();;
		for(int i = 0; i < len2; i++) {
			int count4 = vec10[i].first;
			int c = vec10[i].second.first.first;
			int d = vec10[i].second.first.second;
			int l = vec10[i].second.second.first;
			int r = vec10[i].second.second.second;
			for(int i1 = l; i1 <= r; i1++) {
				int j1 = i1 * c + d;
				if(arr[i1 - 1][j1 - 1])
					count1--;
				arr[i1 - 1][j1 - 1] = 0;
			}
			if(count1 < 100)
				break;
		}


		for(int j = 0; j < n; j++) {
			vector <int> vec;
			for(int i = 0; i < n; i++) {
				int j1 = i + j;
				if(j1 >= n)
					break;
				vec.push_back(arr[i][j1]);
			}
			int len1 = vec.size();
			int count3 = 0;
			for(int i = 0; i < len1; i++) {
				if(vec[i])
					count3++;
				else if(count3) {
					int l = i - count3, r = i - 1;
					if(count3 > 1)
						vec1.push_back(mp(count3, mp(mp(1, j), mp(l + 1, r + 1))));
					count3 = 0;
				}
			}
			if(count3) {
				int l = n - count3, r = n - 1;
				if(count3 > 1)
					vec1.push_back(mp(count3, mp(mp(1, j), mp(l + 1, r + 1))));
				count3 = 0;
			}
		}
		for(int j = 1; j < n; j++) {
			vector <int> vec;
			for(int i = 0; i < n; i++) {
				int j1 = i - j;
				if(j1 >= n || j1 < 0)
					break;
				vec.push_back(arr[i][j1]);
			}
			int len1 = vec.size();
			int count3 = 0;
			for(int i = 0; i < len1; i++) {
				if(vec[i])
					count3++;
				else if(count3) {
					int l = i - count3, r = i - 1;
					if(count3 > 1)
						vec1.push_back(mp(count3, mp(mp(1, j), mp(l + 1, r + 1))));
					count3 = 0;
				}
			}
			if(count3) {
				int l = n - count3, r = n - 1;
				if(count3 > 1)
					vec1.push_back(mp(count3, mp(mp(1, j), mp(l + 1, r + 1))));
				count3 = 0;
			}
		}

		for(int j = n; j >= 0; j--) {
			vector <int> vec;
			for(int i = 1; i <= n; i++) {
				int j1 = -i + j;
				if(j1 >= n || j1 <= 0)
					break;
				vec.push_back(arr[i - 1][j1 - 1]);
			}
			int len1 = vec.size();
			int count3 = 0;
			for(int i = 0; i < len1; i++) {
				if(vec[i])
					count3++;
				else if(count3) {
					int l = i - count3, r = i - 1;
					if(count3 > 1)
						vec1.push_back(mp(count3, mp(mp(-1, j), mp(l + 1, r + 1))));
					count3 = 0;
				}
			}
			if(count3) {
				int l = n - count3, r = n - 1;
				if(count3 > 1)
					vec1.push_back(mp(count3, mp(mp(-1, j), mp(l + 1, r + 1))));
				count3 = 0;
			}
		}

		
		sort(vec1.begin(), vec1.end());
		int len = vec1.size();
		int ans1 = 0;
		for(int i = len - 1; i >= 0; i--) {
			int count4 = vec1[i].first;
			int c = vec1[i].second.first.first;
			int d = vec1[i].second.first.second;
			int l = vec1[i].second.second.first;
			int r = vec1[i].second.second.second;
			ans1++;
			for(int i1 = l; i1 <= r; i1++) {
				int j1 = i1 * c + d;
				if(arr[i1 - 1][j1 - 1])
					count1--;
				arr[i1 - 1][j1 - 1] = 0;
			}
			if(count1 < 100)
				break;
		}
		int ans2 = 0;
		vector <int> vec2, vec3;
		for(int j = 0; j < n; j++) {
			if(count1 < 100)
				break;
			for(int i = 0; i < n; i++) {
				if(arr[i][j]) {
					vec2.push_back(j + 1);
					vec3.push_back(i + 1);
					arr[i][j] = 0;
					count1--, ans2++;
				}
				if(count1 < 100)
					break;
			}
		}
		int ans3 = vec10.size();
		printf("%d\n", ans1 + ans2 + ans3);
		for(int i = 0; i < ans3; i++) {
			int c = vec10[i].second.first.first;
			int d = vec10[i].second.first.second;
			int l = vec10[i].second.second.first;
			int r = vec10[i].second.second.second;
			printf("0 1 0 1 %d 1 %d %d %d\n", c, d, l, r);
		}
		for(int i = len - 1; i >= 0; i--) {
			int c = vec1[i].second.first.first;
			int d = vec1[i].second.first.second;
			int l = vec1[i].second.second.first;
			int r = vec1[i].second.second.second;
			printf("0 1 0 1 %d 1 %d %d %d\n", c, d, l, r);
			ans1--;
			if(ans1 <= 0)
				break;
		}
		for(int i = 0; i < ans2; i++) {
			int c = 0, d = vec2[i], l = vec3[i], r = vec3[i];
			printf("0 1 0 1 %d 1 %d %d %d\n", c, d, l, r);
		}
	}
	return 0;
}