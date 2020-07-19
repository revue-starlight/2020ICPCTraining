#include <bits/stdc++.h>
using namespace std;
int x[105],y[105];
int main(){
    int ans=0;
    int T;
    int n,m;
    cin>>T;
    while (T--){
    ans=INT_MAX;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    for (int i=1;i<=n;i++){
        if (m%x[i]==0){
            ans=min(ans,(m/x[i])*y[i]);
        }
        else ans=min(ans,(m/x[i]+1)*y[i]);
    }
    cout<<ans<<endl;
}
}