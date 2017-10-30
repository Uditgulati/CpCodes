#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
	int n,m;
	scanf("%d",&n);
	int lef_n[n],rig_n[n];
	for(int i=0;i<n;i++)
		scanf("%d%d",&lef_n[i],&rig_n[i]);
	scanf("%d",&m);
	int lef_m[m],rig_m[m];
	for(int i=0;i<m;i++)
		scanf("%d%d",&lef_m[i],&rig_m[i]);
	int l1,r1,l2,r2;
	r1=rig_n[0];
	for(int i=1;i<n;i++)
		if(rig_n[i]<r1)
			r1=rig_n[i];
	l1=lef_m[0];
	for(int i=1;i<m;i++)
		if(lef_m[i]>l1)
			l1=lef_m[i];
	ll ans1=(ll)(l1-r1);
	r2=rig_m[0];
	for(int i=1;i<m;i++)
		if(rig_m[i]<r2)
			r2=rig_m[i];
	l2=lef_n[0];
	for(int i=1;i<n;i++)
		if(lef_n[i]>l2)
			l2=lef_n[i];
	ll ans2=(ll)(l2-r2);
	ll ans=max(ans1,ans2);
	if(ans<0)
		ans=0;
	cout<<ans<<endl;
	return 0;
}