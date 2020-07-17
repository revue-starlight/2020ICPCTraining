#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t[1001][1001];
int main(){
    int n;
   // freopen("data.in","r",stdin);
//	freopen("data2.out","w",stdout);
    while (cin>>n){
        for (int i=1;i<=n;i++)
         for (int j=1;j<=i;j++)
            cin>>t[i][j];
        for (int i=n-1;i>=1;i--)
        {
            for (int j=1;j<=i;j++){
                t[i][j]=t[i][j]+min(t[i+1][j],t[i+1][j+1]);
            }
        }
        cout<<t[1][1]<<endl;
    }
}