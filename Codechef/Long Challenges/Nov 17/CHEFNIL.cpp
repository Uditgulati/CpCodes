#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 2;
const ll modu = 1e9 + 7;
int arr[502][52][52];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				scanf("%d", &arr[i][j][k]);
	}
	vector <int> vec1, vec2;
	int ans = 0;
	for(int i = 0; i < 2; i++) {
		int maxi = -1, x, y;
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++) {
				if(i == 1 && (j == vec1[0] || k == vec2[0]))
					continue;
				if(arr[i][j][k] > maxi)
					maxi = arr[i][j][j], x = j, y = k; 
			}
		ans += maxi;
		vec1.push_back(x), vec2.push_back(y);
	}
	if(m == 50) {
		vector <int> seq1[4], seq2[4];
		int ans1[4];
		for(int i = 0; i < 4; i++)
			ans1[i] = 0;
		for(int i = 0; i < 50; i++) {
			int maxi = -1, x, y;
			for(int k = 0; k < n; k++)
				if(arr[i][i][k] > maxi)
					maxi = arr[i][i][k], x = i, y = k;
			ans1[0] += maxi;
			seq1[0].push_back(x), seq2[0].push_back(y);
		}
		for(int i = 0; i < 50; i++) {
			int maxi = -1, x, y;
			for(int k = 0; k < n; k++)
				if(arr[i][k][i] > maxi)
					maxi = arr[i][k][i], x = k, y = i;
			ans1[1] += maxi;
			seq1[1].push_back(x), seq2[1].push_back(y);
		}
		for(int i = 0; i < 50; i++) {
			int maxi = -1, x, y;
			for(int j = n - 1; j >= 0; j--)
				if(arr[i][i][j] > maxi)
					maxi = arr[i][i][j], x = i, y = j;
			ans1[2] += maxi;
			seq1[2].push_back(x), seq2[2].push_back(y);
		}
		for(int i = 0; i < 50; i++) {
			int maxi = -1, x, y;
			for(int j = n - 1; j >= 0; j--)
				if(arr[i][j][i] > maxi)
					maxi = arr[i][j][i], x = j, y = i;
			ans1[3] += maxi;
			seq1[3].push_back(x), seq2[3].push_back(y);
		}
		for(int i = 0; i < 4; i++)
			if(ans1[i] > ans) {
				ans = ans1[i];
				vec1.clear(), vec2.clear();
				vec1 = seq1[i], vec2 = seq2[i];
			}
	}
	if(m == 500) {
		int ans1[4];
		for(int i = 0; i < 4; i++)
			ans1[i] = 0;
		vector <int> calc1[4], calc2[4];
		int iter = 0;
		for(int i = 0; i < n; i++) {
			iter = i * 10;
			int val1 = 0, val2 = 0;
			vector <int> v1, v2, v3, v4;
			for(int j = 0; j < 10; j++) {
				int s = 5 * j;
				int maxi1 = -1, x1, y1;
				for(int k = s; k < s + 5; k++)
					if(arr[iter][k][i] > maxi1)
						maxi1 = arr[iter][k][i], x1 = k, y1 = i;
				iter++;
				val1 += maxi1;
				v1.push_back(x1), v2.push_back(y1);
			}
			iter = i * 10;
			for(int j = 9; j >= 0; j--) {
				int s = 5 * j;
				int maxi1 = -1, x1, y1;
				for(int k = s; k < s + 5; k++)
					if(arr[iter][k][i] > maxi1)
						maxi1 = arr[iter][k][i], x1 = k, y1 = i;
				iter++;
				val2 += maxi1;
				v3.push_back(x1), v4.push_back(y1);
			}
			if(val1 > val2) {
				int len = v1.size();
				for(int j = 0; j < len; j++)
					calc1[0].push_back(v1[j]), calc2[0].push_back(v2[j]);
				ans1[0] += val1;
			}
			else {
				int len = v3.size();
				for(int j = 0; j < len; j++)
					calc1[0].push_back(v3[j]), calc2[0].push_back(v4[j]);
				ans1[0] += val2;
			}
		}
		/*
		for(int i = n - 1; i >= 0; i--) {
			int maxi = - 1;
			for(int j = 0; j < 10; j++) {
				int s = 5 * j;
				int maxi1 = -1;
				for(int k = s; k < s + 5; k++) {

				}
			}
		}
		*/
		for(int i = 0; i < 1; i++)
			if(ans1[i] > ans) {
				ans = ans1[i];
				vec1.clear(), vec2.clear();
				vec1 = calc1[i], vec2 = calc2[i];
			}
	}
	int len = vec1.size();
	for(int i = 0; i < len; i++)
		printf("%d %d\n", vec1[i] + 1, vec2[i] + 1);
	if(len < m)
		printf("-1 -1\n");
	return 0;
}