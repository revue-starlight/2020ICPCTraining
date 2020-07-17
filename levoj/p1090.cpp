#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while (cin>>n){
        int k;
        for (int i=1;i<=n;i++){
            cin>>k;
            int ans=0;
            int p;
            for (int j=1;j<=k;j++) cin>>p,ans+=p;
            cout<<ans<<endl<<endl;
        }
    }
    return 0;
}