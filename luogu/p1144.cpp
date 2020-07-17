#include <bits/stdc++.h>
using namespace std;
int b[1000006];
struct node{
    int u,v,next;
}edge[4000006];
int head[1000006],ans[1000006];
int cnt=0;
struct node2{
    int x,level;
    
};

queue <node2> q;

void build(int x,int y){cnt++;edge[cnt].u=x;edge[cnt].v=y; edge[cnt].next=head[x];head[x]=cnt;}
int main()
{
    int n,m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        build(t1,t2);build(t2,t1);
    }
    node2 tmp; tmp.level=1; tmp.x=1;
    q.push(tmp);
    ans[1]=1;
    b[1]=1;
    while (!q.empty())
    {
        node2 k=q.front(); q.pop();
        for (int i=head[k.x];i;i=edge[i].next)
        {
            if (b[edge[i].v]==0 || b[edge[i].v]==k.level+1) 
            {   if (b[edge[i].v]==0) 
                {   b[edge[i].v]=k.level+1;
                    node2 tmpp; tmpp.level=k.level+1; tmpp.x=edge[i].v; 
                    q.push(tmpp);
                } 
            ans[edge[i].v]=(ans[edge[i].v]+ans[edge[i].u])%100003;} 
        }
    }
    for (int i=1;i<=n;i++)
    {
        cout<<ans[i]<<endl;
    }

}