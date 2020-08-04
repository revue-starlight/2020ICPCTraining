#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
const ll N=2000;     
ll prime[N] = {0},num_prime = 0;
int isNotPrime[N] = {1, 1};
void makeprime(){ 
        for(int i = 2 ; i < N ; i ++)         {              if(! isNotPrime[i])          prime[num_prime ++]=i;for(int j=0;j<num_prime&&i*prime[j]<N;j++)  {                 isNotPrime[i*prime[j]]=1;if(!(i % prime[j]))  break;
        }          
    }          
}
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
    makeprime();
    cin>>T;
    while (T--){
        int m,n;
        cin>>n>>m;
        if (m>=n) {cout<<"-1"<<endl; continue;}
        ll k=n;
        while (prime[k]>=m) k--;
        ll base=1;
        ll ans=1;
        for (int i=k;i>=0;i--)
        {
            ans=ans*pow(prime[i],base);
            ans%=mod;
            base=base*2;
        }
        cout<<ans<<endl;
    }
}