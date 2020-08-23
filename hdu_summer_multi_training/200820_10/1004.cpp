#include <bits/stdc++.h>
using namespace std;
#define N 5050
const int mod=1e9+7;
int dp[N][N],a[N],dp_sum[N][N];
inline int add(int a,int b) {return (a+b)%mod;}
inline int minu(int a,int b) {if (a<b) return a+mod-b; else return a-b;}
inline void solve(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) dp[i][j]=dp_sum[i][j]=0;
    for (int i=1;i<n;i++) 
        {cin>>a[i];}
    dp[1][1]=dp_sum[1][1]=1;
    for (int i=1;i<n;i++){
        if (a[i]==0){
            for (int j=1;j<=i+1;j++){
                dp[i+1][j]=dp_sum[i][j-1];//dp[i][1]+...+dp[i][j-1];
            }
        }
        else{
            for (int j=1;j<=i;j++){
                dp[i+1][j]=minu(dp_sum[i][i],dp_sum[i][j-1]);//dp[i][j]+...+dp[i][i];
            }
        }
        for (int j=1;j<=i+1;j++)
            dp_sum[i+1][j]=add(dp_sum[i+1][j-1],dp[i+1][j]);
    }
    cout<<dp_sum[n][n]<<"\n";
}
int main(){
    //freopen("1004.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while (T--) solve();
} 