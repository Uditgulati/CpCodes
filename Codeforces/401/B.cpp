#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	string s1,s2;
	cin>>s1>>s2;
	int sher[n],mor[n];
	for(int i=0;i<n;i++)
	{
		sher[i]=(int)(s1[i]);
		mor[i]=(int)(s2[i]);
	}
	sort(sher,sher+n);
	sort(mor,mor+n);
	int index=n-1;
	int count1=0,count2=0;
	for(int i=n-1;i>=0;i--)
	{
		int val=mor[i];
		for(int j=index;j>=0;j--)
		{
			if(sher[j]<=val)
			{
				index=j-1;
				count1++;
				break;
			}
		}
	}
	index=n-1;
	for(int i=n-1;i>=0;i--)
	{
		int val=mor[i];
		for(int j=index;j>=0;j--)
		{
			if(sher[j]<val)
			{
				index=j-1;
				count2++;
				break;
			}
		}
	}
	printf("%d\n",n-count1);
	printf("%d\n",count2);
	return 0;
}