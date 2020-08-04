#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
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
int main(){
    for (ll i=1;i<mod;i++){
        if ((i*i)%mod==5)
            cout<<i<<endl;
    }
    
}