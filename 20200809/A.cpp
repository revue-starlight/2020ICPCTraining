#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll ksm(ll a,ll x){
    ll res=1;
    while (x){
        if (x&1) res=res*a % mod;
        a=a*a % mod;
        x/=2;
    }
    res=res%mod;
    return res;
}

inline void solve(){
    ll m,p,q;
    cin>>m>>p>>q;
   ll x=m*100%mod;
    x=x*ksm(p,mod-2); x%=mod;
    x=x+mod-1; x%=mod;
    x=x*q; x%=mod;
    x=x*ksm(100,mod-2); x%=mod;
   // if (p*q>100*m*(q-p)){
    ll ans=m-x+mod;
    ans%=mod;
    cout<<ans<<endl;
    /*}
    else if (p*q==100*m*(q-p)) {
        cout<<0<<endl;
    }
    else {
        ll ans=x-m+mod;
        ans%=mod;
        cout<<ans<<endl;
    }*/
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}