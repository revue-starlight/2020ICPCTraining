/* 20fen */
#include <bits/stdc++.h>
using namespace std;
int p[100005],head[100005];
struct node{
    int u,v,next;
}edge[500005];
int cnt=0;
void build (int u,int v)
{cnt++; edge[cnt].u=u; edge[cnt].v=v; edge[cnt].next=head[u]; head[u]=cnt;}
int dp[100005],vis[100005],ans=0;
void search(int x,int minn,int dpp)
{
    bool flag=true;
    vis[x]++;
    if (p[x]-minn>dpp) dpp=p[x]-minn;
    if (p[x]<minn) minn=p[x],flag=false;
    if (ans<dpp) ans=dpp;
    for (int i=head[x];i;i=edge[i].next)
    {
        if (vis[edge[i].v]!=2) search(edge[i].v,minn,dpp);
    }
    vis[x]--;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=1;i<=m;i++)
    {
        int xx,yy,zz;
        cin>>xx>>yy>>zz;
        build(xx,yy);
        if (zz==2) build(yy,zz);
    }
    search(1,0x3f3f3f3f,0);
    cout<<ans+1;
}