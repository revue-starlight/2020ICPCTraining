#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        int n,k;
        cin>>n>>k;
        int ans=INT_MAX;
        for (int i=1;i<=sqrt(n);i++){
            if (n%i==0) {
                if (i<=k && (n/i)<=k)
                ans=min(ans,min(n/i,i));
                else
                if (i<=k){
                ans=min(ans,n/i);}
                else break;
            }
        }
        cout<<ans<<endl;
    }
}