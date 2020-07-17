#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000
struct node{
    int u,v,next;
}edge[MAXN];
queue <int> q;
int dis[MAXN];
int head[MAXN],cnt;
bool inq[MAXN];
void build(int u,int v)
{
    edge[++cnt].u=u; edge[cnt].v=v; edge[cnt].next=head[u]; head[u]=cnt;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int xx,yy;
        cin>>xx>>yy;
        build(xx,yy);
    }
    q.push(1);
    for (int i=1;i<=n;i++) dis[i]=1;
    while (!q.empty())
    {
        int tmp;
        tmp=q.front(); q.pop();
        inq[tmp]=0;
        for (int i=head[tmp];i;i=edge[i].next)
        {
            if (dis[edge[i].v]<dis[edge[i].u]+1)
            {
                dis[edge[i].v]=dis[edge[i].u]+1;
                if (!inq[tmp]) {inq[edge[i].v]=1; q.push(edge[i].v);}
            }
        }
    }
    for (int i=1;i<=n;i++) cout<<dis[i]<<endl;
return 0;
}