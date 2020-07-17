#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll ksm(long long int a, long long int k)
{
    long long int ans = 1;
    a %= MOD;
    while(k)
    {
        if(k % 2) ans *= a;
        a = (a * a) % MOD;
        k /= 2;
        ans %= MOD;
    }
    return ans;
}
int main(){
    ll a,b,k,c;
    cin>>a>>b>>k>>c;
    if (c!=a && c!=b) {cout<<0<<endl; return 0;}
    if (a==b) {cout<<k<<endl; return 0;}
    else{
    ll ans=(ksm(2,k-1)*k)%MOD;
    cout<<ans<<endl;
    }
    return 0;
}