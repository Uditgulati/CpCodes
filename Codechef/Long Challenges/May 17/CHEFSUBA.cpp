#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
using namespace std;
int main()
{
	int n, k, p;
	scanf("%d%d%d", &n, &k, &p);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int siz = n - k + 1;
	deque < pair <int, int> > dq;
	map <int, int> mp;
	int num = 0;
	for(int i = 0; i < k; i++)
		num += arr[i];
	dq.push_back(make_pair(num, arr[k - 1]));
	mp.insert(make_pair(num,1));
	for(int i = 1; i < siz; i++) {
		num -= arr[i - 1];
		num += arr[k + i - 1];
		dq.push_back(make_pair(num, arr[i + k - 1]));
		if(mp.count(num))
			mp[num]++;
		else
			mp.insert(make_pair(num,1));
	}
	string s;
	cin >> s;
	if(k >= n) {
		int ans = 0;
		for(int i = 0; i < n; i++)
			ans += arr[i];
		for(int i = 0; i < p; i++)
			if(s[i] == '?')
				printf("%d\n", ans);
		return 0;
	}
	int index = siz - 1;
	int index2 = k - 1;
	for(int i = 0; i < p; i++) {
		if(s[i] == '!') {
			pair <int, int> bval = dq.back();
			pair <int, int> fval = dq.front();
			dq.pop_back();
			int ffreq = fval.first;
			int bfreq = bval.first;
			int rig1 = fval.second;
			int rig2 = bval.second;
			int nfreq = ffreq + rig2 - rig1;
			if(mp[bfreq] == 1)
				mp.erase(bfreq);
			else
				mp[bfreq]--;
			//cout << "minus: " << bfreq << endl;
			if(mp.count(nfreq))
				mp[nfreq]++;
			else
				mp.insert(make_pair(nfreq, 1));
			//cout << "nfreq: " << nfreq << endl;
			//cout << "rig1: " << rig1 << " rig2: " << rig2 << endl;
			if(index)
				index--;
			else
				index = siz - 1;
			if(index2)
				index2--;
			else
				index2 = n - 1;
			dq.push_front(make_pair(nfreq, arr[index2]));
			//cout << "new_right: " << arr[index2] << endl;
		}
		else {
			map <int, int>::iterator it;
			it = mp.end();
			it--;
			printf("%d\n", it->first);
		}
	}
	return 0;
}