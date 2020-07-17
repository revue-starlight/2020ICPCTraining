// Codeforces - Restore Permutation
#include <bits/stdc++.h>
using namespace std;
#define maxn 200001
#define ll long long
struct node{
    ll l,r,minn,lztag;
}tree[maxn*4];
ll ans[maxn];
inline ll lson(ll x){return x<<1;}
inline ll rson(ll x){return x<<1|1;}
inline void push_up(ll x){tree[x].minn=min(tree[lson(x)].minn,tree[rson(x)].minn);}
inline void push_down(ll x){
    if (tree[x].lztag){
        tree[lson(x)].minn-=tree[x].lztag; tree[rson(x)].minn-=tree[x].lztag;
        tree[lson(x)].lztag+=tree[x].lztag;tree[rson(x)].lztag+=tree[x].lztag;
        tree[x].lztag=0;
    }
}
void build(ll l,ll r,ll pos){
    tree[pos].l=l; tree[pos].r=r;
    if (l==r) {cin>>tree[pos].minn; return;}
    ll mid=(l+r)>>1;
    build(l,mid,lson(pos)); build(mid+1,r,rson(pos));
    push_up(pos);
}
inline void change(ll L,ll R,ll pos,ll val){//区间修改
    if (tree[pos].l >= L && tree[pos].r <= R) {tree[pos].minn-=val; tree[pos].lztag+=val;return;}
    push_down(pos);
    ll mid=(tree[pos].l+tree[pos].r)>>1;
    if (R<=mid) change(L,R,lson(pos),val);
    else if (L>mid) change(L,R,rson(pos),val);
    else change(L,R,lson(pos),val),change(L,R,rson(pos),val);
    push_up(pos); 
}

inline void updata(ll x,ll pos){
    if (tree[pos].l==tree[pos].r) {tree[pos].minn=1e18; return;}
    ll mid=(tree[pos].l+tree[pos].r)>>1;
    push_down(pos);
    if (x<=mid) updata(x,lson(pos));
    else updata(x,rson(pos));
    push_up(pos);
}

inline ll query(ll pos){
    if (tree[pos].l==tree[pos].r) return tree[pos].l;
    else{
        push_down(pos);
        if (tree[rson(pos)].minn==0) return query(rson(pos));
        else return query(lson(pos));
    }
}

int main(){
    ll n;
    cin>>n;
    build(1,n,1);
    for (ll i=1;i<=n;i++){
        ll x=query(1);
        ans[x]=i;
        updata(x,1);
        if (x!=n) change(x+1,n,1,i);
    }//一个一个找0,找到以后加入答案，后面的所有值全体-i
    for (ll i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;

}