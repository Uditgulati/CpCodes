#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, q;
		scanf("%d%d", &n, &q);
		int arr[n];
		map <int, int> mp, mp1;
		vector <int> vec;
		for(int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			vec.push_back(arr[i]);
			mp[arr[i]] = i;
		}
		sort(vec.begin(), vec.end());
		for(int i = 0; i < n; i++) {
			mp1[vec[i]] = i;
		}
		while(q--) {
			int x;
			scanf("%d", &x);
			int ind = mp[x];
			int ind1 = mp1[x];
			int lim1 = ind1, lim2 = n - ind1 - 1;
			//cout << ind << endl;
			int ans = 0, flag = 0;
			int low = 0, high = n - 1;
			int mid;
			int num1 = 0, num2 = 0;
			int ans1 = 0, ans2 = 0;
			while(low <= high) {
				mid = (low + high) / 2;
				//cout << mid << " ";
				if(arr[mid] == x)
					break;
				else if(arr[mid] < x) {
					if(mid > ind) {
						high = mid - 1;
						ans1++;
						num2++;
					}
					else {
						low = mid + 1;
						num1++;
					}
				}
				else {
					if(mid < ind) {
						low = mid + 1;
						ans2++;
						num1++;
					}
					else {
						high = mid - 1;
						num2++;
					}
				}
			}
			ans = max(ans1, ans2);
			if(num1 > lim1 || num2 > lim2)
				flag = 1;
			if(flag)
				printf("-1\n");
			else
				printf("%d\n", ans);
		}
	}
	return 0;
}