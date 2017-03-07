#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<pair<int,int> > vec;
	vector<int> ind;
	int a,b,count=0,index=0;
	scanf("%d",&a);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&b);
		if(a==b)
			count++;
		else
		{
			vec.push_back(make_pair(a,count+1));
			ind.push_back(index);
			count=0;
			a=b;
			index=i;
		}
	}
	if(n==1)
		vec.push_back(make_pair(a,count+1));
	else
		vec.push_back(make_pair(b,count+1));
	ind.push_back(index);
	int len=vec.size();
	int maxi[len]={0};
	int maxim=0;
	for(int i=len-1;i>=0;i--)
	{
		if(vec[i].second>maxim)
			maxim=vec[i].second;
		maxi[i]=maxim;
	}
	//for(int i=0;i<len;i++)
	//	cout<<ind[i]<<" "<<vec[i].first<<" "<<vec[i].second<<" "<<maxi[i]<<endl;
	while(m--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		l--;
		r--;
		vector<int>::iterator up;
		up=lower_bound(ind.begin(),ind.end(),l);
		int pos=(up-ind.begin());
		int current=ind[pos];
		if(pos==len)
		{
			if(n-l>=k)
				printf("%d\n",vec[pos-1].first);
			else
				printf("-1\n");
			continue;
		}
		if(current-l>=k)
		{
			printf("%d\n",vec[pos-1].first);
			continue;
		}
		int i,last=0,found=0;
		//cout<<"pos "<<pos<<" cur "<<current<<endl;
		int pos1;
		if(pos!=0)
			pos1=pos-1;
		else
			pos1=pos;
		if(maxi[pos1]<k)
		{
			printf("-1\n");
			continue;
		}
		for(i=pos;i<len;i++)
		{
			int consec=vec[i].second;
			int temp=r-ind[i]+1;
			if(ind[i]>r)
				break;
			if(temp<consec)
				consec=temp;
			if(consec>=k)
			{
				printf("%d\n",vec[i].first);
				found=1;
				break;
			}
		}
		if(found==0)
			printf("-1\n");
	}
	return 0;
}

