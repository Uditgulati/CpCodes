#include<iostream>
using namespace std;
typedef unsigned int ui;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ui c,d,l,min,max;
		scanf("%d%d%d",&c,&d,&l);
		max=(c+d);
		if(2*d<c)
			min=(c-d);
		else
			min=d;
		if(l%4==0)
		{
			l/=4;
			if(min<=l && l<=max)
				printf("yes\n");
			else
				printf("no\n");
		}
		else
			printf("no\n");
	}
	return 0;
}
 
