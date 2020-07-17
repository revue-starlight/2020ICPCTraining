#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    ll a,b,n,m;
    cin>>a>>b>>n>>m;
    if (m<=min(a,b) && n<=(a+b)-m) cout<<"Yes"<<endl; else cout<<"No"<<endl;
}
int main(){
    ll t;
    cin>>t;
    while (t--) solve();
}