#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+9;
const ll N = 1e5+5,A=691504013,B=305495997,D=276601605;
const ll K=1e5+5;
ll q[N],qb[N];
ll inv[K];
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
    int T;
    cin>>T;
    for (int i=1;i<=K;i++) inv[i]=ksm(i,mod-2);
    while (T--){
        int n,c,k;
        cin>>n>>c>>k;
        //make Q
        q[0]=1;
        for (int i=1;i<=k;i++){
            q[i]=q[i-1]*ksm(A,c);
            q[i]%=mod;
        }
        qb[k]=1;
        for (int i=k-1;i>=0;i--){
            qb[i]=qb[i+1]*ksm(B,c);
            qb[i]%=mod;
        }
        for (int i=0;i<=k;i++)
        q[i]=(q[i]*qb[i])%mod;
        bool bo=true;
        for (int i=k;i>=0;i--){
            if (!bo) q[i]=-q[i];
            if (bo) bo=false; else bo=true;
        }
        for (int i=1;i<=k;i++){
            q[i]=q[i]*(k-i+1) % mod;
            q[i]=q[i]*inv[i] % mod;
        }
        ll ans=0;
        for (int i=0;i<=k;i++){
            ans=ans+((ksm(q[i],n+1)-1)%mod*ksm(q[i]-1,mod-2)%mod)%mod;
            ans%=mod;
        }
        ans=ans*ksm(D,k);
        ans%=mod;
        if (ans<0) ans+=mod;
        cout<<ans<<endl;
    }
}