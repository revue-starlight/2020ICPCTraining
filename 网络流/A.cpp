#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
int head[maxn],num_edge;
struct edges{
    int u,v,w,next;
}edge[maxn];
int dis[maxn];
void addedge(int u,int v,int w){
    edge[num_edge].u=u; edge[num_edge].v=v; edge[num_edge].w=w; edge[num_edge].next=head[u];
    head[u]=num_edge++;
}

bool bfs(){
    memset(dis,-1,sizeof(dis));
    dis[1]=0;
    queue <int> q; 
    while (!q.empty()){
        int x=q.front(); q.pop();
        for (int i=head[x];i;i=edge[i].next){
            int j=edge[i].v;
            if (dis[j]==-1 && edge[i].w)
            {
                dis[j]=dis[x]+1;
                q.push(j);
            }
        }
    }
    return dis[n]!=-1;
}

int dfs(int u,int flo){
    if (u==n) return flo;//流量，从1开始时是无限的，在不断dfs的过程中逐渐递减。
    int dlta=flo;//剩余残量
    for (int i=head[u];i!=1;i=edge[i].next){
        int v=edge[i].v;
        
        if ((dis[v]==dis[u]+1) && (edge[i].w>0)){
            int d=dfs(v,min(dlta,edge[v].w));//从v点向下走可允许通过的最大流量，比如A点是8，B点是6
            edge[i].w-=d; //这个边-=d
            edge[i^1].w+=d; //反向边+=d
            dlta-=d; //dlta-8,-6 等等等等等等等等
            if (dlta==0) break; //一滴不剩，地震所有路线可以全部跑光
        }
    }
    return flo-dlta; //原有多少人-还剩多少人。
}
int main(){
    int n,m,x;
    memset(head,0x3f,sizeof(head));
    cin>>n>>m>>x;
    for (int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        addedge(a,b,w); addedge(b,a,0);
    }
    //ahahahahaha 网络流这么简单啊 不就是一个bfs套一个dfs吗哇哈哈哈哈哈哈哈，我以为是什么奇技淫巧没想到是大水题啊w*N
    int ans=0;
    while (bfs()){
        ans+=dfs(1,9999999);
    }
    if(ans!=0)
      if(x%ans)printf("%d %d",ans,(x-(x%ans))/ans+1);
      else printf("%d %d",ans,x/ans);
    else printf("Orz Ni Jinan Saint Cow!");
}