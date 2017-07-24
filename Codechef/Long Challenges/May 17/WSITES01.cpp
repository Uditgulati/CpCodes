#include <bits/stdc++.h>
using namespace std;
bool isPrefix(string a, string b) {
	int n1 = a.size(), n2 = b.size();
	if(n1 > n2)
		return false;
	for(int i = 0; i < n1; i++)
		if(a[i] != b[i])
			return false;
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	vector < pair<string, int> > vec; 
	for(int i = 0; i < n; i++) {
		char c;
		string s;
		cin >> c >> s;
		int a;
		(c == '+') ? a = 1 : a = 0;
		vec.push_back(make_pair(s, a));
	}
	sort(vec.begin(), vec.end());
	vector <string> ans;
	int flag = 0;
	for(int i = 0; i < n; i++) {
		if(vec[i].second)
			continue;
		int single  = 0;
		if(i == 0 || vec[i - 1].second)
			single++;
		if(i == n - 1 || vec[i + 1].second)
			single++;
		if(single == 2) {
			string s1, s2, s3 = vec[i].first;
			int n3 = s3.size();
			int count1 = 0, count2 = 0;
			if(i > 0) {
				s1 = vec[i - 1].first;
				int n1 = min((int)s1.size(), n3);
				if(n3 <= s1.size() && isPrefix(s3, s1)) {
					flag = 1;
					break;
				}
				for(int j = 0; j < n1; j++) {
					if(s1[j] != s3[j])
						break;
					count1++;
				}
			}
			if(i < n -1) {
				s2 = vec[i + 1].first;
				int n2 = min((int)s2.size(), n3);
				if(n3 <= s2.size() && isPrefix(s3, s2)) {
					flag = 1;
					break;
				}
				for(int j = 0; j < n2; j++) {
					if(s2[j] != s3[j])
						break;
					count2++;
				}
			}
			int count = max(count1, count2);
			string s(s3.begin(), s3.begin() + count + 1);
			ans.push_back(s);
		}
		else {
			int index1 = i, index2;
			for(index2 = i; index2 < n; index2++)
				if(vec[index2].second == 1)
					break;
			index2--;
			i = index2;
			string prev;
			for(int x = index1; x <= index2; x++) {
				if(x != index1 && isPrefix(prev, vec[x].first)) {
					continue;
				}
				string s1, s2, s3 = vec[x].first;
				int n3 = s3.size();
				int count1 = 0, count2 = 0;
				if(index1 > 0) {
					s1 = vec[index1 - 1].first;
					int n1 = min((int)s1.size(), n3);
					if(n3 <= s1.size() && isPrefix(s3, s1)) {
						flag = 1;
						break;
					}
					for(int j = 0; j < n1; j++) {
						if(s1[j] != s3[j])
							break;
						count1++;
					}
				}
				if(index2 < n -1) {
					s2 = vec[index2 + 1].first;
					int n2 = min((int)s2.size(), n3);
					if(n3 <= s2.size() && isPrefix(s3, s2)) {
						flag = 1;
						break;
					}
					for(int j = 0; j < n2; j++) {
						if(s2[j] != s3[j])
							break;
						count2++;
					}
				}
				int count = max(count1, count2);
				string s(s3.begin(), s3.begin() + count + 1);
				ans.push_back(s);
				prev = s;
			}
			if(flag)
				break;
		}
	}
	if(flag) {
		printf("-1\n");
		return 0;
	}
	sort(ans.begin(), ans.end());
	int lim = ans.size();
	printf("%d\n", lim);
	for(int i = 0; i < lim; i++)
		cout << ans[i] << endl;
	return 0;
}