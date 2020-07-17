#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define MAXM 10001
int head[MAXN],cnt,fa[MAXN];
struct node{
    int u,v,next,w;
    bool operator <(const node &b) const{return w>b.w;}
}edge[MAXM*2];
priority_queue <node> q;
void build(int u,int v,int w)
{cnt++; edge[cnt].u=u; edge[cnt].v=v; edge[cnt].w=w; edge[cnt].next=head[u]; head[u]=cnt;}
int find(int x)
{
    while (x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}

int main()
{
    int n,m,k,ans=0,s=0;
    cin>>n>>m;
    k=1;
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=m;i++)
        {int xx,yy,zz; cin>>xx>>yy>>zz; build(xx,yy,zz); build(yy,xx,zz);}
    for (int i=1;i<=m*2;i++) q.push(edge[i]);
    while (!q.empty())
    {
        node t=q.top(); q.pop();
        int eu=find(t.u); int ev=find(t.v);
        if (eu==ev) continue;
        s++;
        ans+=t.w;
        fa[ev]=eu;
        if (s==n-k) break;
    } 
    if (s!=n-k) cout<<"No Answer"; else cout<<ans<<endl;
}