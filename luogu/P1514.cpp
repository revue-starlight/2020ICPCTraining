#include <bits/stdc++.h>
using namespace std;
int height[2001][2002],dp[2001],fz[2001][2001],n,m;
bool flag[2001][2001];
bool theshittin[2001];
void dfs(int x,int y){
    const int fx[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    flag[x][y]=1;
        for (int i=0;i<4;i++)
        {
            int dx=x+fx[i][0],dy=y+fx[i][1];
            if (!flag[dx][dy] && height[dx][dy]<height[x][y] && dx>0 && dx<=n && dy>0 && dy<=m){
                dfs(dx,dy);
            }
        }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m+1;j++) fz[i][j]=0x3f3f3f3f;
        for (int i=1;i<=m+1;i++) dp[i]=0x3f3f3f3f;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) scanf("%d",&height[i][j]);
    
    queue <int> v;
    for (int i=1;i<=m;i++)
        if (height[1][i]>=height[1][i-1] && height[1][i]>=height[1][i+1]) v.push(i);
    while (!v.empty()){
        int q=v.front();v.pop();
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                flag[i][j]=0;
            flag[n][m+1]=0;
        dfs(1,q);
        int temp=1,l=0,r=0;
        while (temp<=m){
            while (flag[n][temp]!=1 && temp<=m) temp++;
            if (temp<=m) l=temp;
            if (temp>m) break;
            while (flag[n][temp]!=0 && temp<=m) temp++;
            r=temp-1;
            if (l!=0 && r!=0) {
                for (int i=l;i<=r;i++) theshittin[i]=1;
                for (int i=l;i<=r;i++)
                    for (int j=i;j<=r;j++)
                        fz[i][j]=1;
                if (l==1) for (int i=1;i<=r;i++) dp[i]=1;
            }
        }
    }
int cnt=0;
for (int i=1;i<=m;i++) if (theshittin[i]==0) cnt++;
if (cnt>0) {printf("0\n%d",cnt); return 0;}
    for (int i=1;i<=m;i++)
        for (int j=1;j<=i-1;j++)
        if (dp[i]>dp[j]+fz[j+1][i]) dp[i]=dp[j]+fz[j+1][i];
   printf("1\n%d\n",dp[m]);  
}