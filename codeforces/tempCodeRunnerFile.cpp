#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=2e1+10;
const ll INF=1e7;
ll dp[maxn];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        dp[i]=INF;
    }
    dp[k]=0;
    for (int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        int p=min(dp[x]+1,dp[y]);
        int q=min(dp[y]+1,dp[x]);
        dp[x]=p; dp[y]=q;
    }
    for (int i=1;i<=n;i++)
        cout<<dp[i]<<" ";
    return 0;
}