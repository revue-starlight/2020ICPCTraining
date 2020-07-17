#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200001
vector <int> vec[maxn];
int val[maxn],dis[maxn][maxn],n,ans[maxn ];
bool bo[maxn];
void search(int u,int now,int dist){
    int len=vec[now].size();
    for (int i=0;i<len;i++){
        if (dis[now][u] || dis[u][now]) continue;
        dis[u][vec[now][i]]=dist+dis[u][now]+dis[now][i];
        search(u,vec[now][i],dis[u][vec[now][i]]);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&val[i]);  
    for (int i=1;i<=n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        scanf("%d",dis[u][v]);
        dis[v][u]=dis[u][v];
        vec[u].push_back(v); vec[v].push_back(u);
    }

    for (int i=1;i<=n;i++){
        search(i,i,0);
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
        if (j==i) continue;
        else ans[i]+=(val[i]+val[j])*dis[i][j]
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";

}