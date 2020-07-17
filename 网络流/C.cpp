#include <bits/stdc++.h>
using namespace std;
const int maxn=110;
const int maxm=1010;
int n,m,tot;
int custom_buy[maxn],c[maxm];
int head[maxn];
struct EDGE{
    int u,v,w,next;
}edge[maxn*maxm];
int heads[maxn];
void add_edge(int u,int v,int w){
    edge[tot].u=u; edge[tot].v=v; edge[tot].w=w; heads[u]=tot++;
}
vector <int> custom_num[maxn];
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++) cout<<c[i]<<endl;
    for (int i=1;i<=n;i++) {
        int k;
        cin>>k;
        while (k--){
            int x;
            cin>>x;
            custom_num[i].push_back(x);
            int floww=0;
            if (head[x]==0){
                floww+=c[x];
                head[x]=i;
            }
            else{
                add_edge(head[x],i,INT_MAX);
            }
            if (floww) add_edge(0,i,floww); 
        }
        cin>>custom_buy[i];
    }
    for (int i=1;i<=n;i++){
            add_edge(i,n+1,custom_buy[i]);
    }
// 网络流开始.
    int ans=0;
    while (bfs()){
        ans+=dfs(1,INF);
    }
    cout<<ans<<endl;
    return 0;
}