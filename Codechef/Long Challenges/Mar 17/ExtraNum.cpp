#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+n);
		if(arr[0]+1!=arr[1])
			printf("%d\n",arr[0]);
		else if(arr[n-2]+1!=arr[n-1])
			printf("%d\n",arr[n-1]);
		else
		{
			int i;
			for(i=0;i<n-1;i++)
				if(arr[i]==arr[i+1])
					break;
			printf("%d\n",arr[i]);
		}
	}
	return 0;
}