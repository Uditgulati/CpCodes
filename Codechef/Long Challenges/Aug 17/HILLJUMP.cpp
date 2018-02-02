#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 2;
ll arr[siz], inc[siz], tree[4 * siz];
stack < pair<ll, int> > st;
int n, q;
int pre[20][siz];
pair <int, int> qcount[siz];

void update(int p, ll value) {  
	for(tree[p += n] = tree[p += n] + value; p > 1; p >>= 1) 
		tree[p >> 1] = tree[p] + tree[p ^ 1];
}
ll query(int l, int r) {
	ll res = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1)		res += tree[l++];
		if(r&1) 	res += tree[--r];
	}
	return res;
}
void gre(int l, int r) {
	ll ext = query(0, l);
	st.push(pair <ll, int> (arr[l] + ext, l));
	int lim = min(r + 101, n);
	for(int i = l + 1; i < lim; i++) {
		ext += inc[i];
		ll next = arr[i] + ext;
		if(st.empty())
			break;
		while(!st.empty() && next > st.top().first) {
			if(i - st.top().second > 100)
				pre[0][st.top().second] = st.top().second;
			else
				pre[0][st.top().second] = i;
			st.pop();
		}
		if(i <= r)
			st.push(pair <ll, int> (next, i));
	}
	while(!st.empty()) {
		pre[0][st.top().second] = st.top().second;
		st.pop();
	}
}
void change(int l, int r, ll x) {
	inc[l] += x;
	inc[r + 1] -= x;
	update(l, x);
	update(r + 1, -x);
	int lef = max(0, l - 102), rig = max(l, r - 102);
	gre(lef, l);
	gre(rig, r);
}
void change1(int l, int r, ll x) {
	int lef = max(0, l - 102), rig = max(l, r - 102);
	gre(lef, l);
	gre(rig, r);
}

int main() {
	scanf("%d%d", &n, &q);
	memset(inc, 0, sizeof inc);
	memset(tree, 0, sizeof tree);
	for(int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	gre(0, n - 1);
	while(q > 0) {
		q -= 1;
		int a;
		scanf("%d", &a);
		if(a == 1) {
			int i, k, len = 0, flag = 0;
			scanf("%d%d", &i, &k);
			qcount[len] = pair <int, int> (i, k);
			len++;
			while(q--) {
				scanf("%d", &a);
				if(a == 2) {
					flag = 1;
					break;
				}
				scanf("%d%d", &i, &k);
				qcount[len] = pair <int, int> (i, k);
				len++;
			}
			if(len > 16) {
				for(int i = 1; i < 17; i++) {
					for(int j = 0; j < n; j++) {
						pre[i][j] = pre[i-1][pre[i-1][j]];
					}
				}
				for(int i = 0; i < len; i++) {
					int ind = qcount[i].first - 1, k = qcount[i].second;
					int iter = 0;
					while(k) {
						if(pre[iter][ind] == ind)
							break;
						if(k & 1)
							ind = pre[iter][ind];
						k >>= 1;
						iter++;
					}
					printf("%d\n", ind + 1);
				}
			}
			else {
				for(int i = 0; i < len; i++) {
					int ind = qcount[i].first - 1, k = qcount[i].second;
					while(k--) {
						if(pre[0][ind] == ind)
							break;
						ind = pre[0][ind];
					}
					printf("%d\n", ind + 1);
				}
			}
			if(flag) {
				int l, r;
				ll x;
				scanf("%d%d%lld", &l, &r, &x);
				if(r - l < 20) {
					for(int i = l - 1; i < r; i++)
						arr[i] += x;
					change1(l - 1, r - 1, x);
				}
				else
					change(l - 1, r - 1, x);
			}
		}
		else {
			int l, r;
			ll x;
			scanf("%d%d%lld", &l, &r, &x);
			if(r - l < 20) {
				for(int i = l - 1; i < r; i++)
					arr[i] += x;
				change1(l - 1, r - 1, x);
			}
			else
				change(l - 1, r - 1, x);
		}
	}
	return 0;
}