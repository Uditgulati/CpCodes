#include<iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int num,len;
		scanf("%d%d",&num,&len);
		int n=num*len;
		int arr[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int win[num]={0};
		int check=0;
		int count=0,index=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i])
				count++;
			if((i+1)%len==0)
			{
				win[index]=count;
				if(count>len/2)
					check++;
				count=0;
				index++;
			}
		}
		if(check>num/2)
			goto END;
		int j;
		for(j=0;j<len;j++)
		{
			int var=j;
			for(int i=0;i<num;i++)
			{
				int cur_val=arr[var];
				win[i]-=cur_val;
				if(i==0)
					win[num-1]+=cur_val;
				else
					win[i-1]+=cur_val;
				var+=len;
			}
			check=0;
			for(int i=0;i<num;i++)
				if(win[i]>len/2)
					check++;
			if(check>num/2)
				break;
		}
		if(j==len)
			printf("0\n");
		else
			END:printf("1\n");
	}
	return 0;
}

