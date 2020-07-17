#include <bits/stdc++.h>
#define ll long long
#define MAXN 200001
using namespace std;
ll t[MAXN],a[MAXN],m,n;

inline ll ls(ll x){return x<<1;}
inline ll rs(ll x){return x<<1|1;}
void build(ll l,ll r,ll p){
    if (l==r){
        t[p]=a[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(l,mid,ls(p));
    build(mid+1,r,rs(p));
    t[p]=max(t[ls(p)],t[rs(p)]);
}

inline ll query(ll l,ll r,ll tl,ll tr,ll p){
    if (r<tl || l>tr) return 0;
    if (tl<=l && r<=tr) return t[p];
    ll mid=(l+r)>>1,res=0;
    return max(query(l,mid,tl,tr,ls(p)),query(mid+1,r,tl,tr,ls(p)));
}

inline void update(ll l,ll r,ll tmp,ll k,ll p){
    if (r==l && l==tmp) {
        t[p]=k;
    }
    ll mid=(l+r)>>1;
    if (mid>=tmp) update(l,mid,tmp,k,ls(p));
    else update(mid+1,r,tmp,k,rs(p));
    t[p]=max(t[ls(p)],t[rs(p)]);
}

int main(){
    while (cin>>n>>m){
        for (ll i=1;i<=m*4;i++) t[i]=0;
        for (ll i=1;i<=n;i++)   cin>>a[i];
        build(1,n,1);
        for (ll i=1;i<=m;i++){
            string s;
            ll xx,yy;
            cin>>s>>xx>>yy;
            if (s=="Q") cout<<query(1,n,xx,yy,1)<<endl;
            if (s=="U") update(1,n,xx,yy,1);
        }
    }
}