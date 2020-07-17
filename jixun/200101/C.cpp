#include <bits/stdc++.h>
using namespace std;
#define MAXN 300007
struct node{
    int u,v,next;
}edge[MAXN];
int head[MAXN],n,w[MAXN],layer[MAXN],cnt;
bool b[MAXN];
void build(int x,int y)
{
    edge[++cnt].u=x; edge[cnt].v=y; edge[cnt].next=head[x]; head[x]=cnt;
}

int main()
{
    int maxx=-0x3f3f3f3f;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        if (maxx<w[i]) maxx=w[i];
    }
    queue <int> ss;
    queue <int> s;
    for (int i=1;i<=n;i++)
    {
        if (w[i]==maxx) ss.push(i);
        if (w[i]+1==maxx) s.push(i);
    }

    for (int i=1;i<n;i++)
    {
        int xx,yy;
        scanf("%d %d",&xx,&yy);
        build(xx,yy); build(yy,xx);
    }
    int ssize=ss.size(),size=s.size();
    queue <int> q;
    q.push(ss.front());
// here bfs
    for (int i=1;i<=n;i++)
        layer[i]=0x3f3f3f3f;
    layer[q.front()]=0;
    b[q.front()]=1;
    while (!q.empty()){
        int x=q.front(); q.pop();
        for (int i=head[x];i;i=edge[i].next){
            if (!b[edge[i].v]) layer[edge[i].v]=layer[x]+1;
            if (layer[edge[i].v]<2 && !b[edge[i].v]){b[edge[i].v]=1; q.push(edge[i].v);}
        }
    }
    if (ssize>1)
    {
        while (!ss.empty())
        {
            int x=ss.front(); ss.pop();
            if (layer[x]>1)
            {
                printf("%d\n",maxx+2);
                return 0;
            }
        }
        
            printf("%d\n",maxx+1); return 0;
    }
    else
    {
        while (!s.empty())
        {
            int x=s.front(); s.pop();
            if (layer[x]>1) {printf("%d\n",maxx+1); return 0;}
        }
        printf("%d\n",maxx);
        return 0;
    }

    return 0;
}
