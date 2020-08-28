#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll maxn=5e6+10;
const ll mod=1004535809;
ll fib[maxn]={1,1};
ll A[maxn],B[maxn],C[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i=2;i<=maxn;i++) fib[i]=(fib[i-1]+fib[i-2])%mod;
    ll T;
    cin>>T;
    while (T--){
        int alen,blen,clen;
        cin>>alen;
        for (int i=1;i<=alen;i++) cin>>A[i];
        cin>>blen;
        for (int i=1;i<=blen;i++) cin>>B[i];
        cin>>clen;
        for (int i=1;i<=clen;i++) cin>>C[i];
        ll a=0,b=0,c=0;
        for (int i=1;i<=alen;i++){
            if (A[i]) a=(a+fib[i]) % mod;
        }
        for (int i=1;i<=blen;i++){
            if (B[i]) b=(b+fib[i]) % mod;
        }
        ll ans=(a*b) % mod;
        for (int i=1;i<=clen;i++){
            if (C[i]) c=(c+fib[i]) % mod;
        }
        for (int i=1;i<=clen;i++){
            if (C[i]==0){
                if ( (c+fib[i])%mod == ans ) {
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
}