#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e5+10;
struct node{
    ll l,r;
}a[maxn];
node ans[maxn];
inline void solve(){
    ll n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r;
    ans[n]=a[n];
    bool suc=true;
    
    for (int i=n;i>=1;i--){
        node tmp;
        tmp.l=ans[i].l-k; tmp.r=ans[i].r+k;
        ans[i-1].l=max(tmp.l,a[i-1].l),ans[i-1].r=min(a[i-1].r,tmp.r);
        if (ans[i-1].l>ans[i-1].r) {suc=false; break;}
    }
    for (int i=1;i<n;i++){
        node tmp;
        tmp.l=ans[i].l-k; tmp.r=ans[i].r+k;
        ans[i+1].l=max(tmp.l,ans[i+1].l),ans[i+1].r=min(ans[i-1].r,tmp.r);
        if (ans[i-1].l>ans[i-1].r) {suc=false; break;}
    }


    if (!suc) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for (int i=1;i<n;i++) cout<<ans[i].l;
        cout<<ans[n].l;
        cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll T;
    cin>>T;
    while (T--) solve();
}