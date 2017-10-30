#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int count=0;
	while(n--)
	{
		string s;
		cin>>s;
		if(s=="Tetrahedron")
		{
			count+=4;
		}
		else if(s=="Cube")
		{
			count+=6;
		}
		else if(s=="Octahedron")
		{
			count+=8;
		}
		else if(s=="Dodecahedron")
		{
			count+=12;
		}
		else if(s=="Icosahedron")
		{
			count+=20;
		}
	}
	printf("%d\n",count);
	return 0;
}