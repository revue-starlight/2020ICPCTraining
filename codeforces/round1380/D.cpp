#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=4e6+10;
    ll a[maxn];
ll quickpowmod(ll a,ll b,ll mod) {
    ll ans=1;
    while(b) {
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
int main()
{   
    ll p=998244353;
    a[1]=1;
    for (int i=2;i<maxn;i++)
        a[i]=(a[i-1]*i) % p ;
    ll n;
    while (cin>>n){
    ll aa,bb;
    aa=(a[n]*a[n])%p;
    bb=(a[2*n+1]);
    ll inva=quickpowmod(bb,p-2,p);
    cout<<(aa*inva)%p<<endl;
    }
    return 0;
}