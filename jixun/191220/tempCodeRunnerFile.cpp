#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;
struct node{
    int v,u,next;
}edge[MAXN];
int tot=0,dis[MAXN],a[MAXN],head[MAXN];
void build(int u,int v)
{
    edge[++tot].u=u; edge[tot].v=v; edge[tot].next=head[u]; head[u]=tot;
}
int main()
{
    int n,maxx=0,imax;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]>maxx) {imax=i; maxx=a[i];}
    }

    for (int i=1;i<n;i++)
    {
        int xx,yy;
        cin>>xx>>yy;
        build(xx,yy);
        build(yy,xx);
    }
    stack <int> ss_max;
    stack <int> s_max;
    stack <int> a_max;

    for (int i=1;i<=n;i++)
    {
        if (a[i]==maxx && i!=imax) ss_max.push(i);
        if (a[i]==maxx-1) s_max.push(i);
    }
// dijkstra
    queue <int> q;
    q.push(imax); dis[imax]=0;
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        if (dis[x]==2) break;
        for (int i=head[x];i;i=edge[i].next)
        {
            if (dis[edge[i].v]==0 && edge[i].v!=imax)
            {
            q.push(i);
            dis[edge[i].v]=dis[x]+1;
            }
        }
    }
    while (!ss_max.empty())
    {
        if (dis[ss_max.top()]>=2) {cout<<maxx+2<<endl; return 0;}
        if (ss_max.empty()) {cout<<maxx+1<<endl; return 0;}
        ss_max.pop();
    }
    while (!s_max.empty())
    {
        if (dis[s_max.top()]>=2) {cout<<maxx+1<<endl; return 0;}
        s_max.pop();
    }

    cout<<maxx<<endl;
    return 0;
}