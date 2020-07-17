#include <bits/stdc++.h>
using namespace std;

const int N=5;
const int M=105;
int n,m,B[M],A[N][M];
int f[1<<N][M];
int main( )
{
  int i,j,k,t,z,r,u,G,T;
  cin>>T;
  while(T--)
    {
      cin>>n>>m;
      for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	  cin>>A[i][j];
      int S=(1<<n)-1;
      for(i=1;i<=m;i++)
	for(j=0;j<=S;j++)
	  f[j][i]=0;
      for(i=1;i<=m;i++)
	{
	  for(j=0;j<=S;j++)
	    {
	      for(k=j;;k=(k-1)&j)
		{
		  u=0;
		  for(t=0;t<n;t++)
		    {
		      r=0;
		      for(z=1;z<=n;z++)
			{
			  G=((z-1)+t)%n+1;
			  if(((1<<(G-1))&j)&&(!((1<<(G-1))&k)))
			    r+=A[z][i];
			}
		      u=max(u,r);
		    }
		  f[j][i]=max(f[j][i],f[k][i-1]+u);
		  if(!k) break;
		}
	    }
	}
      printf("%d\n",f[S][n]);
    }		  	      
  return 0;
}