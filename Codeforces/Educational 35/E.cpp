#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

bool func(int p, int q) {
	return (p > q);
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector <int> vec, vec1, vec2, b;//vec-input, vec1-stack, vec2-final stack, b-out 
	int marked[n + 1];
	memset(marked, 0, sizeof marked);
	for(int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
		marked[x] = 1;
	}
	int next = 1;
	vector <int> ans = vec;
	for(int i = 0; i < k; i++) {
		int curr = vec[i];
		vec1.push_back(curr);
		while(int(vec1.size()) > 0) {
			int last = vec1.back();
			if(last == next) {
				b.push_back(last);
				next++;
				vec1.pop_back();
			}
			else
				break;
		}
	}
	vec2 = vec1;
	sort(vec2.begin(), vec2.end(), func);
	if(vec2 != vec1) {
		printf("-1\n");
		return 0;
	}
	int lim = 0;
	while(int(vec1.size()) > 0) {
		int curr = vec1.back();
		for(int i = curr; i > lim; i--)
			if(!marked[i])
				ans.push_back(i), marked[i] = 1;
		vec1.pop_back();
		lim = curr;
	}
	for(int i = n; i > 0; i--)
		if(!marked[i])
			ans.push_back(i);
	for(int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}