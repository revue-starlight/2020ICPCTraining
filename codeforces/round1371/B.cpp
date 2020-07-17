#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    ll n,r;
    cin>>n>>r;
    if (n>r){
        if (r%2==0)
        cout<<(r+1)*(r/2)<<endl;
        else
        cout<<(r+1)/2*r<<endl;
        return;
    }
    if (n==r){
        if (n%2==0)
        cout<<(r-1)*(r/2)+1<<endl;
        else
        cout<<(r-1)/2*r+1<<endl;
        return;
    }
    if (n%2==0)
    cout<<(n-1)*(n/2)+1<<endl;
    else
    cout<<(n-1)/2*n+1<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--) solve();
}