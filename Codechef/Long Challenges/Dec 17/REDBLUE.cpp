#include <bits/stdc++.h>
#define pii pair<int, int>
#define pdi pair<double, int>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;
vector <pii> vec1, vec2;

bool func(pair<pdi, pii> p, pair<pdi, pii> q) {
	return (p.first.first > q.first.first);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		vec1.clear(), vec2.clear();
		for(int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			vec1.push_back(make_pair(x, y));
		}
		for(int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			vec2.push_back(make_pair(x, y));
		}
		int ans = inf;
		for(int i = 0; i < n; i++) {
			int x1 = vec1[i].first, y1 = vec1[i].second;
			int flag = 0;	//0 - not present, 1 - y2 above y1, 2 - y2 below y1
			int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
			vector < pair<pdi, pii> > vec;
			for(int j = 0; j < n; j++) {
				int x2 = vec1[j].first, y2 = vec1[j].second;
				int dy = y2 - y1, dx = x2 - x1;
				if(x2 == x1) {
					//cout << "y: " << x2 << " " << y2 << endl;
					if(y2 > y1)
						flag = 1;
					else if(y2 < y1)
						flag = 2;
				}
				else {
					double p = (double) dy / dx;
					if(x2 < x1)
						count1++;
					else
						count2++;
					vec.push_back(make_pair(make_pair(p, 1), make_pair(x2, y2)));
				}
			}
			for(int j = 0; j < m; j++) {
				int x2 = vec2[j].first, y2 = vec2[j].second;
				int dy = y2 - y1, dx = x2 - x1;
				if(x2 == x1) {
					if(y2 > y1)
						flag = 3;
					else if(y2 < y1)
						flag = 4;
				}
				else {
					double p = (double) dy / dx;
					if(x2 < x1)
						count3++;
					else
						count4++;
					vec.push_back(make_pair(make_pair(p, 2), make_pair(x2, y2)));
				}
			}
			sort(vec.begin(), vec.end(), func);
			int len = vec.size();
			ans = min(ans, min(count1 + count4, count2 + count3));
			//cout << "count: " << count1 << " " << count2 << " " << count3 << " " << count4 << endl;
			//cout << "flag: " << flag << endl;
			//cout << ans << endl;
			for(int j = 0; j < len; j++) {
				int col = vec[j].first.second;
				int x2 = vec[j].second.first, y2 = vec[j].second.second;
				if(flag == 1)
					count1++;
				else if(flag == 2)
					count2++;
				else if(flag == 3)
					count3++;
				else if(flag == 4)
					count4++;
				if(col == 1 && x2 < x1)
					count1--, flag = 2;
				else if(col == 1 && x2 > x1)
					count2--, flag = 1;
				else if(col == 2 && x2 < x1)
					count3--, flag = 4;
				else if(col == 2 && x2 > x1)
					count4--, flag = 3;
				int ans1 = min(count1 + count4, count2 + count3);
				ans = min(ans, ans1);
				//cout << "count: " << count1 << " " << count2 << " " << count3 << " " << count4 << endl;
				//cout << x1 << " " << y1 << " " << x2 << " " << y2 << " ";
				//cout << ans << endl;
			}
		}
		for(int i = 0; i < m; i++) {
			int x1 = vec2[i].first, y1 = vec2[i].second;
			int flag = 0;	//0 - not present, 1 - y2 above y1, 2 - y2 below y1
			int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
			vector < pair<pdi, pii> > vec;
			for(int j = 0; j < n; j++) {
				int x2 = vec1[j].first, y2 = vec1[j].second;
				int dy = y2 - y1, dx = x2 - x1;
				if(x2 == x1) {
					if(y2 > y1)
						flag = 1;
					else if(y2 < y1)
						flag = 2;
				}
				else {
					double p = (double) dy / dx;
					if(x2 < x1)
						count1++;
					else
						count2++;
					vec.push_back(make_pair(make_pair(p, 1), make_pair(x2, y2)));
				}
			}
			for(int j = 0; j < m; j++) {
				int x2 = vec2[j].first, y2 = vec2[j].second;
				int dy = y2 - y1, dx = x2 - x1;
				if(x2 == x1) {
					if(y2 > y1)
						flag = 3;
					else if(y2 < y1)
						flag = 4;
				}
				else {
					double p = (double) dy / dx;
					if(x2 < x1)
						count3++;
					else
						count4++;
					vec.push_back(make_pair(make_pair(p, 2), make_pair(x2, y2)));
				}
			}
			sort(vec.begin(), vec.end(), func);
			int len = vec.size();
			ans = min(ans, min(count1 + count4, count2 + count3));
			//cout << ans << endl;
			for(int j = 0; j < len; j++) {
				int col = vec[j].first.second;
				int x2 = vec[j].second.first, y2 = vec[j].second.second;
				if(flag == 1)
					count1++;
				else if(flag == 2)
					count2++;
				else if(flag == 3)
					count3++;
				else if(flag == 4)
					count4++;
				if(col == 1 && x2 < x1)
					count1--, flag = 2;
				else if(col == 1 && x2 > x1)
					count2--, flag = 1;
				else if(col == 2 && x2 < x1)
					count3--, flag = 4;
				else if(col == 2 && x2 > x1)
					count4--, flag = 3;
				int ans1 = min(count1 + count4, count2 + count3);
				ans = min(ans, ans1);
				//cout << x1 << " " << y1 << " " << x2 << " " << y2 << " ";
				//cout << ans << endl;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}