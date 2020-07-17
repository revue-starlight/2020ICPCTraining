#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXM 300005
struct node{
    int u,v,w,next;
}edge[MAXM];

int cnt=0,head[MAXN];
queue <int> q;

void build (int u,int v,int w)
{
    edge[++cnt].u=u;edge[cnt].v=v; edge[cnt].w=w; edge[cnt].next=head[u]; head[u]=cnt;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        int xx,yy,ww;
        cin>>xx>>yy>>ww;
        build(xx,yy,ww); build(yy,xx,ww);
    }
    int t=0;
    int dis[MAXN]; for (int i=1;i<=n;i++) dis[i]=0x3f3f3f3ff;
    q.push(1);
    int vis[MAXN]; for (int i=1;i<=n;i++) vis[i]=0;
    while (!q.empty())
    {
        int tmp=q.front(); q.pop();
        vis[tmp]=0;
        for (int i=head[tmp];i;i=edge[tmp].next)
            if (dis[tmp]+edge[i].w<dis[edge[i].v])
            {
                
                dis[edge[i].v]=dis[tmp]+edge[i].w;
                if (!vis[edge[i].v]) {vis[edge[i].v]=1; q.push(edge[i].v);}
            }
    }
}