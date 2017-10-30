#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m;
	cin>>n>>m;
	if(m>=n-1)
		cout<<n<<endl;
	else
	{
		ll count=0,i=1;
		ll check=n-m;
		while(1)
		{
			count+=i;
			if(count>=check)
				break;
			i++;
		}
		cout<<m+i<<endl;
	}
	return 0;
}