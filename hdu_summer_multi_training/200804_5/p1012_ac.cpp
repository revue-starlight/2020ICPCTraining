#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
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
    ll T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        if (n==1) {cout<<1<<endl; continue;}
        for (ll i=1;i<=n/2;i++) cout<<0<<" ";
        ll chushifenmu=ksm(2,n/2);
        chushifenmu%=mod;
        ll chushifenzi=1;
        cout<<(chushifenzi*ksm(chushifenmu,mod-2))%mod<<" "; //n/2+1
        ll fzk=n/2+1;
        ll fmk=2;
        for (int i=n/2+2;i<=n-1;i++){
        /*    cout<<"i="<<i<<endl;
            cout<<"fzk="<<fzk<<endl;
            cout<<"fmk="<<fmk<<endl;*/
            chushifenzi*=fzk;
            chushifenmu*=fmk;
           /* cout<<"fenzi:"<<chushifenzi<<endl;
            cout<<"fenmu:"<<chushifenmu<<endl;*/
            chushifenzi%=mod;
            chushifenmu%=mod;
            fzk+=1;
            fzk%=mod;
            fmk+=2;
            fmk%=mod;
            cout<<(chushifenzi*ksm(chushifenmu,mod-2))%mod<<" ";
        }
        cout<<(chushifenzi*ksm(chushifenmu,mod-2))%mod;
        cout<<endl;
    }
}