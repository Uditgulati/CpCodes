#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;
typedef pair<int, pair<int,int> > pii;
struct comp 
{
    bool operator()(const pii& a, const pii& b)
     {
     	return (a.first<b.first);
     }                               
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		string s;
		cin>>s;
		int arr[n];
		for(int i=0;i<n;i++)
			arr[i]=(int)(s[i]-48);
		if(k>=n)
		{
			printf("1\n");
			continue;
		}
		int k1=k,i;
		for(i=0;i<n;i++)
		{
			if(i%2!=0 && arr[i]==0)
			{
				if(k1)
					k1--;
				else
					break;
			}
			else if(i%2==0 && arr[i]==1)
			{
				if(k1)
					k1--;
				else
					break;
			}
		}
		if(i==n)
		{
			printf("1\n");
			continue;
		}
		k1=k;
		for(i=0;i<n;i++)
		{
			if(i%2!=0 && arr[i]==1)
			{
				if(k1)
					k1--;
				else
					break;
			}
			else if(i%2==0 && arr[i]==0)
			{
				if(k1)
					k1--;
				else
					break;
			}
		}
		if(i==n)
		{
			printf("1\n");
			continue;
		}
		priority_queue<pii,vector<pii>,comp> pq;
		int count=1;
		for(i=1;i<n;i++)
		{
			if(arr[i]==arr[i-1])
				count++;
			else
			{
				pq.push(make_pair(count,make_pair(count,0)));
				//cout<<count<<" ";
				count=1;
			}
		}
		int flag=0;
		//cout<<count<<endl;
		pq.push(make_pair(count,make_pair(count,0)));
		while(1)
		{
			if(!k)
				break;
			pii a=pq.top();
			if(a.first==2)
			{
				flag=1;
				break;
			}
			pq.pop();
			pii b=pq.top();
			while(k)
			{
				int a_sf=a.second.first;
				int a_num=a.second.second;
				int b_f=b.first;
				int val=a_sf-(a_num+1);
				//cout<<"A_sf "<<a_sf<<" A_num "<<a_num<<" Val "<<val<<endl;
				float new_num=a_num+2;
				float f_val=val;
				float extra=f_val/new_num;
				int new_val=ceil(extra);
				//cout<<"New_val "<<new_val<<endl;
				k--;
				a.second.second++;
				a.first=new_val;
				if(new_val<b_f || new_val==2)
					break;
			}
			//cout<<a.first<<" "<<a.second.first<<" "<<a.second.second<<endl;
			//cout<<"Pushed: "<<a.first<<" "<<a.second.first<<" "<<a.second.second<<endl;
			pq.push(a);
		}
		if(flag)
			printf("2\n");
		else
		{
			pii ans=pq.top();
			printf("%d\n",ans.first);
		}
		//cout<<"Final queue: ";
		/*while(!pq.empty())
		{
			pii abc=pq.top();
			cout<<abc.first<<" ";
			pq.pop();
		}
		cout<<endl;*/
	}
	return 0;
}