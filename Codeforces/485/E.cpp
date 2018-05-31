#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

ll count_inversion_merge(int array[], int first, int last) {
    int mid = (first+last)/2;
    int ai = first;
    int bi = mid+1;
    int final[last-first+1], finali=0;
    ll inversion = 0;

    while (ai <= mid && bi <= last) {
        if (array[ai] <= array[bi]) {
                final[finali++] = array[ai++];
        } else {
                final[finali++] = array[bi++];
                inversion += ll(mid - ai + 1);
        }
    }

    while (ai <= mid)
        final[finali++] = array[ai++];

    while (bi <= last) 
        final[finali++] = array[bi++];

    for (int i=0 ; i<last-first+1 ; i++)
        array[i+first] = final[i];      

    return inversion;
}

ll count_inversion(int array[], int a, int b) {
    ll x, y, z;
    if (a >= b) return 0LL;

    int mid = (a+b)/2;
    
    x = count_inversion(array, a, mid);
    y = count_inversion(array, mid+1, b);
    z = count_inversion_merge(array, a, b);

    return x+y+z;
}


int main() {
	int n;
	scanf("%d", &n);
	
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	ll num = n * 3;

	ll num1 = count_inversion(arr, 0, n - 1);

	if(num1 % 2ll == num % 2ll)
		cout << "Petr" << endl;
	else
		cout << "Um_nik" << endl;
	return 0;
}