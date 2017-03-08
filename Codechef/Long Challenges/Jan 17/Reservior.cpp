#include<iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int arr[n][m];
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			for(int j=0;j<m;j++)
			{
				char a=s[j];
				if(a=='B')
					arr[i][j]=2;
				else if(a=='W')
					arr[i][j]=1;
				else
					arr[i][j]=0;
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<m;j++)
			{
				int a=arr[i][j];
				if(a==1)
				{
					if(j==0 || j==m-1 || i==n-1)
					{
						printf("no\n");
						goto END;
					}
					else if(arr[i][j-1]==0 || arr[i][j+1]==0)
					{
						printf("no\n");
						goto END;
					}
				}
				if(a==0 && i!=0 && (arr[i-1][j]==2 || arr[i-1][j]==1))
				{
					printf("no\n");
					goto END;
				}
			}
		}
		printf("yes\n");
		END:{}
	}
	return 0;
}
