#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define MAXM 100001
struct vil{
    int x,y,h;
}village[MAXN];
int head[MAXN],cnt,fa[MAXN];
struct node{
    int u,v,next;
    double w;
    bool operator <(const node &b) const{return w>b.w;}
}edge[MAXM*2];
priority_queue <node> q;

void build(int u,int v,double w)
{cnt++; edge[cnt].u=u; edge[cnt].v=v; edge[cnt].w=w; edge[cnt].next=head[u]; head[u]=cnt;}

int find(int x)
{
    while (x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}

int main()
{
    int n,m,k,s=0;
    double ans=0;
    cin>>n; k=1;
    for (int i=1;i<=n;i++){
        cin>>village[i].x>>village[i].y>>village[i].h;
    }
    for (int i=1;i<=n;i++) fa[i]=i; //union initialize

    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {double zz=sqrt((village[i].x-village[j].x)*(village[i].x-village[j].x)+(village[i].y-village[j].y)*(village[i].y-village[j].y))+(village[i].h-village[j].h)*(village[i].h-village[j].h);
         build(i,j,zz); build(i,j,zz);}

    for (int i=1;i<=cnt;i++) q.push(edge[i]);
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
    printf("%.2lf\n",ans);
}