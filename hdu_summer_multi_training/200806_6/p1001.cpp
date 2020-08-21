#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
const ll maxn=4e1+7;
ll frac[maxn];
ll midd[maxn];
ll comp[maxn];
ll a[maxn];
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

void solve(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {cin>>a[i]; frac[i]=midd[i]=comp[i]=0;}
    int mid=(n+1)/2;
    for (int i=1;i<=n;i++)
        frac[i]=ksm(i,mod-2);
    if (n%2==1) midd[mid]=frac[mid]; else midd[mid]=frac[mid]*2%mod;
    for (int i=mid-1;i>1;i--){
        midd[i]=midd[i+1]+frac[i]+frac[n-i+1];
        midd[i]%=mod;
    }
    for (int i=1;i<mid;i++){
        comp[i]=comp[i-1]+frac[i]*i;
        comp[i]%=mod;
        comp[n-i+1]=comp[n-i+2]+frac[n-i+1]*i;
        comp[n-i+1]%=mod;
    }
    ll ans=0;
    for (int i=1;i<mid;i++){
        ll tmp=0;
        tmp+=comp[i]+comp[n-i+1]+midd[i+1]*i;
        tmp*=(a[i]+a[n-i+1]);      
        tmp%=mod;
        ans+=tmp;
        ans%=mod;
    }
    if (n%2==0){
        ll k;
        k=comp[mid-1]+comp[mid+2]+mid*frac[mid]%mod+mid*frac[mid+1]%mod;
        k%=mod;
        k*=((a[mid]+a[mid+1])%mod);
        k%=mod;
        ans+=k;
        ans%=mod;
    }
    else{
        ll k;
        k=comp[mid-1]+comp[mid+1]+mid*frac[mid];
        k%=mod;
        k*=a[mid];
        k%=mod;
        ans+=k;
        ans%=mod;
    }
    ll s=n*(n+1)/2%mod;
    ans=ksm(s,mod-2)*ans;
    ans%=mod;
    cout<<ans<<endl;
    
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}