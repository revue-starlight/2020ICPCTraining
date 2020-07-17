#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while (cin>>n){
        int a[200];
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++) cin>>a[i];
        int dp1[200],dp2[200];
        memset(dp1,0,sizeof(dp1)); memset(dp2,0,sizeof(dp2));
        for (int i=1;i<=n;i++){
            for (int j=0;j<i;j++)
            if (a[i]>a[j]) dp1[i]=max(dp1[i],dp1[j]+1);
        }
        
        for (int i=n;i>=1;i--){
            for (int j=n+1;j>i;j--)
            if (a[i]>a[j]) dp2[i]=max(dp2[i],dp2[j]+1);
        }
        int ans=0;
        for (int i=1;i<=n;i++) ans=max(dp1[i]+dp2[i]-1,ans);
        cout<<n-ans<<endl;
    }
}