#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1004][1004];
#define mod 10000
int main() {
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=n;i++) dp[1][i]=n-i+1;

    for(int i = 2; i <= m; i++)//i为长度。
        if(i%2)//奇数的话
            for(int j=n;j>=1;j--) //前i个偶数中最大数比j小的+前i个数字最后一个比j大的所有方案。（最后一个数直接减。
                dp[i][j]=(dp[i-1][j-1]+dp[i][j+1])%mod;
        else for(int j=1;j<=n;j++)
                dp[i][j]=(dp[i-1][j+1]+dp[i][j-1])%mod;

    if (m%2) cout<<dp[m][1]; else cout<<dp[m][n];
}