#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while (cin>>n){
        int a[1001][1001];
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=i;j++){
                cin>>a[i][j];
            }
        for (int i=n-1;i>=1;i--)
            for (int j=1;j<=i;j++){
                a[i][j]=a[i][j]+max(a[i+1][j],a[i+1][j+1]);
            }
        cout<<a[1][1]<<endl;
    }
}