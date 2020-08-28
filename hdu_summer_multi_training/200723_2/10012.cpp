#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define ll long long
const ll M=2e5+10,N=1e5+10;
ll i,j,x,y,f[N],fa[N],v[M<<1],nxt[M<<1],ed,g[N],T,n,m,wake[N],a[N],q[N],ans;  
inline void add(ll x,ll y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
inline bool cmp(ll x,ll y){return a[x]>a[y];}
ll F(ll x){return f[x]==x?x:f[x]=F(f[x]);}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>T;
    while (T--){
        cin>>n>>m;
       for(ed=0,i=1;i<=n;i++){
      cin>>a[i];
      q[i]=f[i]=i;
      g[i]=fa[i]=wake[i]=0;
    }
        while (m--){
            cin>>x>>y;
            add(x,y); add(y,x);
        }
        sort(q+1,q+n+1,cmp);
        for (i=1;i<=n;i++){
            x=q[i];
            wake[x]=1;
            for (j=g[x];j;j=nxt[j]){
                y=v[j];
                if (!wake[y]) continue;
                y=F(y);
                if (x==y) continue;
                fa[y]=f[y]=x;
            }
        }
        for (ans=0,i=1;i<=n;i++) ans+=a[i]-a[fa[i]];
        cout<<ans<<endl;
    }
}