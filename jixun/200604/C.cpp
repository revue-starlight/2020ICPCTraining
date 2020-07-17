#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100];
inline void solve(){
    ll n;
    cin>>n;
    int k=0;
    ll ans=0;
    while (n!=0){
        k++;
        if (n%2) ans+=a[k-1]+k;
        n/=2;
    }
    cout<<ans<<endl;
}
int main(){
    a[0]=0;
    a[1]=1;
    for (int i=2;i<=62;i++){
        a[i]=2*a[i-1]+i;
    }

    int t;
    cin>>t;
    while (t--){
        solve();
    }
}