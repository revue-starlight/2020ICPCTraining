#include <bits/stdc++.h>
using namespace std;
queue <int> q;
struct node{
    int u,v,w,next;
}edge[20001];
int vis[1001],n,k;
int head[1001];
int dis[1001],cnt=0;
void build(int u,int v,int w)
{
    cnt++;
    edge[cnt].u=u; edge[cnt].v=v; edge[cnt].w=w;edge[cnt].next=head[u]; head[u]=cnt;
}

bool check(int x)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis)); dis[1]=0;
    while (!q.empty()) q.pop();
    q.push(1);/*WRONG 4 PUSH 0*/
    while (!q.empty())
    {
        int tt=q.front(); q.pop();
        vis[tt]=0; //tt means the point u
        for (int i=head[tt];i;i=edge[i].next)
        {
            /* use the w to do the exchange*/
            if (edge[i].w<=x)
            {
                if (dis[edge[i].u]<dis[edge[i].v])
                {
                    dis[edge[i].v]=dis[edge[i].u];
                    if (vis[edge[i].v]==0) /*WRONG 3 vis[edge[i].v]==1(ctrl+c v)*/
                        {
                            q.push(edge[i].v);
                            vis[edge[i].v]=1;
                        }
                }
            }
            else
            {//edge[i].w>x then the w=1;
                if (dis[edge[i].u]+1<dis[edge[i].v])
                {
                    dis[edge[i].v]=dis[edge[i].u]+1;
                    if (vis[edge[i].v]==0) /*WRONG 2 vis[edge[i].v]==1*/
                        {
                            q.push(edge[i].v);
                            vis[edge[i].v]=1;
                        }
                }
            }
        }
    }
    return dis[n]<=k; /* WRONG 1 return vis[n]<=k*/
}

int main()
{
    int p;
    cin>>n>>p>>k;
    for (int i=1;i<=p;i++)
    {
        int xx,yy,zz;
        cin>>xx>>yy>>zz;
        build(xx,yy,zz); build(yy,xx,zz);
    }
    
    int l=1,r=1000001;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (check(mid)) r=mid; else l=mid+1;
        if (l>1000000) {cout<<"-1"<<endl; return 0;}
    }
    cout<<l<<endl;
}


/*cyenQ*/