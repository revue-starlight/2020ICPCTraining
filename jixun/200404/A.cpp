#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[101][101];
    int t;
    cin>>t;
    for (int kaze=1;kaze<=t;kaze++){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++)
                cin>>a[i][j];
        }
        int k=0;
        for (int i=1;i<=n;i++) k+=a[i][i];
        int check[103];
        int r=0; int c=0;
        for (int i=1;i<=n;i++){
            memset(check,0,sizeof(check));
            for (int j=1;j<=n;j++) {
                if (check[a[i][j]]>0) {r++; break;} 
                else check[a[i][j]]++;
            }
        }
        for (int j=1;j<=n;j++){
            memset(check,0,sizeof(check));
            for (int i=1;i<=n;i++){
                if (check[a[i][j]]>0) {c++; break;}
                else check[a[i][j]]++;
            }
        }

        cout<<"Case #"<<kaze<<": "<<k<<" "<<r<<" "<<c<<endl;
    }
    return 0;
}