#include <iostream>
using namespace std;
#define ll long long
const ll N = 3e5+100;
int nxt[N],head[N],tot,to[N],n,k,x,y,T;

inline void add_edge(int u,int v){
    tot++; nxt[tot]=head[u]; to[tot]=v; head[u]=tot;
}

void init(){
    memset(head,0,sizeof(head));
    memset(to,0,sizeof(to));
    memset(nxt,0,sizeof(nxt));
    tot=0;
}

void solve(){
    init();
    cin>>n>>k;
    for (int i=1;i<n;i++){
        cin>>x>>y;
        add_edge(x,y);
    }
    
    
}
int main(){
    cin>>T;
    while (T--) solve();
}