#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 1001
#define MAXM 100001
using namespace std;
int cnt,head[MAXN],dis[MAXN],pri[MAXN];
struct node{
    int u,v,w,p,next;
}edge[MAXM];

struct node2{
    int x,w,p;
     bool operator< (const node2& b) const {
        if (w==b.w) return p>b.p; else return w>b.w;
    }
};

queue <node2> q;
void build(int u,int v,int w,int p)
{
cnt++; edge[cnt].u=u; edge[cnt].v=v; edge[cnt].w=w; edge[cnt].p=p; edge[cnt].next=head[u]; head[u]=cnt;}


int main()
{
    
    while (1)
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    int n,m;
    cin>>n>>m;
    if (n==0 && m==0) return 0;
    cnt=0;
    memset(head,0,sizeof(head)); 
    for (int i=1;i<=m;i++)
    {
        int aa,bb,dd,pp;
        cin>>aa>>bb>>dd>>pp;
        build(aa,bb,dd,pp);
        build(bb,aa,dd,pp);
    }
    int s,t; cin>>s>>t;
    node2 tmp; 
    tmp.x=s; tmp.p=0; tmp.w=0; q.push(tmp);
    for (int i=1;i<=n;i++) dis[i]=0x3f3f3f3f; dis[s]=0;
    for (int i=1;i<=n;i++) pri[i]=0x3f3f3f3f; pri[s]=0;

    while (!q.empty())
    {
        node2 temp;
        temp=q.front(); q.pop();
        for (int i=head[temp.x];i;i=edge[i].next)
        {
            if (dis[temp.x]+edge[i].w<dis[edge[i].v])
             {  dis[edge[i].v]=dis[temp.x]+edge[i].w; 
                pri[edge[i].v]=pri[temp.x]+edge[i].p;
                node2 temp2; temp2.w=dis[temp.x]+edge[i].w; 
                temp2.x=edge[i].v;
                temp2.p=temp.p+edge[i].p;
                q.push(temp2);
            }
            else if (dis[temp.x]+edge[i].w==dis[edge[i].v] && pri[temp.x]+edge[i].p<pri[edge[i].v]) 
            {  dis[edge[i].v]=dis[temp.x]+edge[i].w; 
                pri[edge[i].v]=pri[temp.x]+edge[i].p;
                node2 temp2; temp2.w=dis[temp.x]+edge[i].w; 
                temp2.x=edge[i].v;
                temp2.p=temp.p+edge[i].p;
                q.push(temp2);
            }
        }
    }
    cout<<dis[t]<<" "<<pri[t]<<endl;
    }
}