#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll T;
int main(){
    cin>>T;
    while (T--){
        ll n,m;
        cin>>n>>m;
        ll ans;
        if ((n-2*m)<=0)  
        ans=((n-1)+(1))*(n-1)/2;
        else
        ans=((n-1)+(n-2*m))*(m);
        cout<<ans<<endl;
    }
}