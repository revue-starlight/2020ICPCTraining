#include <bits/stdc++.h>
using namespace std;
struct node{
    int t,h,b;
};
const int maxn=1001;
node a[maxn];
int dp[10001];
int main(){
    int n,t;
    cin>>n>>t;
    for (int i=1;i<=n;i++){
        cin>>a[i].t>>a[i].b>>a[i].h;
    }
    for (int i=1;i<=n;i++){
        for (int j=t;j>=a[i].t;j--){
            if (a[i].h+dp[j-a[i].t]>=dp[j]) dp[j]=a[i].h+dp[j-a[i].t];
        }
    }
    cout<<dp[t]<<endl;
    
}