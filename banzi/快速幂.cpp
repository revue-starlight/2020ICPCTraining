#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
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
    cout<<3*ksm(2,mod-2,mod)%mod<<endl;
}