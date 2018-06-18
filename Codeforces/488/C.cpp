#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;

double dist(double x1, double y1, double x2, double y2) {
	double val = ((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2));
	return sqrt(val);
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
	double a = dist(x1, y1, x2, y2);
	double b = dist(x1, y1, x3, y3);
	double c = dist(x2, y2, x3, y3);
	double s = (a + b + c) / 2.00;
	double val = s * (s - a) * (s - b) * (s - c);
	return sqrt(val);
}

int main() {
	int x1[4], y1[4];
	int min1 = inf, min2 = inf;
	int max1 = -inf, max2 = -inf;
	for(int i = 0; i < 4; i++) {
		scanf("%d%d", &x1[i], &y1[i]);
		min1 = min(min1, x1[i]);
		min2 = min(min2, y1[i]);
		max1 = max(max1, x1[i]);
		max2 = max(max2, y1[i]);
	}
	double p1 = (x1[0] + x1[1] + x1[2] + x1[3]);
	p1 /= 4.00;
	double p2 = (y1[0] + y1[1] + y1[2] + y1[3]);
	p2 /= 4.00;
	int x2[4], y2[4];
	for(int i = 0; i < 4; i++)
		scanf("%d%d", &x2[i], &y2[i]);
	double q1 = (x1[0] + x1[1] + x1[2] + x1[3]);
	q1 /= 4.00;
	double q2 = (y1[0] + y1[1] + y1[2] + y1[3]);
	q2 /= 4.00;
	int flag = 0;
	for(int i = 0; i < 4; i++) {//points of rhom in sq
		int x = x2[i], y = y2[i];
		if(x >= min1 && x <= max1 && y >= min2 && y <= max2)
			flag = 1;
	}
	for(int i = 0; i < 4; i++) {//points of sq in rhom
		double x = x1[i], y = y1[i];
		double val1 = 0, val2 = 0;
		val1 = dist(x2[0], y2[0], x2[1], y2[1]) * dist(x2[1], y2[1], x2[2], y2[2]);
		for(int j = 0; j < 4; j++) {
			int j1 = (j + 1) % 4;
			val2 += area(x, y, x2[j], y2[j], x2[j1], y2[j1]);
		}
		if(fabs(val1 - val2) < 0.00001)
			flag = 1;
	}
	double x = p1, y = p2;
	double val1 = 0, val2 = 0;
	val1 = dist(x2[0], y2[0], x2[1], y2[1]) * dist(x2[1], y2[1], x2[2], y2[2]);
	for(int j = 0; j < 4; j++) {
		int j1 = (j + 1) % 4;
		val2 += area(x, y, x2[j], y2[j], x2[j1], y2[j1]);
	}
	if(fabs(val1 - val2) < 0.00001)
		flag = 1;
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}