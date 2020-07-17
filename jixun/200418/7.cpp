#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    long long ans=0;
    for (int i=1;i<=n;i++){
        int tempans;
        tempans=i;
        for (int j=2;j<=m-1;j++){
            tempans*=i;
        }
        ans+=tempans;
        cout<<"i="<<i<<" "<<tempans<<endl;
    }
    cout<<ans;
}