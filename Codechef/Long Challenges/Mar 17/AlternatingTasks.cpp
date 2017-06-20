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
		int n,ans1=0,ans2=0,a;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(i%2)
				ans2+=a;
			else
				ans1+=a;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(i%2)
				ans1+=a;
			else
				ans2+=a;
		}
		printf("%d\n",min(ans1,ans2));
	}
	return 0;
}