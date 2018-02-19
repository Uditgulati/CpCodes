#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;
const int inf = 1e9 + 10;
const ll inf1 = 1e18 + 10;

bool func(pair<ll, int> p, pair<ll, int> q) {
	return (p.first > q.first);
}

int merge(int arr[], int temp[], int left, int mid, int right) {
  int i, j, k;
  int inv_count = 0;
 
  i = left; 
  j = mid; 
  k = left;
  while ((i <= mid - 1) && (j <= right)) {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  while (j <= right)
    temp[k++] = arr[j++];
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
 
  return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right) {
  int mid, inv_count = 0;
  if (right > left) {
    mid = (right + left)/2;
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

int inversions(int arr[], int array_size) {
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		int mini = inf;
		scanf("%d%d", &n, &m);
		ll ans[m];
		int l1[m], r1[m];
		for(int i = 0; i < m; i++) {
			int l, r;
			scanf("%d%d", &l, &r);
			ans[i] = r;
			l1[i] = l, r1[i] = r;
		}
		ll arr[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				scanf("%lld", &arr[i][j]);
			}
		vector <ll> pre[m];
		for(int i = 0; i < m; i++) {
			ll low = l1[i];
			ll high = r1[i];
			ll diff = high - low;
			diff /= 100LL;
			for(int j = 0; j < 100; j++) {
				pre[i].push_back(low);
				low += diff;
			}
		}
		for(int k = 0; k < 2000; k++) {
			ll ans1[m];
			int arr1[n];
			for(int i = 0; i < m; i++) {
				int ind = rand() % 100;
				ans1[i] = pre[i][ind];
			}
			vector < pair<ll, int> > vec1;
			for(int i = 0; i < n; i++) {
				ll temp = 0;
				for(int j = 0; j < m; j++) {
					temp += (arr[i][j] * ans1[j]);
				}
				vec1.push_back(make_pair(temp, i));
			}
			sort(vec1.begin(), vec1.end(), func);
			for(int i = 0; i < n; i++)
				arr1[i] = vec1[i].second;
			int inv = inversions(arr1, n);
			if(inv < mini) {
				mini = inv;
				for(int i = 0; i < m; i++)
					ans[i] = ans1[i];
			}
		}
		for(int i = 0; i < m; i++)
			printf("%lld ", ans[i]);
		printf("\n");
	}
	return 0;
}