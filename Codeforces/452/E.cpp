#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int prev = arr[0], num = 1, ind = 0;
	vector < pair<int, int> > vec;
	vector <int> vec1;
	for(int i = 1; i < n; i++) {
		if(arr[i] == prev)
			num++;
		else {
			vec.push_back(make_pair(prev, num));
			vec1.push_back(ind);
			ind = i;
			prev = arr[i], num = 1;
		}
	}
	vec1.push_back(ind);
	vec.push_back(make_pair(prev, num));
	int len = vec.size();
	int ans = 0;
	map <int, pair<int, int> > mp1;
	map <int, set<int> > mp2;
	for(int i = 0; i < len; i++) {
		int ind = vec1[i];
		int val = vec[i].first, num = vec[i].second;
		mp1[ind] = make_pair(val, num);
		set <int> temp;
		temp.insert(ind);
		if(mp2.count(num))
			mp2[num].insert(ind);
		else
			mp2[num] = temp;
	}
	while(mp1.size() > 0) {
		ans++;
		map <int, set<int> >::iterator it;
		it = mp2.end();
		it--;
		set<int>::iterator ind1 = (it -> second).begin();
		int curr = *ind1;
		(it -> second).erase(ind1);
		int cap = (it -> second).size();
		if(cap == 0)
			mp2.erase(it);
		pair<int, int> p = mp1[curr];
		int val = p.first, num = p.second;
		map<int, pair<int, int> >::iterator it1 = mp1.find(curr), it2, it3;
		it2 = it3 = it1;
		it2--, it3++;
		int val1 = (it2 -> second).first, val2 = (it3 -> second).first;
		int num1 = (it2 -> second).second, num2 = (it3 -> second).second;
		if(it1 == mp1.begin() || it3 == mp1.end() || val1 != val2) {
			mp1.erase(it1);
			continue;
		}
		int index1 = it2 -> first, index2 = it3 -> first;
		mp1.erase(curr), mp1.erase(index1), mp1.erase(index2);
		int tot = num1 + num2;
		mp1[index1] = make_pair(val1, tot);
		it = mp2.find(num1);
		(it -> second).erase(index1);
		if((it -> second).size() == 0) 
			mp2.erase(it);
		it = mp2.find(num2);
		(it -> second).erase(index2);
		if((it -> second).size() == 0) 
			mp2.erase(it);
		set <int> s1;
		s1.insert(index1);
		if(mp2.count(tot))
			mp2[tot].insert(index1);
		else
			mp2[tot] = s1;
	}
	printf("%d\n", ans);
	return 0;
}