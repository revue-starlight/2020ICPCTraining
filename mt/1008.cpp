#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1000000009;
ll fib[100000];
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
map <ll,ll> mp;
int main(){
    int n,c,k;
    long long ans=0;
    cin>>n>>c>>k;
    fib[0]=0; fib[1]=1;
    for (int i=2;i<=n*c;i++){
        fib[i]=fib[i-1]+fib[i-2];
                cout<<"fib["<<i<<"]="<<fib[i]<<endl;
        fib[i]%=mod;
        if (i%c==0) {
                cout<<"N="<<i<<endl;
                ans=ans+ksm(fib[i],k);
                ans%=mod;
                mp[ans]++;
                cout<<ans<<" "<<mp[ans]<<endl;
                }
    }
}