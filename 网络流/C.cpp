#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=1e2;
const int maxn=1e1;
struct node{
    int e,v,nxt;
}edge[maxm<<1];
int cnt,n;
inline void add_e(int u,int v,int w){
    edge[cnt].e=v;
    edge[cnt].v=w;
    edge[cnt].nxt=head[u];
    head[u]=cnt++;
}

struct NT_flows{
    int head[maxn],dis[maxn];
    bool bfs(){
        memset(dis,-1,sizeof(dis));
        dfs[1]=0;
        queue <int> q;
        q.push(1);
        while (!q.empty()){
            int r=q.front(); q.pop();
            for (int i=head[r];i!=-1;i=edge[i].nxt){
                int j=edge[i].e;
                if (dis[j]==-1 && edge[i].v){
                    dis[j]=dis[r]+1;
                    q.push(j);
                }
            }
        }
    }

    int dfs(int u,int flo){
        if (u==n) return flo;
        int delta=flo;
        for (int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].e;
            if (dis[v]==(dis[u]+1) && (edge[i].v)>0){
                if d=dfs(v,min(delta,edge[i].v));
                edge[i].v-=d;
                edge[i^1].v+=d;
                delta-=d;
                if (!delta) break;
            }
        }
        return flo-delta;
    }
    int dini(){
        int ans=0;
        while (bfs()){
            ans+=dfs(1,INF)
        }
        rturn ans;
    }
}
int32_t main(){

}