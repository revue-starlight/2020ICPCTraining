#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 8006
const ll afjs=0x3f3f3f3f;
ll a[maxn],mp[maxn];
inline void solve(){
    int n;
    cin>>n;
    ll maxx=-afjs;
    ll minn=afjs;
    for (ll i=1;i<=n;i++) mp[i]=0;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]>maxx) maxx=a[i];
        if (a[i]<minn) minn=a[i];
        mp[a[i]]++;
    }
    int ans=0;
    for (ll i=1;i<=n;i++) a[i]=a[i]+a[i-1];
    for (ll i=1;i<=n;i++){
        for (ll j=i+1;j<=n;j++){
            if (a[j]-a[i-1]>maxx) break;
            ans+=mp[a[j]-a[i-1]];
            mp[a[j]-a[i-1]]=0;
        }  
    }
    cout<<ans<<endl;
    
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while (T--) solve();
}