#include <iostream>
using namespace std;
int a[101][101];
int n;

void dfs(int x,int y,int k,int fx)
{
	a[x][y]=k;
	if (k==n*n) return;
	if (fx==1)
	{
		if (a[x+1][y]==0 && x+1<=n) dfs(x+1,y,k+1,1);
		else dfs(x,y-1,k+1,2);
	}
	if (fx==2)
	{
		if (a[x][y-1]==0 && y-1>=1) dfs(x,y-1,k+1,2);
		else dfs(x-1,y,k+1,3);
	}
	if (fx==3)
	{
		if (a[x-1][y]==0 && x-1>=1) dfs(x-1,y,k+1,3);
		else dfs(x,y+1,k+1,4);
	}
	if (fx==4)
	{
		if (a[x][y+1]==0 && y+1<=n) dfs(x,y+1,k+1,4);
		else dfs(x+1,y,k+1,1);
	}
}

int main()
{
	while (cin>>n)
	{
		for (int i=1;i<=100;i++)
			for (int j=1;j<=100;j++) a[i][j]=0;
		dfs(1,n,1,1);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++) cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}