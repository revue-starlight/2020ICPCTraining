#include <bits/stdc++.h>
using namespace std;
#define LL long long
int n=4;
int rbq[5][5];
int a[5][5];
int b[5][5];
const int mod=10000;
int main(){
    int T;
    cin>>T;
    while (T--){
        int n,m;
        cin>>n>>m;
        int k=min(m,1000);
        for (int i=1;i<=k;i++){
            for (int xx=1;xx<=n;xx++)  for (int yy=1;yy<=n;yy++) rbq[xx][yy]=0;
            for (int xx=1;xx<=n;xx++)
                for (int yy=1;yy<=n;yy++)
                for (int kk=1;kk<=n;kk++)
                rbq[xx][yy]+=a[xx][kk]*b[kk][yy];
            
            for (int ii=1;ii<=n;ii++){
                for (int j=1;j<=n;j++) cout<<rbq[ii][j]<<" ";
                cout<<endl;
            }
        }
    }
}