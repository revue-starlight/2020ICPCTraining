#include <bits/stdc++.h>
#define ll long long
#define MAXN 400001
using namespace std;
ll t[MAXN],tagmul[MAXN],tagadd[MAXN],a[MAXN],p;

inline ll rs(ll pos){ return pos>>1|1;}
inline ll ls(ll pos){ return pos>>1;}

void build(ll l,ll r,ll pos)
{
    if (l==r) t[pos]=a[l];
    else{
        tagmul[pos]=1;
        tagadd[pos]=0;
        ll mid=(l+r)>>1;
        build(l,mid,ls(pos));
        build(mid+1,r,rs(pos));
        t[pos]=t[ls(pos)]+t[rs(pos)];
    }
}
inline void push_down(ll l,ll r,ll pos){
    ll mid=(l+r)>>1;
    if (tagadd[pos]=0 && tagmul[pos]==1) return;
        t[rs(pos)]=(t[rs(pos)]*tagmul[pos]);
        t[rs(pos)]=(t[rs(pos)]+(r-mid)*tagadd[pos])%p;
        t[ls(pos)]=(t[ls(pos)]*tagmul[pos]);
        t[ls(pos)]=(t[ls(pos)]+(mid-l+1)*tagadd[pos])%p; //左儿子右儿子本身向下搞左儿子右儿子继承花呗
        tagmul[rs(pos)]*=tagmul[pos]; //* 向下迭代
        tagmul[rs(pos)]%=p;
        tagmul[ls(pos)]*=tagmul[pos];
        tagmul[ls(pos)]%=p;

        tagadd[rs(pos)]=tagadd[pos]*tagmul[pos]+tagadd[rs(pos)]; //+ 向下迭代
        tagadd[rs(pos)]%=p;
        tagadd[ls(pos)]+=tagadd[pos]*tagmul[pos]+tagadd[ls(pos)];
        tagadd[ls(pos)]%=p;
        tagadd[pos]=0; tagmul[pos]=1;
        //左右先×再+
}

inline void update_add(ll l,ll r,ll tl,ll tr,ll k,ll pos)
{
    int mid=(l+r)>>1;
    if (tl<=l && r<=tr){
        t[pos]+=(r-l+1)*k;
        tagadd[pos]+=k;
        return;
    }
    push_down(l,r,pos);
    if (tl<=mid) update_add(l,mid,tl,tr,k,ls(pos));
    if (tr>mid) update_add(mid+1,r,tl,tr,k,rs(pos));
    t[pos]=t[ls(pos)]+t[rs(pos)];
}

inline void update_mul(ll l,ll r,ll tl, ll tr,ll k,ll pos)
{
    int mid=(l+r)>>1;
    if (tl<=l && r<=tr){
        t[pos]*=k;
        tagadd[pos]*=k;
        tagmul[pos]*=k;
        return;
    }

    push_down(l,r,pos);
    if (tl<=mid) update_mul(l,mid,tl,tr,k,ls(pos));
    if (tr>mid) update_mul(mid+1,r,tl,tr,k,rs(pos));
    t[pos]=t[ls(pos)]+t[rs(pos)];
}

ll query(ll l,ll r,ll tl,ll tr,ll pos)
{
    int mid=(l+r)>>1;
    if (tl<=l && r<=tr){
        return t[pos];
    }
    ll res=0;
    push_down(l,r,pos);
    if (tl<=mid) res+=query(l,mid,tl,tr,pos);
    if (tr>mid) res+=query(mid+1,r,tl,tr,pos);
    return pos;
}
int main()
{
    int n,m;
    cin>>n>>m>>p;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++){
        int tmp;
        ll x,y,k;
        cin>>tmp;
        if (tmp==1)
        {
           cin>>x>>y>>k;
            update_mul(1,n,x,y,k,1);
        }
        if (tmp==2){
          cin>>x>>y>>k;
            update_add(1,n,x,y,k,1);
        }
        if (tmp==3){
            cin>>x>>y;
            printf("%lld\n",query(1,n,x,y,1));
        }
    }
    return 0;
}