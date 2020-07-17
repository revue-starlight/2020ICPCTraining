#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        long long a,b;
        cin>>a>>b;
        if (a<b) swap(a,b);
        int ans=0;
        while (a>b && a%2==0){
            a/=2;
            ans++;
        }
        if (a==b){
        if (ans%3==0) ans/=3; else ans=ans/3+1;
        cout<<ans<<endl;}
        else {
            cout<<"-1"<<endl;
        }
    }
}