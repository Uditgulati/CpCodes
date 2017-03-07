#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
typedef long long ll;
ll store[300001];
int arr[300001],steps[201];
ll prefix[300001];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		deque<ll> qi;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		prefix[0]=arr[0];
   		for(int i=1;i<n;i++)
     	   	prefix[i]=prefix[i-1]+arr[i];
		for(int i=0;i<m;i++)
			scanf("%d",&steps[i]);
		for(int i=m-1;i>=0;i--)
		{
			int len=steps[i];
			int num=n-len;
			for(int j=0;j<=num;j++)
			{
				ll sum=0;
				if(j)
					sum=prefix[j+len-1]-prefix[j-1];
				else
					sum=prefix[j+len-1];
				if(i!=m-1)
				{
					int len1=steps[i+1];
					int upper=j+len-len1;
					if(j)
					{
						while(!qi.empty() && qi.front()<=j)
							qi.pop_front();
						while(!qi.empty() && store[upper-1]>=store[qi.back()])
							qi.pop_back();
						qi.push_back(upper-1);
						sum-=store[qi.front()];
					}
					else
					{
						ll maxi=store[j+1];
						qi.push_back(j+1);
						for(int k=j+2;k<upper;k++)
						{
							maxi=max(maxi,store[k]);
							while(!qi.empty() && store[k]>=store[qi.back()])
								qi.pop_back();
							qi.push_back(k);
						}
						sum-=maxi;
					}
				}
				store[j]=sum;
			}
			qi.clear();
		}
		int lim=n-steps[0];
		ll ans=0;
		for(int i=0;i<=lim;i++)
			ans=max(ans,store[i]);
		printf("%lld\n",ans);
	}
	return 0;
}


