#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

struct Point {
	double x, y;
};
bool compare(Point a,Point b) {
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

class compare_1 {
public:
	bool operator()(const Point i, const Point j) { return compare(i, j); }
};
//Returns positive value if B lies to the left of OA,
// negative if B lies to the right of OA, 0 if collinear
double cross(const Point &O, const Point &A, const Point &B) {
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
//Returns a list of points on the convex hull
vector<Point> convex_hull(vector<Point> P) {
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
	sort(P.begin(), P.end(),compare);
	// Build lower hull
	for(int i = 0; i < n; ++i) {
		while(k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) 
			k--;
		H[k++] = P[i];
	}
	// Build upper hull
	//i starts from n-2 because n-1 is the point which both hulls will have in common
	//t=k+1 so that the upper hull has atleast two points to begin with
	for(int i = n-2, t = k+1; i >= 0; i--) {
		while(k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) 
			k--;
		H[k++] = P[i];
	}
	//the last point of upper hull is same with the fist point of the lower hull
	H.resize(k-1);
	return H;
}



int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, k, r;
		scanf("%d%d%d", &n, &k, &r);
		vector <Point> vec;
		map <Point, int, compare_1> mp1, mp2;
		int arr1[n], arr2[n];
		int maxi1, mini1;	//for x
		int ind1, ind2;
		int ind3, ind4;
		int maxi2, mini2;	//for y
		for(int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			Point temp = {x, y};
			arr1[i] = x, arr2[i] = y;
			mp1[temp] = i;
			vec.push_back(temp);
			if(i) {
				if(x < mini1)
					ind1 = i;
				if(x > maxi1)
					ind2 = i;
				maxi1 = max(maxi1, x), mini1 = min(mini1, x);
			}
			else
				maxi1 = mini1 = x, ind1 = ind2 = i;
			if(i) {
				if(y < mini2)
					ind3 = i;
				if(y > maxi2)
					ind4 = i;
				maxi2 = max(maxi2, y), mini2 = min(mini2, y);
			}
			else
				maxi2 = mini2 = y, ind3 = ind4 = i;
		}
		int lim = (maxi1 - mini1) / 2;
		lim = min(lim, r);
		//cout << "lim: " << lim << endl;
		Point p1 = vec[ind1];
		int flag = 0;
		Point p11 = {p1.x + lim, p1.y};
		for(int i = 0; i < vec.size(); i++) {
			if(vec[i].x == p11.x && vec[i].y == p11.y)
				flag = 1;
		}
		if(!flag) {
			vec[ind1].x += lim;
		}

		mp1.clear();
		for(int i = 0; i < vec.size(); i++) {
			Point curr = vec[i];
			mp1[curr] = i;
		}

		if(k > 1 && ind2 != ind1) {
			Point p2 = vec[ind2];
			int flag1 = 0;
			Point p22 = {p2.x - lim, p2.y};
			for(int i = 0; i < vec.size(); i++)
				if(vec[i].x == p22.x && vec[i].y == p22.y)
					flag1 = 1;
			if(!flag1)
				vec[ind2].x -= lim;
		}

		mp1.clear();
		for(int i = 0; i < vec.size(); i++) {
			Point curr = vec[i];
			mp1[curr] = i;
		}

		int lim1 = (maxi2 - mini2) / 2;
		lim1 = min(lim1, r);

		if(k > 2 && ind3 != ind1 && ind3 != ind2) {
			Point p3 = vec[ind3];
			int flag1 = 0;
			Point p33 = {p3.x, p3.y + lim1};
			for(int i = 0; i < vec.size(); i++)
				if(vec[i].x == p33.x && vec[i].y == p33.y)
					flag1 = 1;
			if(!flag1)
				vec[ind3].y += lim1;
		}

		mp1.clear();
		for(int i = 0; i < vec.size(); i++) {
			Point curr = vec[i];
			mp1[curr] = i;
		}

		if(k > 3 && ind4 != ind1 && ind4 != ind2 && ind4 != ind3) {
			Point p4 = vec[ind4];
			int flag1 = 0;
			Point p44 = {p4.x, p4.y - lim1};
			for(int i = 0; i < vec.size(); i++)
				if(vec[i].x == p44.x && vec[i].y == p44.y)
					flag1 = 1;
			if(!flag1)
				vec[ind4].y -= lim1;
		}

		mp1.clear();
		for(int i = 0; i < vec.size(); i++) {
			Point curr = vec[i];
			mp1[curr] = i;
		}


		vector <Point> hull = convex_hull(vec);
		int len = hull.size();
		for(int i = 0; i < len; i++) {
			Point curr = hull[i];
			mp2[curr] = i;
		}
		
		printf("%d\n", len);
		for(int i = 0; i < len; i++) {
			Point curr = hull[i];
			int ind = mp1[curr];
			printf("%d ", ind + 1);
		}
		printf("\n");
		for(int i = 0; i < n; i++)
			printf("%d %d\n", (int)vec[i].x, (int)vec[i].y);
	}
	return 0;
}