#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d",&n);
	ll l,r;
	scanf("%lld%lld",&l,&r);
	vector<ll> arr;
	vector<ll> diff;
	vector<ll> sum;
	for(int i=0;i<n;i++)
	{
		ll a;
		scanf("%lld",&a);
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n-1;i++)
	{
		diff.push_back(arr[i+1]-arr[i]+1);
		sum.push_back(arr[i+1]+arr[i]-1);
	}
	ll count=0,low=diff[n-2],high=sum[n-2];
	for(int i=n-3;i>=0;i--)
	{
		if(sum[i]>=low)
		{
			low=min(diff[i],low);
		}	
		else
		{
			if(high<l)
				break;
			if(low>r)
			{
				low=diff[i];
				high=sum[i];
				continue;
			}
			if(low<l)
				low=l;
			if(high>r)
				high=r;
			count+=(high-low+1);
			low=diff[i];
			high=sum[i];
		}
	}
	if(low>r || high<l)
		goto END;
	if(low<l)
		low=l;
	if(high>r)
		high=r;
	count+=(high-low+1);
	END:printf("%lld\n",count);
	return 0;
}

