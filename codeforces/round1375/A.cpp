#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[400][400];
int main(){
    int T;
    cin>>T;
    while (T--){
        bool bo=true;
        cin>>n>>m;
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (i==1 && j==1 || i==1 && j==m || i==n && j==1 || i==n &&j==m){
                    if (a[i][j]>2) {bo=false; break;}
                }
                else if (i==1 || i==n || j==1 || j==m){
                    if (a[i][j]>3) {bo=false; break;}
                }
                else {
                    if (a[i][j]>4) {bo=false; break;}
                }
            }
        if (!bo){
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
            for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (i==1 && j==1 || i==1 && j==m || i==n && j==1 || i==n &&j==m){
                    cout<<2<<" ";
                }
                else if (i==1 || i==n || j==1 || j==m){
                    cout<<"3 ";
                }
                else {
                    cout<<"4 ";
                }
                if (j==m)cout<<endl;
            }
        }
    }
}