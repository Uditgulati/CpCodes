#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
bool compare(const pair<ll,int> &i, const pair<ll,int> &j)
{
    return i.first>j.first;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		ll arr[n+1];
		priority_queue<ll> conn[n+1];
		vector<pair<ll,int> > vec;
		for(int i=0;i<n;i++)
		{
			ll x;
			scanf("%lld",&x);
			arr[i+1]=x;
			vec.push_back(make_pair(x,i+1));
		}
		sort(vec.begin(),vec.end(),compare);
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			conn[u].push(arr[v]);
			conn[v].push(arr[u]);
		}
		for(int i=1;i<=n;i++)
			conn[i].push(arr[i]);
		for(int i=1;i<=n;i++)
		{
			int j=0;
			while(!conn[i].empty())
			{
				ll val=conn[i].top();
				if(val!=vec[j].first)
				{
					printf("%d ",vec[j].second);
					break;
				}
				j++;
				conn[i].pop();
			}
			if(conn[i].empty())
			{
				if(j==n)
					printf("0 ");
				else
					printf("%d ",vec[j].second);
			}
		}
		printf("\n");
	}
	return 0;
}
