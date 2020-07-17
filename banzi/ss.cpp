#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=10;
ll ksm(ll a,ll x){
    ll res=1;
    while (x){
        if (x&1) res=(res*a) % mod;
        a=(a*a) % mod;
        x/=2;
    }
    res=res%mod;
    return res;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<ksm(a,b)<<endl;
}