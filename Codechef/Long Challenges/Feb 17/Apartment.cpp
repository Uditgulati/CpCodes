#include<iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int count=0,flag=0,fine=0;
		int n;
		scanf("%d",&n);
		while(n--)
		{
			int a;
			scanf("%d",&a);
			if(a==0)
			{
				count++;
				flag=1;
			}
			if(flag)
				fine++;
		}
		printf("%d\n",(count*1000+fine*100));
	}
	return 0;
}

