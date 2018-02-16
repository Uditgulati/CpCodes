#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
int freq[siz];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		memset(freq, 0, sizeof freq);
		scanf("%d", &n);
		int arr[n];
		vector <int> vec1, vec2;
		for(int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			freq[arr[i]]++;
		}
		if(n == 1) {
			printf("0\n");
			printf("%d\n", arr[0]);
			continue;
		}
		map <int, vector<int> > mp;
		map <int, int> mp1;
		vector <int> dummy;
		for(int i = 0; i < siz; i++) {
			if(freq[i] == 2)
				vec2.push_back(i), mp[i] = dummy;
			else if(freq[i] == 1)
				vec1.push_back(i);
		}
		for(int i = 0; i < n; i++) {
			int curr = arr[i];
			if(mp.count(curr))
				mp[curr].push_back(i);
			else
				mp1[curr] = i;
		}
		int len1 = vec1.size();
		int len2 = vec2.size();
		map<int, vector<int> >::iterator it, it1;
		map<int, int>::iterator it2, it3;
		if(len1 == 0) {
			if(len2 == 1) {
				printf("0\n");
				printf("%d %d\n", arr[0], arr[1]);
			}
			else {
				printf("%d\n", n);
				int ans[n];
				for(it = mp.begin(); it != mp.end(); it++) {
					int prev;
					it1 = it;
					it1--;
					if(it == mp.begin()) {
						it1 = mp.end();
						it1--;
					}
					prev = it1 -> first;
					vector <int> pos = it -> second;
					ans[pos[0]] = ans[pos[1]] = prev;
				}
				for(int i = 0; i < n; i++)
					printf("%d ", ans[i]);
				printf("\n");
			}
		}
		else if(len2 == 0) {
			printf("%d\n", n);
			for(int i = 0; i < n; i++) {
				int i1 = (i + 1) % n;
				printf("%d ", arr[i1]);
			}
			printf("\n");
		}
		else {
			if(len1 == 1 && len2 == 1) {
				printf("2\n");
				for(int i = 0; i < n; i++) {
					int i1 = (i + 1) % n;
					printf("%d ", arr[i1]);
				}
				printf("\n");
			}
			else if(len1 == 1) {
				printf("%d\n", n);
				int ans[n];
				for(it = mp.begin(); it != mp.end(); it++) {
					int prev;
					it1 = it;
					it1--;
					if(it == mp.begin()) {
						it1 = mp.end();
						it1--;
					}
					prev = it1 -> first;
					vector <int> pos = it -> second;
					ans[pos[0]] = ans[pos[1]] = prev;
				}
				it2 = mp1.begin();
				int pos1 = it2 -> second;
				ans[pos1] = arr[pos1];
				int pos2 = (pos1 + 1) % n;
				swap(ans[pos1], ans[pos2]);
				for(int i = 0; i < n; i++)
					printf("%d ", ans[i]);
				printf("\n");
			}
			else if(len2 == 1) {
				printf("%d\n", n);
				int ans[n];
				for(it2 = mp1.begin(); it2 != mp1.end(); it2++) {
					int i1 = it2 -> second;
					it3 = it2;
					it3--;
					if(it2 == mp1.begin()) {
						it3 = mp1.end();
						it3--;
					}
					int prev = it3 -> first;
					ans[i1] = prev;
				}
				it = mp.begin(), it2 = mp1.begin();
				vector <int> pos = it -> second;
				int pos1 = pos[0], pos2 = pos[1];
				ans[pos1] = arr[pos1];
				ans[pos2] = arr[pos2];
				int pos3 = it2 -> second;
				it2++;
				int pos4 = it2 -> second;
				swap(ans[pos1], ans[pos3]);
				swap(ans[pos2], ans[pos4]);
				for(int i = 0; i < n; i++)
					printf("%d ", ans[i]);
				printf("\n");
			}
			else {
				printf("%d\n", n);
				int ans[n];
				for(it2 = mp1.begin(); it2 != mp1.end(); it2++) {
					int i1 = it2 -> second;
					it3 = it2;
					it3--;
					if(it2 == mp1.begin()) {
						it3 = mp1.end();
						it3--;
					}
					int prev = it3 -> first;
					ans[i1] = prev;
				}
				for(it = mp.begin(); it != mp.end(); it++) {
					int prev;
					it1 = it;
					it1--;
					if(it == mp.begin()) {
						it1 = mp.end();
						it1--;
					}
					prev = it1 -> first;
					vector <int> pos = it -> second;
					ans[pos[0]] = ans[pos[1]] = prev;
				}
				for(int i = 0; i < n; i++)
					printf("%d ", ans[i]);
				printf("\n");
			}
		}
	}
	return 0;
}