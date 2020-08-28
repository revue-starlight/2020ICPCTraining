#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ans[100005];
inline void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    ll xmin=n/y;
    if (x<xmin || x*y<n) {cout<<"NO"<<endl; return;}
    if (x+y>n+1) {cout<<"NO"<<endl; return;}
    if (x+y==n+1){
        for (int i=1;i<x;i++) ans[i]=i;
        for (int i=x;i<=n;i++) ans[i]=n+x-i; 
        for (int i=1;i<n;i++) cout<<ans[i]<<" ";
        cout<<ans[n]<<endl; return;
    }
    else{
        int k=(n-x)/(y-1);
        for (int i=1;i<=k;i++){
            int p=n-i*y;
            for (int j=1;j<=y;j++){
                ans[p+j]=n-(i-1)*y+1-j;
            }
        }
        if ((n-x)%(y-1)) {
            int f_p=n-y*k;
            int tmp=(n-x)%(y-1)+1;
            int n_x=f_p-tmp;
            for (int i=n_x;i<f_p;i++)
                ans[i+1]=n_x+f_p-i;
                for (int i=1;i<=n_x;i++) ans[i]=i;
        }
        else{
            for (int i=1;i<=n-y*k;i++) ans[i]=i;
        }
        cout<<"YES"<<endl;
        for (int i=1;i<n;i++)  cout<<ans[i]<<" ";
        cout<<ans[n]<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    ll T;
    cin>>T;
    while (T--) solve();
}