#include <bits/stdc++.h>
using namespace std;
int dp[101][101],maze[101][101];
int n,m;
bool judge(int i,int j){
    if (i<=0 || i>n || j<=0 || j>m) return 0;
    return 1;
}
int dfs(int x,int y){
    const int fx[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    if (dp[x][y]) return dp[x][y];
    int ret=1;
    for (int i=0;i<4;i++)
    {
        int xx=x+fx[i][0];
        int yy=y+fx[i][1];
        if (maze[xx][yy]<maze[x][y] && judge(xx,yy)) ret=max(dfs(xx,yy)+1,ret);
    }
    dp[x][y]=ret;
    return ret;
}
int main(){
    while (cin>>n>>m){
        memset(dp,0,sizeof(dp));
        memset(maze,0,sizeof(maze));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) cin>>maze[i][j];
        int res=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++){
                int l=dfs(i,j);
                if (res<l) res=l;
            }
        cout<<res<<endl;
    }
}