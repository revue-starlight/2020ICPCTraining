#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ksm(ll a,ll x,ll mod){
    ll res=1;
    while (x){
        if (x&1) res=res*a % mod;
        a=a*a % mod;
        x/=2;
    }
    res=res%mod;
    return res;
}
int main(){
    ll a,x,mod;
    cin>>a>>x>>mod;
    cout<<a<<"^"<<x<<" mod "<<mod<<"="<<ksm(a,x,mod)<<endl;
}