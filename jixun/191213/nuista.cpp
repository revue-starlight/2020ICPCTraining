#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 1001
#define MAXM 100001
using namespace std;
int cnt=0,head[MAXN],dis[MAXN],wishes[MAXN];
struct node{
    int u,v,w,next;
}edge[MAXM];


void build(int u,int v,int w)
{
    cnt++; edge[cnt].u=u; edge[cnt].v=v; edge[cnt].w=w; edge[cnt].next=head[u]; head[u]=cnt;
}

queue <int> q;

int main()
{

    int t,s,d;
    while(cin>>t>>s>>d)
    {
       memset(head,0,sizeof(head)); cnt=0; memset(wishes,0,sizeof(wishes));
    for (int i=1;i<=t;i++)
    {
        int aa,bb,cc;
        cin>>aa>>bb>>cc;
        build(aa,bb,cc); build(bb,aa,cc);
    }
    
    for (int i=1;i<=1000;i++) dis[i]=0x3f3f3f3f;
    for (int i=1;i<=s;i++)
    {
        int pp;
        cin>>pp; q.push(pp);
        dis[pp]=0;
    }
    for (int i=1;i<=d;i++){int pp; cin>>pp; wishes[i]=pp;}


    while (!q.empty())
    {
        int tmp=q.front(); q.pop();
        for (int i=head[tmp];i;i=edge[i].next)
        {
            if (edge[i].w+dis[tmp]<dis[edge[i].v])
            {
                dis[edge[i].v]=edge[i].w+dis[tmp];
                q.push(edge[i].v);
            }
        }
    }
    int minn=0x3f3f3f3f;
    for (int i=1;i<=d;i++)
    {
        if (dis[wishes[i]]<minn) minn=dis[wishes[i]];}
        
    cout<<minn<<endl;
    }
}