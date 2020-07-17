#include <bits/stdc++.h>
using namespace std;
struct node{
    int u,w;
    bool operator<(const node&b) const{ return w>b.w;}
};
struct node2{
    int u,v,w,next;
}edge[100001];

priority_queue <node> q;

int head[101],ans;
int cnt=1;
void build(int u,int v,int w)
{
    edge[cnt].u=u; edge[cnt].v=v; edge[cnt].w=w; edge[cnt].next=head[u]; head[u]=cnt; cnt++;
}

int main()
{
    int n,start,end;
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>start>>end;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for (int j=1;j<=x;j++)
        {
            int v;
            cin>>v;
            if (j==1) build(i,v,0);
            else build(i,v,1);
        }
    }

node tmp; tmp.w=0; tmp.u=start; q.push(tmp);
bool bo[101];
memset(bo,0,sizeof(bo));
int dis[101];
memset(dis,0x3f,sizeof(dis));
dis[start]=0;
bool checker=0;
while (!q.empty())
{
    node tt;
    tt=q.top(); q.pop();
    if (bo[tt.u]) continue;
    if (tt.u==end) {ans=dis[tt.u]; checker=1; break;}
    bo[tt.u]=1;
    for (int i=head[tt.u];i;i=edge[i].next)
        if (edge[i].w+dis[tt.u]<dis[edge[i].v])
        {dis[edge[i].v]=edge[i].w+dis[tt.u]; node tt2; tt2.u=edge[i].v; tt2.w=dis[edge[i].v]; q.push(tt2);}
}
if (checker)
cout<<ans<<endl;
 else cout<<-1<<endl;   
}