#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
int arr[100][100];
vector <int> moves;
int sx1, sy1, ex1, ey1;
vector <int> vec;


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int count1 = 0;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++) {
			if(s[j] == '.')
				arr[i][j] = 0;
			else if(s[j] == '#')
				arr[i][j] = 1;
			else if(s[j] == 'S')
				arr[i][j] = 2, sx1 = i, sy1 = j;
			else if(s[j] == 'E')
				arr[i][j] = 3, ex1 = i, ey1 = j;
		}
	}
	string s1;
	cin >> s1;
	int len = s1.size();
	for(int i = 0; i < len; i++) {
		int val = s1[i] - 48;
		moves.push_back(val);
	}
	int num = 24;
	vector <int> temp;
	temp.push_back(0);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(3);
	do {
		vector <int> curr;
		for(int i = 0; i < 4; i++)
			curr.push_back(temp[i]);
		vec = curr;
		vector <int> m1;
		for(int i = 0; i < len; i++) {
			int ind = moves[i];
			m1.push_back(vec[ind]);
		}
		int flag = 0, x1 = sx1, y1 = sy1;
		for(int i = 0; i < len; i++) {
			int curr = m1[i];
			if(x1 == ex1 && y1 == ey1) {
				flag = 1;
				break;
			}
			if(curr == 0)
				x1++;
			else if(curr == 1)
				x1--;
			else if(curr == 2)
				y1++;
			else if(curr == 3)
				y1--;
			if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m || arr[x1][y1] == 1)
				break;
			if(x1 == ex1 && y1 == ey1) {
				flag = 1;
				break;
			}
		}
		count1 += flag;
	} while(next_permutation(temp.begin(), temp.end()));
	printf("%d\n", count1);
	return 0;
}