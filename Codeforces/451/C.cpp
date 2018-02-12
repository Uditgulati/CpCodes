#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

bool suff(string s1, string s2) {
	int len1 = s1.size(), len2 = s2.size();
	int flag = 0;
	int diff = len2 - len1;
	for(int i = 0; i < len1; i++) {
		if(s1[i] != s2[i + diff])
			flag = 1;
	}
	return (!flag);
}

bool func(string p, string q) {
	return(p.size() < q.size());
}

int main() {
	int n;
	map <string, vector <string> > mp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector <string> vec;
		int a;
		scanf("%d", &a);
		while(a--) {
			string s1;
			cin >> s1;
			vec.push_back(s1);
		}
		if(mp.count(s)) {
			vector <string> curr = mp[s];
			int len = vec.size();
			for(int i = 0; i < len; i++)
				curr.push_back(vec[i]);
			mp[s] = curr;
		}
		else {
			mp[s] = vec;
		}
	}
	map<string, vector<string> >::iterator it;
	int m = mp.size();
	printf("%d\n", m);
	for(it = mp.begin(); it != mp.end(); it++) {
		string s = it -> first;
		cout << s << " ";
		vector <string> curr = it -> second, curr1;
		int len1 = curr.size();
		sort(curr.begin(), curr.end(), func);
		int marked[len1];
		memset(marked, 0, sizeof marked);
		for(int i = 0; i < len1; i++) {
			string s1 = curr[i];
			for(int j = i + 1; j < len1; j++) {
				if(suff(s1, curr[j])) {
					marked[i] = 1;
				}

			}
		}
		for(int i = 0; i < len1; i++)
			if(!marked[i])
				curr1.push_back(curr[i]);
		curr.clear();
		curr = curr1;
		len1 = curr.size();
		printf("%d ", len1);
		for(int i = 0; i < len1; i++)
			cout << curr[i] << " ";
		cout << endl;
	}
	return 0;
}