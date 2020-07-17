#include <bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w,next;
}edge[200001];

struct node2{
    int u,w;
    bool operator < (const node2& b) const{return w>b.w;}
};
int b[100001];
int head[100001];
int dis[100001];
int cnt=1;
priority_queue <node2> q;

void build(int u,int v,int w)
{
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt; cnt++;
}

int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    for (int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        build(a,b,c);
    }
    for (int i=1;i<=n;i++) dis[i]=1000000009;
    dis[s]=0;
    node2 tmpp;
    tmpp.u=s; tmpp.w=0;
    q.push(tmpp);
    while (!q.empty())
    {
        node2 tmp;

        tmp=q.top(); q.pop();
        if (b[tmp.u]) continue;
        b[tmp.u]=1;
        for (int i=head[tmp.u];i;i=edge[i].next)
        {
            if (edge[i].w+dis[edge[i].u]<dis[edge[i].v]) 
            {
                dis[edge[i].v]=edge[i].w+dis[edge[i].u];
                node2 tmpp; tmpp.u=edge[i].v; tmpp.w=dis[edge[i].v];
                q.push(tmpp);//更新后的距离推进去
            }
        }

    }
    for (int i=1;i<=n;i++) cout<<dis[i]<<" ";

}