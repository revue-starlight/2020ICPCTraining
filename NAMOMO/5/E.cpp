#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
    double ans;
    ans=0;
    int l,r;
    cin>>l>>r;
    for (int i=l;i<=r;i++){
        ans+=(1.0/i);
    }
    cout<<setprecision(15)<<(r-l+1)/ans<<endl;
    }
}