#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while (n--){
        int a,b;
        cin>>a>>b;
        int ans=INT_MAX;
        ans=min(ans,max(a+a,b));
        ans=min(ans,max(a+b,max(a,b)));
        ans=min(ans,max(b+b,a));
        ans=ans*ans;
        cout<<ans<<endl;
    }
}