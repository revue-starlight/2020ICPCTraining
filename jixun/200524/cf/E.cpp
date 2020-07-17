#include <bits/stdc++.h>
using namespace std;
int a[51][51];
int b[51][51];
int main(){
    int t;
    cin>>t;
    int n;
    while (t--){
        memset(b,0,sizeof(b));
        cin>>n;
        getchar();
        for (int i=1;i<=n;i++)
        {              
            for (int j=1;j<=n;j++){
                char ch=getchar();
                a[i][j]=ch-'0';
            }
            getchar();
        }
        for (int i=1;i<=n+1;i++) b[n+1][i]=1;
        for (int i=1;i<=n;i++) b[i][n+1]=1;

        for (int step=n;step>=1;step--){
            for (int i=n;i>=1;i--) if ((b[step+1][i]==1 || b[step][i+1]==1) && a[step][i]==1) b[step][i]=1;
            for (int i=n;i>=1;i--) if ((b[i][step+1]==1 || b[i+1][step]==1) && a[i][step]==1) b[i][step]=1;
        }
        bool bo=false;
        for (int i=1;i<=n;i++)
         {for (int j=1;j<=n;j++){
             if (a[i][j]!=b[i][j]) {bo=true;}
         }
        }
        if (bo) cout<<"NO"<<endl; else cout<<"YES"<<endl;
    }
}