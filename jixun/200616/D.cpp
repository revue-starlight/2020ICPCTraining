#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=5005;
vector <int> vec[maxn];
int deg[maxn];
int tardeg[maxn];
int n,m;
int ans[maxn];
struct node{
    int id;
};
void solve(){
    int k=0;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for (int i=1;i<=n;i++) cin>>tardeg[i];
    queue <node> q[2];
    for (int i=1;i<=n;i++){
        if (tardeg[i]==1){
        node x;
        x.id=i;
        q[1].push(x);
        }
    }
    int tmp=1;
    bool bo=true;
    while (!q[tmp%2].empty()){
        node x=q[tmp%2].front(); q[tmp%2].pop();
        ans[++k]=x.id;
        if (tardeg[x.id]!=tmp) {bo=false; break;}
        for (int i=0;i<vec[x.id].size();i++) {
            deg[vec[x.id][i]]--; 
            if (deg[vec[x.id][i]]==1){
                node t;
                t.id=vec[x.id][i];
                q[(tmp+1)%2].push(t);
                deg[vec[x.id][i]]=INT_MAX;
            }
        }
        if (q[tmp%2].empty()) tmp++;
    }
    
    if (bo) for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    else cout<<"-1";
    
}
int main(){
    solve();
    return 0;
}