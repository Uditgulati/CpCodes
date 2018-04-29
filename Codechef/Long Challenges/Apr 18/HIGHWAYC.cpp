#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	double eps = 0.000001;
	scanf("%d", &t);
	while(t--) {
		int n;
		double s, y;
		scanf("%d%lf%lf", &n, &s, &y);
		double arr1[n], arr3[n], arr4[n];
		int dir[n];
		for(int i = 0; i < n; i++)
			scanf("%lf", &arr1[i]);
		for(int i = 0; i < n; i++)
			scanf("%d", &dir[i]);
		for(int i = 0; i < n; i++)
			scanf("%lf", &arr3[i]);
		for(int i = 0; i < n; i++)
			scanf("%lf", &arr4[i]);
		double ans = 0;
		double chef_time = y / s;
		for(int i = 0; i < n; i++) {
			double dist = ans * arr1[i];
			double pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;
			double dist1 = arr1[i] * chef_time;
			double x1 = 0;
			if(dir[i] == 1) {
				pos1 = arr3[i] + dist;
				pos2 = pos1 - arr4[i];
				pos3 = pos1 + dist1;
				pos4 = pos2 + dist1;
			}
			else {
				pos1 = arr3[i] - dist;
				pos2 = pos1 + arr4[i];
				pos3 = pos1 - dist1;
				pos4 = pos2 - dist1;
			}
			if(pos1*pos2 > 0 && pos2*pos3 > 0 && pos3*pos4 > 0
				&& fabs(pos3) > eps && fabs(pos4) > eps) {
				ans += chef_time;
			}
			else {
				x1 = fabs(pos2);
				double ext = x1 / arr1[i];
				ans += (chef_time + ext);
			}
			//cout << ans << endl;
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}