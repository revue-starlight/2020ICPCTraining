#include <bits/stdc++.h>
#define MAXN 2000001
#define ll long long
using namespace std;
ll t[MAXN],a[MAXN],add[MAXN],n,m;
inline ll num(string s){
    ll len=s.length(),res=0;
    for (ll i=len-1;i>=0;i--){
        res=res*10+(s[i]-48);
    }
    return res;
}
inline ll ls(ll x) {return x<<1;}
inline ll rs(ll x) {return x<<1|1;}
void build(ll l,ll r,ll p){
    if (l==r){
        t[p]=a[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(l,mid,ls(p));
    build(mid+1,r,rs(p));
    t[p]=t[ls(p)]+t[rs(p)];
}
inline void pushdown(ll l,ll r,ll p){
    if (add[p]==0) return;
    add[ls(p)]+=add[p];
    add[rs(p)]+=add[p];
    ll mid=(l+r)>>1;
    t[ls(p)]+=(mid-l+1)*add[p];
    t[rs(p)]+=(r-mid)*add[p];
    add[p]=0;
}

inline void updata(ll l,ll r,ll tl,ll tr,ll k,ll p){
    if (tl<=l && r<=tr){
        t[p]+=k*(r-l+1);
        return;
    }
    pushdown(l,r,p);
    ll mid=(l+r)>>1;
    updata(l,mid,tl,tr,k,ls(p));
    updata(mid,r,tl,tr,k,rs(p));
    t[p]=t[ls(p)]+t[rs(p)];
}

inline ll query(ll l,ll r,ll tl,ll tr,ll p){
    if (tl<=l && r<=tr){
        return t[p];
    }
    pushdown(l,r,p);
    ll mid=(l+r)>>1,res=0;
    res+=query(l,mid,tl,tr,ls(p));
    res+=query(mid+1,r,tl,tr,rs(p));
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll tmp,n;
    cin>>tmp;
    for (ll CASE=1;CASE<=tmp;CASE++){
        cin>>n;
        for (ll i=1;i<=n;i++) cin>>a[i];
        for (ll i=1;i<=n*4+1;i++) {t[i]=0; add[i]=0;}
        build(1,n,1);
        string s1,s2,s3;
        while (cin>>s1>>s2>>s3){
            if (s1=="End")break;
            ll tl=num(s2),tr=num(s3);
            if (s1=="Query") cout<<query(1,n,tl,tr,1)<<endl;
            else if (s1=="Add") updata(1,n,tl,tr,1,1);
            else if (s1=="Sub") updata(1,n,tl,tr,-1,1);
        }
    }
}