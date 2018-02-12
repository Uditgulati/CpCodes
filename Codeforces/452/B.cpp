#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 1e5 + 10;
const ll modu = 1e9 + 7;

int arr1[12] = {28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31};
int arr2[12] = {29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31};
int arr3[11] = {31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31};
int arr4[36] = {28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31};
int arr5[36] = {29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31};
int arr6[36] = {28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31};
int arr7[36] = {28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31};



bool sub(int arr[], int arr1[], int n) {
	int num = 36 - n + 1;
	int flag = 0;
	for(int i = 0; i < num; i++) {
		int end1 = i + n;
		int flag1 = 0;
		for(int j = i; j < end1; j++) {
			if(arr[j - i] != arr1[j])
				flag1 = 1;
		}
		if(!flag1)
			flag = 1;
	}
	return flag;
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	if(sub(arr, arr4, n) || sub(arr, arr5, n) || sub(arr, arr6, n) || sub(arr, arr7, n))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}