#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	printf("a");
	if(n % 2 == 1) {
		int lim = n/2;
		for(int i = 0; i < lim; i++)
			if(i % 2 == 0)
				printf("bb");
			else
				printf("aa");
	}
	else {
		n -= 2;
		int lim = n/2;
		int i;
		for(i = 0; i < lim; i++) {
			if(i % 2 == 0)
				printf("bb");
			else
				printf("aa");
		}
		if(lim % 2 == 0)
			printf("b");
		else
			printf("a");
	}
	printf("\n");
	return 0;
}