#include <iostream>
using namespace std;
#define maxn 400015
#define mod 1000000007
#define ll long long
ll lj[maxn];
ll ans=0;
int main(){
    lj[0]=0;
    ll n;
    cin>>n;
    char ch;
    getchar();
    for (ll i=1;i<=n;i++){
        scanf("%c",&ch);
        if (ch=='0') lj[i]=lj[i-1];
        else lj[i]=i;
    }

    for (ll i=1;i<=n;i++){
        ll ans1=((  (  ( ((2*i-lj[i]+1)%mod) * (lj[i]%mod) % mod )/2)%mod ) *lj[i])%mod;
        ans=(ans1+ans)%mod;
    }
    cout<<ans<<endl;;
    return 0;
}