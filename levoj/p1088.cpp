#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a,ans,t;
    while (cin>>n){
        ans=0;
        for (int i=1;i<=n;i++) cin>>a,ans+=a;
        cout<<ans<<endl;
        }
}