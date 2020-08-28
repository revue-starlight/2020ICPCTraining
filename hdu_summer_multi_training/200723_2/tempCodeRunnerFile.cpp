#include <bits/stdc++.h>
using namespace std;
const int M=2e5+10,N=1e5+10;
int f[N],fa[N],v[M<<1],nxt[M<<1],ed,g[N],T,n,m,wake[N],a[N],q[N];
long long ans;  
int F(int x){return f[x]==x?x:x=f[x];}
int add(int x,int y){v[ed++]=y;nxt[ed]=g[x];g[x]=ed;}
bool cmp(int x,int y){return a[x]>a[y];}
int main(){
    cin>>T;
    ios::sync_with_stdio(false);
    while (T--){
        cin>>n>>m;
        for (int i=1;i<=n;i++) {cin>>a[i]; q[i]=f[i]=i; g[i]=fa[i]=wake[i]=0;} ed=0;
        for (int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            add(x,y); add(y,x);
        }
        sort(q+1,q+n+1,cmp);
        for (int i=1;i<=n;i++){
            int x=q[i];
            wake[x]=1;
            for (int j=g[x];j;j=nxt[j]){
                int y=v[j];
                if (!wake[j]) continue;
                y=F(y);
                if (x==y) continue;
                fa[y]=f[y]=x;
            }
        }
        ans=0;
        for (int i=1;i<=n;i++) ans+=a[i]-a[fa[i]];
        cout<<ans<<endl;
    }
}