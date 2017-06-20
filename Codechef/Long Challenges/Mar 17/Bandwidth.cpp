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
		int s=n*n,count=0;
		for(int i=0;i<s;i++)
		{
			int a;
			scanf("%d",&a);
			if(!a)
				count++;
		}
		//cout<<count<<endl;
		int ans=n;
		for(int i=1;i<n;i++)
		{
			int val=2*i;
			count-=val;
			if(count<0)
			{
				ans=i;
				break;
			}
		}
		ans=n-ans;
		printf("%d\n",ans);
	}
	return 0;
}