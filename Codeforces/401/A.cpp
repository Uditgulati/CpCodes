#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	n=n%6;
	if(n==1)
	{
		if(x==0)
			x=1;
		else if(x==1)
			x=0;
	}
	else if(n==2)
	{
		if(x==0)
			x=1;
		else if(x==1)
			x=2;
		else
			x=0;
	}
	else if(n==3)
	{
		if(x==0)
			x=2;
		else if(x==2)
			x=0;
	}
	else if(n==4)
	{
		if(x==0)
			x=2;
		else if(x==1)
			x=0;
		else
			x=1;
	}
	else if(n==5)
	{
		if(x==1)
			x=2;
		else if(x==2)
			x=1;
	}
	printf("%d\n",x);
	return 0;
}