#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
const int inf1 = 1e9 + 10;
const ll inf2 = 1e18 + 10;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int count1 = n / 10;
		int x1[n], y1[n];
		int mini = inf1, maxi = -inf1;
		int ind1, ind2;
		for(int i = 0; i < n; i++) {
			scanf("%d%d", &x1[i], &y1[i]);
			if(x1[i] < mini)
				mini = x1[i], ind1 = i;
			if(x1[i] > maxi)
				maxi = x1[i], ind2 = i;
		}
		int i1 = min(ind1, ind2);
		int i2 = max(ind1, ind2);
		vector < pair<int, int> > vec1, vec2;
		for(int i = i1; i <= i2; i++) {
			vec1.push_back(make_pair(x1[i], y1[i]));
		}
		for(int i = i2; i < n; i++) {
			vec2.push_back(make_pair(x1[i], y1[i]));
		}
		for(int i = 0; i <= i1; i++) {
			vec2.push_back(make_pair(x1[i], y1[i]));
		}
		sort(vec1.begin(), vec1.end());
		sort(vec2.begin(), vec2.end());
		set < pair<int, int> > ans;
		for(int i = 0; i < n; i++) {
			int x = x1[i], y = y1[i];
			vector < pair<int, int> > points;
			points.push_back(make_pair(x - 1, y));
			points.push_back(make_pair(x + 1, y));
			points.push_back(make_pair(x, y - 1));
			points.push_back(make_pair(x, y + 1));
			points.push_back(make_pair(x - 1, y - 1));
			points.push_back(make_pair(x - 1, y + 1));
			points.push_back(make_pair(x + 1, y - 1));
			points.push_back(make_pair(x + 1, y + 1));
			for(int j = 0; j < 8; j++) {
				int x2 = points[j].first;
				double y2 = points[j].second;
				double x22 = x2;
				if(x2 <= mini || x2 >= maxi)
					continue;
				int ind = lower_bound(vec1.begin(), vec1.end(), make_pair(x2, -inf1)) - vec1.begin();
				double xa = vec1[ind - 1].first, ya = vec1[ind - 1].second;
				double xb = vec1[ind].first, yb = vec1[ind].second;
				double temp = (yb - ya) * (x22 - xa);
				temp /= (xb - xa);
				temp += ya;
				double yl = temp;

				ind = lower_bound(vec2.begin(), vec2.end(), make_pair(x2, -inf1)) - vec2.begin();
				xa = vec2[ind - 1].first, ya = vec2[ind - 1].second;
				xb = vec2[ind].first, yb = vec2[ind].second;
				temp = (yb - ya) * (x22 - xa);
				temp /= (xb - xa);
				temp += ya;
				double yr = temp;
				double diff1 = yl - y2, diff2 = y2 - yr;
				if(diff1 * diff2 > 0.000001)
					ans.insert(points[j]);
			}
		}
		if(ans.size() < count1) {
			printf("-1\n");
			continue;
		}
		set < pair<int, int> >::iterator it;
		int iter = 0;
		for(it = ans.begin(); it != ans.end(); it++) {
			printf("%d %d\n", it -> first, it -> second);
			iter++;
			if(iter == count1)
				break;
		}
	}
	return 0;
}