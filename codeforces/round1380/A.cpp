#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    int a[1001];
    memset(a,0,sizeof(a));
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=1;
    while (t<n && a[t+1]<a[t]) t++;
    if (t==n) {cout<<"NO"<<endl; return;} 
    while (t<n && a[t+1]>a[t]) t++;
    if (t==n) {cout<<"NO"<<endl; return;}
    cout<<"YES"<<endl;
    cout<<t-1<<" "<<t<<" "<<t+1<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--) solve();
}