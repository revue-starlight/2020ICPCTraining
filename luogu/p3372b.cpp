#include <bits/stdc++.h>
#define MAXN 407
#define MAXM 407
#define ll long long
using namespace std;
ll t[MAXM],a[MAXN],tag[MAXN];

inline ll rs(ll pos){return (pos<<1|1);}
inline ll ls(ll pos){return pos<<1;}

void push_up(int pos){
    t[pos]=t[ls(pos)]+t[rs(pos)];
}
void build(ll l,ll r,ll pos){
    if (l==r) {t[pos]=a[l]; return;}
    ll mid=(l+r)>>1;
    build (l,mid,ls(pos));
    build (mid+1,r,rs(pos));
    push_up(pos);
}
inline void f(ll l,ll r,ll k,ll pos)
{
    tag[pos]=tag[pos]+k;
    t[pos]=t[pos]+k*(r-l+1);
}

inline void push_down(ll l,ll r,ll pos){
    ll mid=(l+r)>>1;
    f(l,mid,tag[pos],ls(pos));
    f(mid+1,r,tag[pos],rs(pos));
    tag[pos]=0;
}
inline void update(ll l,ll r,ll tl,ll tr,ll pos,ll k)
{
    if (tl<=l&&r<=tr){
        t[pos]+=k*(r-l+1);
        tag[pos]+=k;
        return;
    }
    push_down(l,r,pos);
    ll mid=(l+r)>>1;
    if (tl<=mid) update(l,mid,tl,tr,ls(pos),k);
    if (tr>mid) update(mid+1,r,tl,tr,rs(pos),k);
    push_up(pos);
}
ll query(ll l,ll r,ll tl,ll tr,ll pos){
    ll ans=0;
    if (tl<=l && r<=tr) return t[pos];
    ll mid=(l+r)>>1;
    push_down(l,r,pos);
    if (tl<=mid) ans+=query(l,mid,tl,tr,ls(pos));
    if (tr>mid) ans+=query(mid+1,r,tl,tr,rs(pos));
    return ans;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,n,1);
    for (int i=1;i<=m;i++)
    {
        ll res;
        scanf("%lld",&res);
        if (res==1){
            ll x,y,k;
            scanf("%lld%lld%lld",&x,&y,&k);
            update(1,n,x,y,1,k);
        }
        else{
            ll x,y;
            cin>>x>>y;
            printf("%lld\n",query(1,n,x,y,1));
        }
    }
    return 0;
}