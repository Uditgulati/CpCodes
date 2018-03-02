#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int r;
	scanf("%d", &r);
	int x1, y1;
	scanf("%d%d", &x1, &y1);
	int x2, y2;
	scanf("%d%d", &x2, &y2);
	double x3 = x1, y3 = y1;
	double x4 = x2, y4 = y2;
	double diff1 = x3 - x4;
	double diff2 = y3 - y4;
	double dist = sqrt((diff1 * diff1) + (diff2 * diff2));
	double lim = r;
	diff1 = -diff1, diff2 = -diff2;
	diff1 /= dist, diff2 /= dist;
	diff1 *= lim, diff2 *= lim;
	double tot = dist + lim;
	double totr = tot / 2.00;
	
	double x5 = x3 - diff1, y5 = y3 - diff2;
	if(x1 == x2 && y1 == y2) {
		x5 = x4 + tot;
		y5 = y4;	
	}

	double ans1 = (x4 + x5) / 2;
	double ans2 = (y4 + y5) / 2;
	if(dist > lim) {
		ans1 = x3, ans2 = y3;
		totr = lim;	
	}
	printf("%.10f %.10f %.10f\n", ans1, ans2, totr);
	return 0;
}