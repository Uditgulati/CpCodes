#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector < pair<int, int> > vec1, vec2;
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		vec1.push_back(make_pair(min(a, b), max(a, b)));
	}
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		vec2.push_back(make_pair(min(a, b), max(a, b)));
	}
	set <int> s1;
	for(int i = 0; i < n; i++) {
		int val1 = vec1[i].first, val2 = vec1[i].second;
		for(int j = 0; j < m; j++) {
			int val3 = vec2[j].first, val4 = vec2[j].second;
			int count1 = 0;
			int value = -1;
			if(val1 == val3 || val1 == val4)
				count1++, value = val1;
			if(val2 == val3 || val2 == val4)
				count1++, value = val2;
			if(count1 == 1) {
				s1.insert(value);
			}
		}
	}
	if(s1.size() == 1) {
		printf("%d\n", *(s1.begin()));
		return 0;
	}
	int flag = 0;
	for(int i = 0; i < n; i++) {
		int val1 = vec1[i].first, val2 = vec1[i].second;
		set <int> s2;
		for(int j = 0; j < m; j++) {
			int val3 = vec2[j].first, val4 = vec2[j].second;
			int count1 = 0;
			int value = -1;
			if(val1 == val3 || val1 == val4)
				count1++, value = val1;
			if(val2 == val3 || val2 == val4)
				count1++, value = val2;
			if(count1 == 1) {
				s2.insert(value);
			}
		}
		if(s2.size() > 1) {
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 0; i < m; i++) {
		int val1 = vec2[i].first, val2 = vec2[i].second;
		set <int> s2;
		for(int j = 0; j < n; j++) {
			int val3 = vec1[j].first, val4 = vec1[j].second;
			int count1 = 0;
			int value = -1;
			if(val1 == val3 || val1 == val4)
				count1++, value = val1;
			if(val2 == val3 || val2 == val4)
				count1++, value = val2;
			if(count1 == 1) {
				s2.insert(value);
			}
		}
		if(s2.size() > 1) {
			printf("-1\n");
			return 0;
		}
	}
	printf("0\n");
	return 0;
}