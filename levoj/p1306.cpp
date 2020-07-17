#include <bits/stdc++.h>
using namespace std;
int n,c;
int main(){
    while (cin>>n>>c){
        int dp[10001];
        memset(dp,0,sizeof(dp));
        int v[101],w[101];
        for (int i=1;i<=n;i++){cin>>v[i]>>w[i];}
        for (int i=1;i<=n;i++){
            for (int j=c;j>=v[i];j--)
            {
                int d;
                d=j/v[i];
                for (int k=1;k<=d;k++)
                if (dp[j]<dp[j-k*v[i]]+k*w[i]) dp[j]=dp[j-k*v[i]]+k*w[i];
            }
        }
        cout<<dp[c]<<endl;
    }
}