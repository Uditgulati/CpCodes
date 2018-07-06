#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e6 + 10;
const ll modu = 1e9 + 7;

int freq[siz], freq1[siz];
int arr[siz];
int maxi = -1;

bool check(int n, int m, int x, int y) {
	if(x < 0 || x >= n || y < 0 || y >= m)
		return false;
	memset(freq1, 0, sizeof freq1);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			freq1[abs(i - x) + abs(y - j)]++;
	for(int i = 1; i <= maxi; i++)
		if(freq[i] != freq1[i])
			return false;
	return true;
}

int main() {
	int len;
	scanf("%d", &len);
	memset(freq, 0, sizeof freq);
	
	for(int i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
		freq[arr[i]]++;
		maxi = max(maxi, arr[i]);
	}
	if(freq[0] != 1) {
		printf("-1\n");
		return 0;
	}
	if(len == 1) {
		cout << "1 1" << endl;
		cout << "1 1" << endl;
		return 0;
	}
	int now = 4, ind = 0;
	for(int i = 1; i <= maxi; i++) {
		if(freq[i] == now)
			ind = i;
		now += 4;
	}
	vector <int> div;
	for(int i = 1; i <= len; i++) {
		if(len % i == 0)
			div.push_back(i);
	}
	int siz1 = div.size();
	for(int i = 0; i < siz1; i++) {
		int n = div[i];
		int m = len / n;
		if(m < n)
			break;
		int x, y;

		x = ind;
		y = maxi - x;
		//cout << x << " " << y << endl;
		if(check(n, m, x, y)) {
			cout << n << " " << m << endl;
			cout << x + 1 << " " << y + 1 << endl;
			return 0;
		}
		
		x = n - ind - 1;
		y = maxi - x;
		//cout << x << " " << y << endl;
		if(check(n, m, x, y)) {
			cout << n << " " << m << endl;
			cout << x + 1 << " " << y + 1 << endl;
			return 0;
		}

		y = ind;
		x = maxi - y;
		//cout << x << " " << y << endl;
		if(check(n, m, x, y)) {
			cout << n << " " << m << endl;
			cout << x + 1 << " " << y + 1 << endl;
			return 0;
		}
		
		y = m - ind - 1;
		x = maxi - y;
		//cout << x << " " << y << endl;
		if(check(n, m, x, y)) {
			cout << n << " " << m << endl;
			cout << x + 1 << " " << y + 1 << endl;
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}