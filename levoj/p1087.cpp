#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a,ans;
    while (cin>>n){
        if (n==0) return 0;
        ans=0;
        for (int i=1;i<=n;i++) cin>>a,ans+=a;
        cout<<ans<<endl;
    }
}